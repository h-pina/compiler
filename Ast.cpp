#include "Ast.h"
#include <iostream>


int AST::newNode(Token tk, int parentIndex){
    
    astNode newNode = {tk, parentIndex};
    if(nodes.size() == 0){
        nodes.push_back(newNode);
        root = nodes.size() - 1; 
    }
    else {
        nodes.push_back(newNode);
        nodes[parentIndex].children.push_back(nodes.size()-1); 
    }
    return nodes.size() - 1; 
}