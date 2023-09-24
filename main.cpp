#include <stdio.h>
#include <iostream>
#include <string>
#include "Tokenizer.h"

int main(){
    std::string tt[] = {"tk_class","tk_intType","tk_stringType","tk_floatType","tk_if","tk_else","tk_do","tk_while","tk_read","tk_write","tk_int","tk_real","tk_literal","tk_identifier","tk_comma","tk_semicolon","tk_openBracket","tk_closedBracket","tk_openPar","tk_closePar","tk_assignment","tk_minus","tk_more","tk_factor","tk_lessEqual","tk_lessThan","tk_greaterThan","tk_greaterEqualThan","tk_notEqual","tk_equal","tk_or","tk_and","tk_divBy","tk_mulBy","tk_eof"};
    Tokenizer tokenizer = Tokenizer();
    tokenizer.storeCodeIntoBuffer("testfile.txt");
    Token tk;
    while(tk.token != "EOF"){
        tk = tokenizer.getNextToken();
        std::cout << "[Main] Token: " << tk.token << "| Type: " << tt[static_cast<int>(tk.tkType)] << std::endl;
    }

}