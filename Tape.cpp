//
// Created by dima_ on 6/5/2023.
//
#include "Tape.h"

Tape::Tape(char* tape_name, Delays delays_){
    file.open(tape_name,  std::fstream::in | std::fstream::out | std::fstream::binary  | std::fstream::trunc); //
    if (!file.is_open()) {
        std::cout << "File is not opened\n" << std::endl;
    }
    this->delays = delays_;
}
Tape::~Tape(){
    file.close();
}

int Tape::read(){
    file.read(buffer, int_size);
    file.seekg(-1*int_size, std::ios_base::cur);
    int number;
    sscanf(buffer, "%x", &number);
    return number;
};

bool Tape::write(int number){
    const char* data = std::to_string(number).c_str();
    file.write(data, int_size);
    file.seekg(-1*int_size, std::ios_base::cur);
    return 1;
};

bool Tape::move_forward() {
    if (file.peek() == EOF)
        return 0;
    file.seekg(1*int_size, std::ios_base::cur);
    return 1;
};
bool Tape::move_back(){
    if (file.tellg() == 0)
        return 0;
    file.seekg(-1*int_size, std::ios_base::cur);
    return 1;
};
bool Tape::move_to_beg(){
    file.seekg(0, std::ios_base::beg);
    return 1;
};
bool Tape::move_to_end() {
    file.seekg(-1*int_size, std::ios_base::end);
    return 1;
};