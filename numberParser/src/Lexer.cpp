#include "Lexer.h"

using namespace BasicParser;

Lexer::Lexer(){}

Lexer::Lexer(std::string input)
{
    this->input = input;
}

void Lexer::SetInput(std::string input)
{
    this->input = input;
}

std::string Lexer::GetInput()
{
    return this->input;
}

void Lexer::tokenice(std::string input)
{
    this->token.push_back(T_BEGIN);
    for(int i = 0; i < input.length(); i++)
    {
	switch(input[i])
	{
	case('+'):
	    this->token.push_back(T_ADD);
	    break;
	case('-'):
	    this->token.push_back(T_MIN);
	    break;
	case('*'):
	    this->token.push_back(T_MUL);
	    break;
	case('/'):
	    this->token.push_back(T_DIV);
	    break;
	case('0'):
	    this->token.push_back(T_ZERO);
	    break;
	case('1'):
	    this->token.push_back(T_ONE);
	    break;
	case('2'):
	    this->token.push_back(T_TWO);
	    break;
	case('3'):
	    this->token.push_back(T_THREE);
	    break;
	case('4'):
	    this->token.push_back(T_FOUR);
	    break;
	case('5'):
	    this->token.push_back(T_FIVE);
	    break;
	case('6'):
	    this->token.push_back(T_SIX);
	    break;
	case('7'):
	    this->token.push_back(T_SEVEN);
	    break;
	case('8'):
	    this->token.push_back(T_EIGTH);
	    break;
	case('9'):
	    this->token.push_back(T_NINE);
	    break;
	default:
	    this->token.push_back(T_NULL);
	}
    }
    this->token.push_back(T_END);
}

std::vector<Token> Lexer::GetTokens()
{
    this->tokenice(this->input);
    return this->token;
}
