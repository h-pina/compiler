#include "Ast.h"

class Parser{
    private:
        Lexer *lexer;
        SymbolTable *symbolTable;
        AST ast;
        std::vector<Token> buffer;

    public:
        Parser(Lexer &lex, SymbolTable &sb);
        AST buildAst();
        void parse(TokenType tk, int parentNodeIndex); //validade if next token is the expected and add to tree
        void parse(Token tk, int parentNodeIndex); //add already validated tokenn to tree
        Token getNextToken();
        void throwError(std::string errormsg);
        void program();
        void declList(int parentNodeIndex);
        void decl(int currentNodeIndex);
        void identList(int currentNodeIndex);
        void type(int currentNodeIndex);
        void body(int currentNodeIndex);
        void stmtList(int currentNodeIndex);
        void stmt(int currentNodeIndex);
        void assignStmt(int currentNodeIndex);
        void ifStmt(int currentNodeIndex);
        void condition(int currentNodeIndex);
        void doStmt(int currentNodeIndex);
        void doSuffix(int currentNodeIndex);
        void readStmt(int currentNodeIndex);
        void writeStmt(int currentNodeIndex);
        void writable(int currentNodeIndex);
        void expression(int currentNodeIndex);
        void term(int currentNodeIndex);
        void factorA(int currentNodeIndex);
        void factor(int currentNodeIndex);
        void relop(int currentNodeIndex);
        void addop(int currentNodeIndex);
        void mulop(int currentNodeIndex);
};