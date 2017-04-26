#ifndef TOKEN_NUMBER_H
#define TOKEN_NUMBER_H

#include "Token.h"

namespace BasicParser
{
    class TokenNumber : Token
    {
    private:
	int value;

    public:
	TokenNumber(TokenType type, int value);
	virtual void SetType(TokenType type);
	void SetNumber(int value);
	int GetNumber();
    };
}
#endif /* TOKEN_H */
