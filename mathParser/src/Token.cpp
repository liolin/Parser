#include "Token.h"

using namespace BasicParser;

Token::Token()
{
}

Token::Token(TokenType type)
{
    this->SetType(type);
    this->SetValue(0);
}

Token::Token(TokenType type, int value)
{
    this->SetType(type);
    this->SetValue(value);
}

void Token::SetType(TokenType type)
{
    this->type = type;
}

TokenType Token::GetType()
{
    return this->type;
}

void Token::SetValue(int value)
{
    this->value = value;
}

int Token::GetValue()
{
    return this->value;
}
