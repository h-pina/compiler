#include "Token.h"

Token::Token(TokenType tkt, std::string tokenStr){
    tkType = tkt;
    token = tokenStr;
}

Token::Token(){
    tkType = TokenType::tk_empty;
    token = "";
}