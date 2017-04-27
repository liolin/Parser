#include "Token.h"

using namespace BasicParser;

Token::Token()
{
}

Token::Token(TokenType type)
{
    this->SetType(type);
    this->SetValue("");
}

Token::Token(TokenType type, std::string data)
{
    this->SetType(type);
    this->SetValue(data);
}

void Token::SetType(TokenType type)
{
    this->type = type;
}

TokenType Token::GetType()
{
    return this->type;
}

void Token::SetValue(std::string data)
{
    this->data = data;
}

std::string Token::GetValue()
{
    return this->data;
}

bool Token::equal(const Token tok)
{
    if(this->type == tok.type && this->data == tok.data)
	return true;
    else
	return false;
}

bool Token::operator ==(const Token& tok)
{
    return this->type == tok.type;
}

bool Token::operator !=(const Token& tok)
{
    return this->type != tok.type;
}
