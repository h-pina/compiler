#include "SymbolTable.h"
#include <sstream>
#include <string>


class Lexer
{
private:
    std::string filename; 
    std::stringstream code; //stores the code as a single string

    void storeCodeIntoBuffer(std::string filename);

public:
    SymbolTable symbolTable;
    int lineCount; //line count is freely acessible. 
    
    Lexer(std::string file); // Default constructor: fills code buffer and initializes variables
    
    bool isLetter(char c );
    bool isDigit(char c);
    bool isNonZero(char c);
    bool isAllowedAsciiCharacter(char c); 
    
    void skipIgnoredChars(char &c); //Ignores whitespaces, tabs, newlines, and comments 
    Token checkForSymbol(char c );  //Check for special symnbols tokens  ('}' for)
    Token checkForKeyword(std::string c); //Check for special symnbols tokens  ('}' for)
    
    Token getNextToken(); //retrieve the next token from 'code' buffer
    void printSymbolTable(); //Wrapper around SymbolTable function
};
