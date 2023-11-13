program ::= class identifier [decl-list] body
decl-list ::= decl ";" { decl ";"}
decl ::= type ident-list
ident-list ::= identifier {"," identifier}
type ::= int | string | float
body ::= "{" stmt-list "}"
stmt-list ::= stmt ";" { stmt ";" }
stmt ::= assign-stmt | if-stmt | do-stmt
 | read-stmt | write-stmt
assign-stmt ::= identifier "=" simple_expr
if-stmt ::= if "(" condition ")" "{" stmt-list "}"
 | if "(" condition ")" "{" stmt-list "}" else "{" stmt-list "}"
condition ::= expression
do-stmt ::= do "{" stmt-list "}" do-suffix
do-suffix ::= while "(" condition ")"
read-stmt ::= read "(" identifier ")"
write-stmt ::= write "(" writable ")"
writable ::= simple-expr 
expression ::= simple-expr | simple-expr relop simple-expr
simple-expr ::= term | simple-expr addop term
term ::= factor-a | term mulop factor-a
factor-a ::= factor | "!" factor | "-" factor
factor ::= identifier | constant | "(" expression ")"
relop ::= ">" | ">=" | "<" | "<=" | "!=" | "=="
addop ::= "+" | "-" | "||"
mulop ::= "*" | "/" | "&&"



constant → integer_const | literal | real_const
integer_const → nonzero digit* | 0
real_const → interger_const "." digit+
literal → " “ " caractere* " ” "
identifier → letter {letter | digit | " _ " } 
letter → [A-Za-z]
digit → [0-9]
nonzero → [1-9]
caractere → um dos 256 caracteres do conjunto ASCII, exceto as 
aspas e quebra de linha
