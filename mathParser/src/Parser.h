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

	
    public:
	void parse(std::string);
    };
}

#endif /* PARSER_H */
