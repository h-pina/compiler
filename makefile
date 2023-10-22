Lexer: main.cpp Token.cpp Lexer.cpp SymbolTable.cpp
	g++ -o Parser main.cpp Token.cpp Lexer.cpp SymbolTable.cpp Parser.cpp Ast.cpp -I.