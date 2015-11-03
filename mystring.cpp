#include <iostream>
#include <cstring>
#include <cassert> 

#include "./mystring.h"

void mystring::reallocate() 
{
    size_t _new_size = _size << 1;
    assert(_new_size >> 1 == _size);
    char* _new_data = new char[_new_size];
    assert(_new_data != 0);
    strncpy(_new_data, _data, _size);
    delete _data;
    _data = _new_data;
    _end = _data;
}

int mystring::set(char* str, size_t n) {
    strncpy(_data, str, n);
    _end = _data + n;
    return 0;
}

char& mystring::at(int i)
{
    if (i >= 0) {
        assert(_data + i < _end);
        return *(_data + i);
    } else {
        assert(_end + i >= _data);
        return *(_end + i);
    }
}

char mystring::operator [] (int i) const 
{
    return this->at(i);
}

char& mystring::operator [] (int i)
{
    return this->at(i);
}