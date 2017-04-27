#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

enum TokenType {
    // general tokens
    T_NIL    = 0,
    T_BEGIN  = 1,
    T_END    = 2,
    T_ERROR  = 3,

    // keywords
    T_SELECT = 10,
    T_FROM   = 11,
    T_WHERE  = 12,
    
    T_FIELD = 20,
    T_RPAREN = 21,
};

#endif /* TOKEN_TYPE_H */
