#include <stdio.h>
#include <iostream>
#include <string>
#include "Tokenizer.h"

int main(){
    std::string tt[] = {"tk_class","tk_if","tk_else","tk_do","tk_while","tk_read","tk_write","tk_intType","tk_stringType","tk_floatType","tk_int","tk_real","tk_literal","tk_identifier","tk_comma","tk_semicolon","tk_openBracket","tk_closedBracket","tk_openPar","tk_closePar","tk_assign","tk_minus","tk_plus","tk_factor","tk_lessEqualThan","tk_lessThan","tk_greaterThan","tk_greaterEqualThan","tk_notEqual","tk_equal","tk_or","tk_and","tk_divBy","tk_mulBy","tk_eof","tk_empty"};
    Tokenizer tokenizer = Tokenizer();
    tokenizer.storeCodeIntoBuffer("testfile.txt");
    Token tk;
    while(tk.token != "EOF"){
        tk = tokenizer.getNextToken();
        std::cout << "[Main] Token: " << tk.token << "| Type: " << tt[static_cast<int>(tk.tkType)] << std::endl;
    }

}