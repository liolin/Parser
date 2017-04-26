#include <iostream>

#include "Token.h"
#include "TokenNumber.h"

using namespace BasicParser;
using namespace std;

int main()
{
    TokenNumber tok(T_NUMBER, 2);
    cout << "Token number: " << tok.GetNumber() << '\n';
    return 0;
}
