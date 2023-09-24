
#include <fstream>
#include "Tokenizer.h"
#include "utils.h"


Tokenizer::Tokenizer(){}
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

//TODO: Resolve problem with <= and !=, for example 
Token Tokenizer::checkForSymbol(char c ){
    for(Token token : PreDefinedTokens::symbols){
        if(token.token[0] == c){
            return token;
        }
    }
    return Token();
}

//Also fix this I have no idea whats going on
Token Tokenizer::checkForKeyword(std::string s ){
    for(Token t : PreDefinedTokens::keywords){
        
        Utils::debug(t.token);
        Utils::debug(s);
        Utils::debug("");
        if(t.token.compare(s) == 0){
            Utils::debug("-----------------------------------");
            return t;
        }
    }
    return Token();
}

void Tokenizer::storeCodeIntoBuffer(std::string filename){
    std::ifstream f(filename);
    Tokenizer::code << f.rdbuf();
}

Token Tokenizer::getNextToken(){
    char c;
    Tokenizer::code.get(c);
    std::string tokenString = "";
    TokenType tokenType;

    if(code.eof()){
        return Token(TokenType::tk_eof, "EOF");
    }
    
    while(c == ' '){
        code.get(c);
    }
    
    if(isNonZero(c)){
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
        code.get(c); // dispose first "
        while(isAllowedAsciiCharacter(c)){
            tokenString += c;
            code.get(c);
        }
        if (c == '\n') throw std::runtime_error("error");

        tokenType = TokenType::tk_literal;
        return Token(tokenType,tokenString);
    }else{
        return checkForSymbol(c);
    }
    throw std::runtime_error("error");
}