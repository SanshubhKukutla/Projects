#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <vector>

class ArrayBuffer{
    private: //define types and instantiate member intializer list variables
        std::vector<char> buf_;
        size_t cap_;
        size_t r_;
        size_t w_;
    
    explicit ArrayBuffer(size_t cap): //explicit forces direct intization (no implicit - must specify constructor)
        buf_(cap), cap_(cap), r_(0), w_(0){ //member intializer list (kinda like global but def inside classes/structs)
            if (cap_ == 0) throw std::invalid_argument("capacity size must be greater than 0");
        }

    // -- Observers --
    size_t capacity() const{return cap_;}
    size_t readable() const{return w_ - r_;} //bytes available to read
    size_t writeable() const{return cap_ - w_;} //free spaces at tail
    bool empty() const{return readable == 0;}

        
    
};