#include "Parser.h"

using namespace BasicParser;

Parser::Parser()
{
    this->input = "";
    this->current = T_NULL;
    this->curPos = -1;
}
Parser::Parser(std::string input)
{
    this->input = input;
    this->lex.SetInput(input);
    this->current = T_NULL;
    this->curPos = -1;
}

void Parser::SetInput(std::string input)
{
    this->input = input;
}

std::string Parser::GetInput()
{
    return this->input;
}

bool Parser::parse()
{
    this->tokens = this->lex.GetTokens();
    Token tmp = this->peekNext();
    
    if(tmp != T_BEGIN)
	return false;
    this->fetchNext();    
    return this->parseInteger();
}

bool Parser::parseInteger()
{
    Token tmp = T_NULL;

    tmp = this->peekNext();
    if(this->parseSign())
	this->fetchNext();

    if(this->current != T_ADD && this->current != T_MIN)
    {
	while(this->peekNext() == T_ZERO)
	{
	    this->fetchNext();
	}    
    }
    if(!this->parseNaturalNumber())
	return false;

    tmp = this->peekNext();
    if(tmp != T_END)
	return false;
    return true;
}

bool Parser::parseSign()
{
    Token tmp = this->peekNext();
    if(tmp != T_ADD)
    {
	if(tmp != T_MIN)
	    return false;
	return true;
    }
    return true;
}

bool Parser::parseNaturalNumber()
{
    if(!this->parseNumberExpectZero())
	return false;
    this->fetchNext();
    
    while(this->parseNumber()){this->fetchNext();};
    this->fetchPrev();
    return true;
}

bool Parser::parseNumberExpectZero()
{
    Token tmp = this->peekNext();
    switch(tmp)
    {
    case(T_ONE):
    case(T_TWO):
    case(T_THREE):
    case(T_FOUR): 
    case(T_FIVE): 
    case(T_SIX):
    case(T_SEVEN):
    case(T_EIGTH):
    case(T_NINE): return true;
    default:
	return false;
    }
}

bool Parser::parseNumber()
{
    Token tmp = this->peekNext();
    if(tmp != T_ZERO)
    {
	if(!this->parseNumberExpectZero())
	    return false;
	return true;
    }
    return true;
}

void Parser::fetchPrev()
{
    this->curPos--;
    if(this->curPos > 0)
    {
	this->current = this->tokens[this->curPos];
    }
    this->curPos++;
    this->current = T_ERROR;
}

void Parser::fetchNext()
{
    this->curPos++;
    if(this->curPos < this->tokens.size())
    {
	this->current = this->tokens[this->curPos];
	return;
    }
    this->curPos--;
    this->current = T_ERROR;
}

Token Parser::peekNext()
{
    if(this->curPos+1 < this->tokens.size())
	return this->tokens[this->curPos+1];
    return T_ERROR;
}
