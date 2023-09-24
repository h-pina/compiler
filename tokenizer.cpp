
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

// bool Tokenizer::isSpecial(std::string s){
//     for (int i = 0; i<arraySize; i++){
//         if (s == array[i]){return true;}
//     }
//     return false;
// }

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
        Utils::debug("w");
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
    }
    else {
        
    }
    
    throw std::runtime_error("error");
}