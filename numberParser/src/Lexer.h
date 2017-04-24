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
	std::vector<Token> token;
	std::string input;
	void tokenice(std::string input);
    
    public:
	Lexer();
	Lexer(std::string input);
	void SetInput(std::string input);
	std::string GetInput();
	std::vector<Token> GetTokens();
    };
}
#endif /* LEXER_H */
