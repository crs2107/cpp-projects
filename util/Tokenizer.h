#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <fstream>

#define BUFFER_SIZE 32*1024
//#define TOK_SIZE 4*1024 + 1
//#define DELIMETER_SIZE 1024

using namespace std;

class Tokenizer 
{
public :
    explicit Tokenizer(const char* file , const char* delimeters);
    ~Tokenizer();
    const char* GetToken();
private :
    void ReadBlock();

private :
    ifstream    _file_handler ;
    const char  *_delimeters ;
    char        _buffer[BUFFER_SIZE] ;
    //char        _token[TOK_SIZE] ;
    //bool      _is_tok_buff_full; 
    char       *_next_ptr ; //Whenver user call GetToken we start to look from _next_ptr
    char       _temp ; //to store the delimeters as well as the next character to a delimeter 
    bool       _is_swap_happened ; //used to understand if swap between temp and next pointer has happened or not
    bool        _is_file_ended ;
    char       *_end_of_buffer_ptr ; //Sometimes it may happen that  buffer does not have the
                               // required space of the block of data we want to read.
                               // So we want to keep track of the end of the buffer also.
    //char       _delimeter_found[DELIMETER_SIZE] ;
} ;

#endif
