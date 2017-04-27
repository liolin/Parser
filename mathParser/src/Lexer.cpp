#include "Lexer.h"

using namespace BasicParser;

Lexer::Lexer(std::string input)
    :input(input), curPos(0), curPosVec(0)
{
    this->readNextChar();
    this->iniTokeVec();
}

/**
   @brief Get next token from vector

   @param bool peek if true peeks the next, else gets the next
*/
Token Lexer::getNextToken(bool peek)
{
    if(this->curPosVec < this->tokens.size())
    {
	if(!peek)
	    return this->tokens[this->curPosVec++];
	return this->tokens[this->curPosVec];
    }

    return Token(T_NIL);
}

/**
   @brief Reads next token from input string
*/
Token Lexer::readNextToken()
{
    std::string buffer;
    this->skipSpace();

    switch(this->ch)
    {
    case '+':
	this->readNextChar();
	return Token(T_ADD);
    case '-':
	this->readNextChar();
	return Token(T_MIN);
    case '*':
	this->readNextChar();
	return Token(T_MUL);
    case '/':
	this->readNextChar();
	return Token(T_DIV);
    // case '(':
    // 	this->readNextChar();
    // 	return Token(TT_LPAREN);
    // case ')':
    // 	this->readNextChar();
    // 		return Token(TT_RPAREN);

    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
	while (isdigit(this->ch))
	{
	    buffer += this->ch;
	    this->readNextChar();
	}
	
	return Token(T_INT, std::stoi(buffer));
	
    default:
	if (this->ch != 0)
	    //std::wcerr << "Error: nicht unterstuetzes Zeichen: '" << this->_ch << "'" << std::endl;
	    break;
    }
    
    // Keine tokens mehr gefunden
    return Token(T_END);
}

/**
   @brief Read next char from the input string

   Read next char from the input string and writes to this->ch
*/
void Lexer::readNextChar()
{
    if(this->curPos > this->input.length())
    {
	this->ch = 0;
	return;
    }

    this->ch = this->input[this->curPos++];
}

/**
   @brief Skip spaces from the input string
*/
void Lexer::skipSpace()
{
    while(this->ch == ' ' || this->ch == '\t' || this->ch == '\r' || this->ch == '\n')
	this->readNextChar();
}

/**
   @brief Fills the vector with tokens from the input string
*/
void Lexer::iniTokeVec()
{
    Token tok = this->readNextToken();

    while(tok.GetType() != T_END)
    {
	this->tokens.push_back(tok);
	tok = this->readNextToken();
    }
}
