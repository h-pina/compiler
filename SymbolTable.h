#include "Token.h"
#include <string>
#include <unordered_map>

class SymbolTable
{
private:
    std::unordered_map<std::string, Token> symbolTable;
public:
    SymbolTable();
    bool insert(std::string key, Token token);
    bool contains(std::string key);
    Token get(std::string key);
    void printTable();
};