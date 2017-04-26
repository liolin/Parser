#include "Token.h"

using namespace BasicParser;

Token::Token(TokenType type)
{
    this->SetType(type);
}

void Token::SetType(TokenType type)
{
    this->type = type;
}

TokenType Token::GetType()
{
    return this->type;
}
