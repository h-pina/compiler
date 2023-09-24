
#include <fstream>
#include "Tokenizer.h"
#include "utils.h"


Tokenizer::Tokenizer(){}
void Tokenizer::storeCodeIntoBuffer(std::string filename){
    std::ifstream f(filename);
    Tokenizer::code << f.rdbuf();
}

bool Tokenizer::isLetter(char c ){
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
bool Tokenizer::isDigit(char c){
    return (c>=48 && c<=57);
}
bool Tokenizer::isNonZero(char c){
    return (c>48 && c<=57);
}
bool Tokenizer::isAllowedAsciiCharacter(char c){
    return (c != '\"' && c != '\n');
}
Token Tokenizer::checkForSymbol(char c){
    std::string symbol = "";
    Token finalToken = Token();
    symbol += c;
    
    //Check for single character symbols
    for(Token token : PreDefinedTokens::singCharSymbols){ 
        if(token.token == symbol){
            finalToken = token;
        }
    }
    code.get(c);
    if(!code.eof()){
        symbol += c;
        for(Token token : PreDefinedTokens::doubleCharSymbols){ 
            if(token.token == symbol){
                finalToken =  token;
                return finalToken;
            }
        }
        code.putback(c);
    }
    return finalToken;
}
Token Tokenizer::checkForKeyword(std::string s ){
    for(Token t : PreDefinedTokens::keywords){
        if(t.token == s){
            return t;
        }
    }
    return Token();
}

Token Tokenizer::getNextToken(){
    char c;
    Tokenizer::code.get(c);
    std::string tokenString = "";
    TokenType tokenType;
    //std::cout << "Character Captured: " << c << std::endl;


    if(code.eof()){
        Utils::debug("End Of FIle Encountered");
        return Token(TokenType::tk_eof, "EOF");
    }
    
    while(c == ' ' || c == '\n'){
        Utils::debug("Found whitespace or newline");
        code.get(c);
    }
    
    if(isNonZero(c)){
        Utils::debug("Found Number");
        tokenString += c;
        bool haveDecimalPoint = false;
        code.get(c);

        while(isDigit(c) || c == '.'){
            if (c == '.'){
                if(!haveDecimalPoint){ haveDecimalPoint = true; }
                else throw std::runtime_error("error");
            }
            tokenString += c;
            code.get(c);
        }
        code.putback(c);
        tokenType = haveDecimalPoint ? TokenType::tk_real : TokenType::tk_int;
        return Token(tokenType,tokenString);
    }
    else if(isLetter(c)){
        Utils::debug("Found Letter");
        tokenString += c;
        code.get(c);
        while(isLetter(c) || isDigit(c) || c == '_'){
            tokenString += c;
            code.get(c);
        }
        code.putback(c);
        Token keywordCheck = checkForKeyword(tokenString);
        if(keywordCheck.tkType != TokenType::tk_empty){
            return keywordCheck;
        }
        tokenType = TokenType::tk_identifier;
        return Token(tokenType,tokenString);

    }else if(c == '\"'){
        Utils::debug("Found String");
        code.get(c); // dispose first "
        while(isAllowedAsciiCharacter(c)){
            tokenString += c;
            code.get(c);
        }
        if (c == '\n') throw std::runtime_error("error");

        tokenType = TokenType::tk_literal;
        return Token(tokenType,tokenString);
    }else{
        Utils::debug("Nothing Found, checking for special symbols");
        Token symbolCheck = checkForSymbol(c);
        if(symbolCheck.tkType != TokenType::tk_empty){
            return symbolCheck;
        }
    }
    throw std::runtime_error("error");
}