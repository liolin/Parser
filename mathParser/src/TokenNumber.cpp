#include "TokenNumber.h"

using namespace BasicParser;

TokenNumber::TokenNumber(TokenType type, int value)
    : Token(type)
{
    this->SetNumber(value);
}

void TokenNumber::SetType(TokenType type)
{
    this->type = type;
}

void TokenNumber::SetNumber(int value)
{
    this->value = value;
}

int TokenNumber::GetNumber()
{
    return this->value;
}
