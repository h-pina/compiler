#include "Token.h"

Token::Token(TokenType tkt, std::string lex){
    tkType = tkt;
    lexeme = lex;
}

Token::Token(){
    tkType = TokenType::tk_empty;
    lexeme = "";
}