#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <string>
#include "Parser.h"


//This is a simple test file. It will print out the token division of the file named testfile.txt
int main(){
    //freopen("output.txt","w",stdout); //This line can be used  pipe the output of the lexer to the file output.txt
    std::string filename = "testfile.txt"; //You can change the tested file by changing this variable
    Lexer lexer(filename); //Lexer initialization 
    Parser parser(lexer, lexer.symbolTable);
    AST ast = parser.buildAst();
    int i = 0;
}