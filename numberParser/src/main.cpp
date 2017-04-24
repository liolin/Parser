#include <iostream>
#include <vector>
#include <string>
#include "Parser.h"

using namespace BasicParser;

int main()
{
    std::string in = "";

    std::cin >> in;
    
    Parser* parse = new Parser(in);
    if(parse->parse())
	std::cout << "An valid integer\n";
    else
	std::cout << "This is not an valid integer\n";
    return 0;
}
