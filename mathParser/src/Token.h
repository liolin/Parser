#ifndef TOKEN_H
#define TOKEN_H

namespace BasicParser
{
    enum TokenType {
	// general tokens
	T_NIL    = 0,
	T_BEGIN  = 1,
	T_END    = 2,
	T_ERROR  = 3,

	// number tokens
	T_INT    = 10,
	T_FLOUT  = 11,

	// operators
	T_ADD    = 20,
	T_MIN    = 21,
	T_MUL    = 22,
	T_DIV    = 23,
	T_EQUAL  = 24
    };


    class Token
    {
    protected:
	TokenType type;
	int value;
	
    public:
	Token(TokenType type);
	Token(TokenType type, int value);
	void SetType(TokenType type);
	TokenType GetType();
	void SetValue(int value);
	int GetValue();
    };
}
#endif /* TOKEN_H */
