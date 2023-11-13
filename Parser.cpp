#include "Parser.h"
#include <iostream>

Parser::Parser(Lexer &lex, SymbolTable &sb)
    : lexer(&lex), symbolTable(&sb){}

AST Parser::buildAst(){
    program();
    return ast;
}
void Parser::program(){
    Token tk;
    int currentNodeIndex = ast.newNode(tk, -1);
    parse(TokenType::tk_class, currentNodeIndex);
    parse(TokenType::tk_identifier, currentNodeIndex);
    declList(currentNodeIndex); // TODO: Make it loop
    body(currentNodeIndex);
}

void Parser::parse(TokenType tk, int parentNodeIndex){
    Token nextToken = getNextToken();
    
    if(nextToken.tkType != tk)  throwError("[Error] Wrong token type found while parsing token " + nextToken.lexeme);
    ast.newNode(nextToken, parentNodeIndex);
}

//What the fuck is the difference between this and the other one
void Parser::parse(Token tk, int parentNodeIndex){
    ast.newNode(tk, parentNodeIndex);
}

//TODO: Improve Error generation
void Parser::throwError(std::string errormsg){
    throw std::runtime_error(errormsg);
}

Token Parser::getNextToken(){
    if(buffer.empty()) return lexer->getNextToken();
    else{ //TODO: Remove last element from buffer
        Token tk = buffer.back();
    }
}

//TODO: Make it recursive
void Parser::declList(int parentNodeIndex){
    Token tk; 
    int currentNodeIndex = ast.newNode(tk, parentNodeIndex); 
    decl(currentNodeIndex);
    parse(TokenType::tk_semicolon,currentNodeIndex);
    //TODO: Generate logic for repeating declarations
}


void Parser::decl(int parentNodeIndex){
    Token tk; 
    int currentNodeIndex = ast.newNode(tk, parentNodeIndex);
    type(currentNodeIndex);
    identList(currentNodeIndex);
}

void Parser::identList(int parentNodeIndex){
    Token tk; 
    int currentNodeIndex = ast.newNode(tk, parentNodeIndex);
    parse(TokenType::tk_identifier, currentNodeIndex);
    tk = lexer->getNextToken();
    while(tk.tkType == TokenType::tk_comma){
        parse(tk,currentNodeIndex);
        parse(TokenType::tk_identifier,currentNodeIndex);
        tk = lexer->getNextToken(); //todo: add a storage to store this variable when while loop ends, and create a fuction to check if buffer is full
    }
}

void Parser::type(int parentNodeIndex){
    Token nextToken = lexer->getNextToken();
    if (nextToken.tkType == TokenType::tk_intType || nextToken.tkType == TokenType::tk_stringType || nextToken.tkType == TokenType::tk_floatType){
        parse(nextToken,parentNodeIndex);
    }
    else{
        throwError(nextToken.lexeme + " is an invalid type");
    }
}

void Parser::body(int parentNodeIndex){
    Token tk; 
    int currentNodeIndex = ast.newNode(tk, parentNodeIndex);
    parse(TokenType::tk_openBracket,currentNodeIndex);
    stmtList(currentNodeIndex);
    parse(TokenType::tk_closedBracket,currentNodeIndex);
}

void Parser::stmtList(int parentNodeIndex){
    Token tk; 
    int currentNodeIndex = ast.newNode(tk, parentNodeIndex);   
    stmt(currentNodeIndex);
}

void Parser::stmt(int currentNodeINdex){
    Token nextToken = lexer->getNextToken();
    switch(nextToken.tkType){
        case TokenType::tk_if:
            break;
        case TokenType::tk_do:
            break;
        case TokenType::tk_while:
            break;
        case TokenType::tk_read:
            break;
        case TokenType::tk_write:
            break;
        case TokenType::tk_identifier:
            break;
        default:
            throwError(nextToken.lexeme + "does not start any statemnte insidde the defined grammar");
    }
}
void Parser::assignStmt(int currentNodeINdex){}
void Parser::ifStmt(int currentNodeINdex){}
void Parser::condition(int currentNodeINdex){}
void Parser::doStmt(int currentNodeINdex){}
void Parser::doSuffix(int currentNodeINdex){}
void Parser::readStmt(int currentNodeINdex){}
void Parser::writeStmt(int currentNodeINdex){}
void Parser::writable(int currentNodeINdex){}
void Parser::expression(int currentNodeINdex){}
void Parser::term(int currentNodeINdex){}
void Parser::factorA(int currentNodeINdex){}
void Parser::factor(int currentNodeINdex){}
void Parser::relop(int currentNodeINdex){}
void Parser::addop(int currentNodeINdex){}
void Parser::mulop(int currentNodeINdex){}