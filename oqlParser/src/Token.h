#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "TokenType.h"

namespace BasicParser
{
    class Token
    {
    protected:
	TokenType type;
	std::string data;
	
    public:
	Token();
	Token(TokenType type);
	Token(TokenType type, std::string data);
	void SetType(const TokenType type);
	TokenType GetType();
	void SetValue(const std::string data);
	std::string GetValue();

	bool equal(const Token tok);
	bool operator ==(const Token& tok);
	bool operator !=(const Token& tok);
    };
}
#endif /* TOKEN_H */
