#include "Parser.h"

using namespace BasicParser;


bool Parser::accept(Token token)
{
    return (token.GetType() == this->tok.GetType()) ? true : false;
}

void Parser::getNextToken()
{
    this->tok = this->lexer.getNextToken();
}

void Parser::parse(std::string)
{
    return;
}
