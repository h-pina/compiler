#include <vector>
#include "Lexer.h"

struct astNode{
	Token token;
    int parent;
    std::vector<int> children;
};

class AST{
    private:
        std::vector<astNode> nodes;
    public:
        int root;
        int newNode(Token tk , int parentIndex);
};