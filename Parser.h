#include "Ast.h"

class Parser{
    private:
        Lexer *lexer;
        SymbolTable *symbolTable;
        AST ast;

    public:
        Parser(Lexer &lex, SymbolTable &sb);
        AST buildAst();
        void parse(TokenType tk, astNode *parentNode);
        void program();
        void declList(astNode* parentNode);
        void decl(astNode* parentNode);
        void identList(astNode* parentNode);
        void type(astNode* parentNode);
        void body(astNode* parentNode);
        void stmtList(astNode* parentNode);
        void stmt(astNode* parentNode);
        void assignStmt(astNode* parentNode);
        void ifStmt(astNode* parentNode);
        void condition(astNode* parentNode);
        void doStmt(astNode* parentNode);
        void doSuffix(astNode* parentNode);
        void readStmt(astNode* parentNode);
        void writeStmt(astNode* parentNode);
        void writable(astNode* parentNode);
        void expression(astNode* parentNode);
        void term(astNode* parentNode);
        void factorA(astNode* parentNode);
        void factor(astNode* parentNode);
        void relop(astNode* parentNode);
        void addop(astNode* parentNode);
        void mulop(astNode* parentNode);
};