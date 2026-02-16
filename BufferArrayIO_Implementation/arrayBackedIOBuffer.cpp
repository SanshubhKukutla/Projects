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
    
    public:
        explicit ArrayBuffer(size_t cap): //explicit forces direct intization (no implicit - must specify constructor)
        buf_(cap), cap_(cap), r_(0), w_(0){ //member intializer list (kinda like global but def inside classes/structs)
            if (cap_ == 0) throw std::invalid_argument("capacity size must be greater than 0");
        }

        // -- Observers --
        size_t capacity() const{return cap_;}
        size_t readable() const{return w_ - r_;} //bytes available to read
        size_t writable() const{return cap_ - w_;} //free spaces at tail
        bool empty() const{return readable() == 0;}

        //Pointer to readable region - valid for readable() bytes
        const char* read_ptr() const {return buf_.data() + r_;}
        //Pointer to writable region - valid for writable() bytes
        char* write_ptr() { return buf_.data() + w_; }

        // ---- Mutators ----
        void did_write(size_t n) {
            // TODO
        }

        void did_read(size_t n) {
            // TODO
        }

        void compact() {
            // TODO
        }
};

class BufferedReader {
public:
    BufferedReader(std::istream& in, size_t cap)
        : in_(in), buf_(cap) {}

    size_t read(char* out, size_t n) {
        // TODO
        return 0;
    }

private:
    void refill() {
        // TODO
    }

    std::istream& in_;
    ArrayBuffer buf_;
};

class BufferedWriter {
public:
    BufferedWriter(std::ostream& out, size_t cap)
        : out_(out), buf_(cap) {}

    size_t write(const char* data, size_t n) {
        // TODO
        return 0;
    }

    void flush() {
        // TODO
    }

private:
    std::ostream& out_;
    ArrayBuffer buf_;
};


