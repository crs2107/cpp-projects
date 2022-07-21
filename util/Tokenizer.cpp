#include "Tokenizer.h"
#include <iostream>
#include <cassert>
#include <cstring>

Tokenizer::Tokenizer(const char* file_name , const char* delimeters) :
    _delimeters(delimeters),
    _next_ptr(_buffer),
    _is_file_ended(false),
    _end_of_buffer_ptr(0)
{
    _file_handler.open(file_name) ;
    if(!_file_handler.is_open())
    {
        cout<<"Unable to open file = "<<string(file_name)<<endl ;
        throw "Unable to open file = "+string(file_name);
    }
    // _is_tok_buff_full = false ;
}

Tokenizer::~Tokenizer() 
{
    _file_handler.close() ;
}

const char*
Tokenizer::GetToken()
{
    uint64_t tok_size = 0 ; //points to the first character of each token

    if(_next_ptr > _end_of_buffer_ptr && !_is_file_ended)
    {
        ReadBlock(); //ReadBlock should reset the _next_ptr
    }

    if (_is_file_ended && _next_ptr > _end_of_buffer_ptr)
    {
        return 0 ; // File ended and still next pointer is ahead of _end_of_buffer_ptr. So nothing to return
    }


   
    if(strchr(_delimeters , *_next_ptr) != NULL) 
    {
        _token[tok_size] = *_next_ptr ;
        tok_size ++ ;
        _next_ptr++ ;
        _token[tok_size] = '\0' ;
        return _token ;
    }


    while(strchr(_delimeters , *_next_ptr) == NULL && tok_size <= TOK_SIZE)
    {
        assert(_next_ptr <= _end_of_buffer_ptr) ;
        _token[tok_size] = *_next_ptr ;
        tok_size++ ;
        _next_ptr++ ;
        if (_next_ptr > _end_of_buffer_ptr) {
            if (_is_file_ended) break ;
            ReadBlock() ;
        }
    }

    _token[tok_size] = '\0' ;

    
    return _token ;
}



void 
Tokenizer::ReadBlock() 
{
    _file_handler.read(_buffer,BUFFER_SIZE) ;
    _is_file_ended  = _file_handler.eof() ;
    _next_ptr = _buffer ;
    _end_of_buffer_ptr = _buffer + (_file_handler.gcount() - 1) ; 
}
