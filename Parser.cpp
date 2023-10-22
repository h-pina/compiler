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
    astNode* currentNode = ast.newNode(tk,nullptr);
    parse(TokenType::tk_class, currentNode);
    parse(TokenType::tk_identifier, currentNode);
    declList(currentNode);// TODO: Can be more dcl-lists. Change lateri
    body(currentNode);
}

void Parser::parse(TokenType tk, astNode* parentNode){
    Token nextToken = lexer->getNextToken();
    
    if(nextToken.tkType != tk) throw std::runtime_error("tkError");
    ast.newNode(nextToken, parentNode);
}
void Parser::declList(astNode* parentNode){return;}
void Parser::decl(astNode* parentNode){}
void Parser::identList(astNode* parentNode){}
void Parser::type(astNode* parentNode){}
void Parser::body(astNode* parentNode){return;}
void Parser::stmtList(astNode* parentNode){}
void Parser::stmt(astNode* parentNode){}
void Parser::assignStmt(astNode* parentNode){}
void Parser::ifStmt(astNode* parentNode){}
void Parser::condition(astNode* parentNode){}
void Parser::doStmt(astNode* parentNode){}
void Parser::doSuffix(astNode* parentNode){}
void Parser::readStmt(astNode* parentNode){}
void Parser::writeStmt(astNode* parentNode){}
void Parser::writable(astNode* parentNode){}
void Parser::expression(astNode* parentNode){}
void Parser::term(astNode* parentNode){}
void Parser::factorA(astNode* parentNode){}
void Parser::factor(astNode* parentNode){}
void Parser::relop(astNode* parentNode){}
void Parser::addop(astNode* parentNode){}
void Parser::mulop(astNode* parentNode){}