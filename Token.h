#include <string>
#include "TokenTypes.h"

class Token
{
public:
    TokenType tkType;
    std::string token;
    Token(TokenType tkType, std::string token);
    Token();
};


// const Token operators[14] = {
//     Token(TokenType::tk_minus , "-"),
//     // Token(TokenType::tk_plus,"+"),
//     // Token(TokenType::tk_greaterThan,">"),
//     // Token(TokenType::tk_greaterEqualThan,">="),
//     // Token(TokenType::tk_lessThan,"<"),
//     // Token(TokenType::tk_lessEqualThan,"<="),
//     // Token(TokenType::tk_and,"&&"),
//     // Token(TokenType::tk_notEqual,"!="),
//     // Token(TokenType::tk_equal,"=="),
//     // Token(TokenType::tk_or,"||"),
//     // Token(TokenType::tk_divBy,"/"),
//     // Token(TokenType::tk_mulBy,"*"),
//     // Token(TokenType::tk_factor,"!")
// };


// const std::string types[3] = {"int","string","float"};
// const std::string symbols[7] = {",",";","{","}","(",")","="};
// const std::string keywords[7] = {"class", "if", "else", "do", "while", "read", "write"};