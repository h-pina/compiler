//Specifies all the available token types
enum class TokenType{
    //reserved words
    tk_class,
    tk_if,
    tk_else,
    tk_do,
    tk_while,
    tk_read,
    tk_write,

    //types
    tk_intType,
    tk_stringType,
    tk_floatType,
    
    //constants
    tk_int,
    tk_real,
    tk_literal,
    tk_identifier,

    //symbols
    tk_comma,
    tk_semicolon,
    tk_openBracket,
    tk_closedBracket,
    tk_openPar,
    tk_closePar,
    tk_assign,

    //operations
    tk_minus,
    tk_plus,
    tk_factor,
    tk_lessEqualThan,
    tk_lessThan,
    tk_greaterThan,
    tk_greaterEqualThan,
    tk_notEqual,
    tk_equal,
    tk_or,
    tk_and,
    tk_divBy,
    tk_mulBy,

    tk_eof,

    tk_empty // Used on the default empty token
};
