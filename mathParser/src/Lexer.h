#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string>
#include "Token.h"

namespace BasicParser
{
    class Lexer
    {
    private:
	int pos;
	std::vector<Token> tokens;

	bool isNumeric(char c);
	
    public:
	Lexer();
	void tokenice(std::string input);
	std::vector<Token> getAllTokens();
	Token getNextToken(bool peek = false);
    };
}

#endif /* LEXER_H */
