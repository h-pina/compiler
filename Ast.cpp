#include "Ast.h"
#include <iostream>


astNode* AST::newNode(Token tk, astNode &parent ){
    std::cout << "[I] Adding " << tk.lexeme << " to tree" << "\n";
    astNode newNode = {tk, parent};
    if(nodes.size() == 0){
        std::cout<<"Enter" << std::endl;
        nodes.push_back(newNode);
        root = nodes.back(); 
    }
    else if(parent != nullptr){
        nodes.push_back(newNode);
        parent->children.push_back(nodes.back()); //This can be problematic idk
    }else{
     std::cout<<"Cant add to tree" << std::endl; //TODO: Remove      
    }
    return &(nodes.back());
}


void AST::showTree(astNode* node){
    std::cout << ":D" << std::endl;
}