#include "Parser.h"
#include <iostream>

using namespace BasicParser;

Parser::Parser(std::string input)
    :lexer(input)
{
    this->getNextToken();
}

bool Parser::accept(Token token)
{
    //std::cerr << "Error: unerwartetes Token " << this->_tok.toString() << ", " << TokenTypeStr[type] << " erwartet" << std::endl;
    if(this->tok.GetType() != token.GetType())
        std::cerr << "Error: unerwartetes Token\n";
    this->getNextToken();
    return true;
}

void Parser::getNextToken()
{
    this->tok = this->lexer.getNextToken();
}

int Parser::parse()
{
    int res = 0;
    if(!this->accept(T_BEGIN))
	return 0;

    res = this->start();

    if(!this->accept(T_END))
	return 0;

    return res;
}

int Parser::start()
{
    int res = 0;
    res = this->multiplikation();

    while(this->tok.GetType() == T_ADD || this->tok.GetType() == T_MIN)
    {
	switch(this->tok.GetType())
	{
	case(T_ADD):
	    this->getNextToken();
	    res += this->multiplikation();
	    break;
	case(T_MIN):
	    this->getNextToken();
	    res -= this->multiplikation();
	    break;
	default:
	    res += this->multiplikation();
	}
    }
    
    return res;
}

int Parser::multiplikation()
{
    int res = 0;
    res = this->paren();

    while(this->tok.GetType() == T_MUL || this->tok.GetType() == T_DIV)
    {
	switch(this->tok.GetType())
	{
	case(T_MUL):
	    this->getNextToken();
	    res *= this->paren();
	    break;
	case(T_DIV):
	    this->getNextToken();
	    res /= this->paren();
	    break;
	default:
	    res *= this->paren();
	}
    }
    
    return res;
}

int Parser::paren()
{
    int sign = 1; // +1 = +; -1 = -;

    if(this->tok.GetType() == T_ADD || this->tok.GetType() == T_MIN)
    {
	if(this->tok.GetType() == T_MIN)
	    sign = -1;

	this->getNextToken();
    }
    
    if(this->tok.GetType() == T_LPAREN)
    {
	this->accept(T_LPAREN);
	int res = sign * this->start();
	this->accept(T_RPAREN);

	return res;
    }

    return sign * this->number();
}

int Parser::number()
{
    int res = 0;
    res = this->tok.GetValue();
    res = (this->accept(T_INT)) ? res : 0;
    return res;
}

