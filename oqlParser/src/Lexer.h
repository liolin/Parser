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
	std::string input;
	unsigned int curPos;
	unsigned int curPosVec;
	char ch;
	std::vector<Token> tokens;

	void iniTokeVec();
	Token readNextToken();
	void skipSpace();
	void readNextChar();
	
    public:
	Lexer(std::string input);
	Token getNextToken(bool peek = false);
    };
}

#endif /* LEXER_H */
