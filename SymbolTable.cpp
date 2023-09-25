#include "SymbolTable.h"
#include <iostream>


SymbolTable::SymbolTable(){
    for(Token t : PreDefinedTokens::keywords){
        insert(t.lexeme, t);
    }
}

bool  SymbolTable::insert(std::string key, Token token){
    return symbolTable.insert({key, token}).second;
}

Token SymbolTable::get(std::string key){
    if (contains(key)){
        auto search = symbolTable.find(key);
        return search->second;
    }
    else{
        return Token();
    }
}

bool SymbolTable::contains(std::string key){
    return symbolTable.find(key) != symbolTable.end();
}

void SymbolTable::printTable(){
    std::cout << "Symbols in symbolTable: " << std::endl;
    for(auto iter = symbolTable.begin(); iter != symbolTable.end(); iter++){
        std::cout << "  " <<iter->first << ", ";
    }
    std::cout << std::endl << std::endl;

}