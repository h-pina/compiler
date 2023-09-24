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

//Token Objects pre created
namespace PreDefinedTokens{
    const Token singCharSymbols[] = {
        Token(TokenType::tk_minus , "-"),
        Token(TokenType::tk_plus,"+"),
        Token(TokenType::tk_greaterThan,">"),
        Token(TokenType::tk_lessThan,"<"),
        Token(TokenType::tk_divBy,"/"),
        Token(TokenType::tk_mulBy,"*"),
        Token(TokenType::tk_factor,"!"),
        Token(TokenType::tk_comma,","),
        Token(TokenType::tk_semicolon,";"),
        Token(TokenType::tk_openBracket,"{"),
        Token(TokenType::tk_closedBracket,"}"),
        Token(TokenType::tk_openPar,"("),
        Token(TokenType::tk_closePar,")"),
        Token(TokenType::tk_assign,"=")
    };

    const Token doubleCharSymbols[] = {
        Token(TokenType::tk_greaterEqualThan,">="),
        Token(TokenType::tk_lessEqualThan,"<="),
        Token(TokenType::tk_and,"&&"),
        Token(TokenType::tk_notEqual,"!="),
        Token(TokenType::tk_equal,"=="),
        Token(TokenType::tk_or,"||")
    };

    const Token keywords[] = {
        Token(TokenType::tk_stringType,"string"),
        Token(TokenType::tk_floatType,"float"),
        Token(TokenType::tk_class, "class"),
        Token(TokenType::tk_if,"if"),
        Token(TokenType::tk_else,"else"),
        Token(TokenType::tk_do,"do"),
        Token(TokenType::tk_intType,"int"),
        Token(TokenType::tk_while,"while"),
        Token(TokenType::tk_read,"read"),
        Token(TokenType::tk_write,"write")
    };
}