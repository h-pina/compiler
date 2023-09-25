#include <stdio.h>
#include <iostream>
#include <string>
#include "Lexer.h"

//This is a simple test file. It will print out the token division of the file named testfile.txt
int main(){
    std::string filename = "testfile.txt"; //You can change the tested file by changing this variable

    //This array is used for printing the token types of each type. Since the TokenTypes structure is a enum, it serves as an index
    static const std::string tokenTypesToString[] = {"tk_class","tk_if","tk_else","tk_do","tk_while","tk_read","tk_write","tk_intType","tk_stringType",
    "tk_floatType","tk_int","tk_real","tk_literal","tk_identifier","tk_comma","tk_semicolon","tk_openBracket","tk_closedBracket","tk_openPar",
    "tk_closePar","tk_assign","tk_minus","tk_plus","tk_factor","tk_lessEqualThan","tk_lessThan","tk_greaterThan","tk_greaterEqualThan","tk_notEqual",
    "tk_equal","tk_or","tk_and","tk_divBy","tk_mulBy","tk_eof","tk_empty"};
    
    
    Lexer lexer(filename); //Lexer initialization 
    Token tk; //creation of a token variable for storing each of the tokens found

    while(tk.lexeme != "EOF"){
        tk = lexer.getNextToken();
        std::cout << "Lexeme: " << tk.lexeme << " | TokenType: " << tokenTypesToString[static_cast<int>(tk.tkType)] << std::endl;
    }
    
    std::cout << "File LineCount: " << lexer.lineCount << std::endl;
    
    lexer.printSymbolTable(); 

}