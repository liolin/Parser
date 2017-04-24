#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "Lexer.h"
#include "Token.h"

class Parser
{
private:
    Lexer lex;
    std::string input;
    Token current;
    int curPos;
    std::vector<Token> tokens;

    bool parseInteger();
    bool parseSign();
    bool parseNaturalNumber();
    bool parseNumberExpectZero();
    bool parseNumber();

    void fetchPrev();
    void fetchNext();
    Token peekNext();

public:
    Parser();
    Parser(std::string input);
    
    void SetInput(std:: string input);
    std::string GetInput();

    bool parse();
};

#endif /* PARSER_H */
