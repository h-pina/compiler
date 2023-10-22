#include <vector>
#include "Lexer.h"

struct astNode{
	Token token;
    astNode* parent;
    std::vector<astNode> children;
};

class AST{
    private:
        astNode root;
        std::vector<astNode> nodes;
    public:
        astNode* newNode(Token tk = Token(), astNode *parent = nullptr);
        void showTree(astNode* node = nullptr);

};