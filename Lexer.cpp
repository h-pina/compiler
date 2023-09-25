#include <fstream>
#include "Lexer.h"

Lexer::Lexer(std::string file){
    filename = file;
    storeCodeIntoBuffer(filename);
    lineCount = 1;
}

void Lexer::storeCodeIntoBuffer(std::string filename){
    std::ifstream f(filename);
    Lexer::code << f.rdbuf();
}

bool Lexer::isLetter(char c ){
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool Lexer::isDigit(char c){
    return (c>=48 && c<=57);
}

bool Lexer::isNonZero(char c){
    return (c>48 && c<=57);
}

bool Lexer::isAllowedAsciiCharacter(char c){
    return (c != '\"' && c != '\n');
}

Token Lexer::checkForSymbol(char c){
    std::string symbol = "";
    Token finalToken = Token();
    symbol += c;
    
    //Check for single character symbols
    for(Token token : PreDefinedTokens::singCharSymbols){ 
        if(token.lexeme == symbol){
            finalToken = token;
        }
    }
    
    //check for double character symbols
    code.get(c);
    if(!code.eof()){
        symbol += c; //Build potential double character symbols
        for(Token token : PreDefinedTokens::doubleCharSymbols){ 
            if(token.lexeme == symbol){
                finalToken =  token;
                return finalToken;
            }
        }
        code.putback(c); //if no symbol is found, return the last character to code buffer
    }
    return finalToken;
}

Token Lexer::checkForKeyword(std::string s ){
    for(Token t : PreDefinedTokens::keywords){
        if(t.lexeme == s){
            return t;
        }
    }
    return Token(); //if no keyword found, return default empty token
}

void Lexer::skipIgnoredChars(char &c){
    while(c == ' ' || c == '\n' || c == '\t' || c == '\r'){  //remove whitespaces, tabs and newlineas
        if(c == '\n') { lineCount++; }
        code.get(c); 
    }
    if(c == '/'){ //check for comments
        code.get(c);
        if(c == '/'){ //single line comment
            while(c != '\n') {code.get(c);}
            lineCount++;
            code.get(c);
        }
        else if (c ==  '*'){ //multi line comment
            bool isEndOfComment = false;
            while(!isEndOfComment) {
                if(c == '\n') { lineCount++; }
                code.get(c);
                if(c == '*'){
                    code.get(c);
                    if(c == '/') {isEndOfComment = true;}
                    else{code.putback(c);}
                }
               
            }
            code.get(c);
        }else{
            code.putback(c);
            c = '/';
        }
    }

    while(c == ' ' || c == '\n' || c == '\t' || c == '\r'){  //remove whitespaces, tabs and newlineas
        if(c == '\n') { lineCount++; }
        code.get(c); 
    }
}

Token Lexer::getNextToken(){
    char c;
    Lexer::code.get(c);
    std::string tokenString = "";
    TokenType tokenType;

    skipIgnoredChars(c);

    if(code.eof()){ //check if file ended
        return Token(TokenType::tk_eof, "EOF");
    }

    if(isNonZero(c)){ //check for real and integer numbers
        
        tokenString += c;
        bool haveDecimalPoint = false;
        code.get(c);

        while(isDigit(c) || c == '.' ){
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
    else if(c == '0'){ //edge case: number = 0
        return Token(TokenType::tk_int, "0");
    }
    else if(isLetter(c)){ //check for identifiers
        tokenString += c;
        code.get(c);
        
        while(isLetter(c) || isDigit(c) || c == '_'){
            tokenString += c;
            code.get(c);
        }
        code.putback(c);
        
        Token keywordCheck = checkForKeyword(tokenString);
        if(keywordCheck.tkType != TokenType::tk_empty){ //if any keyword is found, return it
            return keywordCheck; 
        }
        
        tokenType = TokenType::tk_identifier; // if no keyword found, treat token as a normal idenftifier
        Token t = Token(tokenType,tokenString);
        
        
        symbolTable.insert(t.lexeme, t); //add  identifier to symbol table
        return t;

    }else if(c == '\"'){ //check for string
        
        code.get(c); // dispose first double-quotes
        while(isAllowedAsciiCharacter(c)){
            tokenString += c;
            code.get(c);
        }
        if (c == '\n') { throw std::runtime_error(std::string("Lexer found a problem recognizing the tokens at line ") + std::to_string(Lexer::lineCount)); } 

        tokenType = TokenType::tk_literal;
        return Token(tokenType,tokenString);
    }else{ //if no other tokens identified, check for symbols
        Token symbolCheck = checkForSymbol(c);
        if(symbolCheck.tkType != TokenType::tk_empty){
            return symbolCheck;
        }
    }
    throw std::runtime_error(std::string("Lexer found a problem recognizing the tokens at line ") + std::to_string(Lexer::lineCount)); //if nothing is found, return error
}

void Lexer::printSymbolTable(){ //This works as a wrapper to symbolTable`s printTable function
    symbolTable.printTable();
}