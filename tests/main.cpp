#include "Tokenizer.h"
#include <iostream>
#include<string>

int
main(int argc , char *argv[])
{
    if(argc < 2)
    {
        cout << "Please provide a filename" << endl ;
        return 0;
    }

    Tokenizer  tok(argv[1],"\n, ") ;

    const char *token = tok.GetToken() ;
    while (token) {
        cout << "Token Obtained = '" << token << "'" << endl ;
        token = tok.GetToken() ;
    }

    return 0 ;
}
