#ifndef TOKEN_H
#define TOKEN_H

namespace BasicParser
{
    enum TokenType {
	T_NIL    = 0,
	T_BEGIN  = 1,
	T_END    = 2,
	T_ERROR  = 3,
	T_NUMBER = 10, 
	T_ADD    = 11,
	T_MIN    = 12,
	T_MUL    = 13,
	T_DIV    = 14
    };

    class Token
    {
    private:
	TokenType type;
	int value;

    public:
	Token(TokenType type, int value);
	void SetType(TokenType type);
	TokenType GetType();
	void SetValue(int value);
	int GetValue();
    };
}
#endif /* TOKEN_H */
