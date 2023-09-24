#include "Token.h"
#include <sstream>
#include <string>


class Tokenizer
{
private:
    std::string filename;
    std::stringstream code;

public:
    Tokenizer();
    bool isLetter(char c );
    bool isDigit(char c);
    bool isNonZero(char c);
    bool isAllowedAsciiCharacter(char c);
    void removeIgnoredChars(char c);
    Token checkForSymbol(char c ); 
    Token checkForKeyword(std::string c); 
    Token getNextToken();
    void storeCodeIntoBuffer(std::string filename);
};
