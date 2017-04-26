#include "Lexer.h"

using namespace BasicParser;

Lexer::Lexer()
    :pos(-1)
{
}

bool Lexer::isNumeric(char c)
{
    switch(c)
    {
    case('0'):
    case('1'):
    case('2'):
    case('3'):
    case('4'):
    case('5'):
    case('6'):
    case('7'):
    case('8'):
    case('9'):
	return true;
    default:
	return false;
    }
}

void Lexer::tokenice(std::string input)
{
    this->tokens.push_back(Token(T_BEGIN));
    std::string tmp;
    for(int i = 0; i < input.length(); i++)
    {
	if(this->isNumeric(input[i]))
	{
	    tmp += input[i];
	    continue;
	}
	else
	{
	    this->tokens.push_back(Token(T_INT, 123));
	    tmp = "";
	}
	
	switch(input[i])
	{
	case('+'):
	    this->tokens.push_back(Token(T_ADD));
	    break;
	case('-'):
	    this->tokens.push_back(Token(T_MIN));
	    break;
	case('*'):
	    this->tokens.push_back(Token(T_MUL));
	    break;
	case('/'):
	    this->tokens.push_back(Token(T_DIV));
	    break;
	default:
	    this->tokens.push_back(Token(T_NIL));
	    break;
	}
    }
    this->tokens.push_back(Token(T_END));

    return;
}

std::vector<Token> Lexer::getAllTokens()
{
    return this->tokens;
}

Token Lexer::getNextToken(bool peek)
{
    if(pos+1 >= this->tokens.size())
	return T_ERROR;

    if(peek)
	return this->tokens[this->pos+1];
    else
    {
	this->pos++;
	return this->tokens[this->pos];
    }
}
