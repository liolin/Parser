#include <iostream>
#include <string>

#include "Parser.h"

using namespace BasicParser;
using namespace std;

int main()
{
    string in;
    cin >> in;

    Parser a(in);

    cout << a.parse() << '\n';
    
    return 0;
}
