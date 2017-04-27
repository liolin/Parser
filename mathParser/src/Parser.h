#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "Token.h"
#include "Lexer.h"

namespace BasicParser
{
    class Parser
    {
    private:
	Lexer lexer;
	Token tok;

	bool accept(Token tok);
	void getNextToken();
	
	/* regeln */
	int start();
	int multiplikation();
	int paren();
	int number();
	
    public:
	Parser(std::string);
	int parse();
    };
}

#endif /* PARSER_H */
