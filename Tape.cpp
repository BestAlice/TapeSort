//
// Created by dima_ on 6/5/2023.
//
#include "Tape.h"

Tape::Tape(char* tape_name, Delays delays_, bool clear){
    if (clear){
        file.open(tape_name,  std::fstream::in | std::fstream::out | std::fstream::binary  | std::fstream::trunc);
    } else {
        file.open(tape_name,  std::fstream::in | std::fstream::out | std::fstream::binary  );
    }
    if (!file.is_open()) {
        std::cout << "File is not opened\n" << std::endl;
        exit(1);
    }
    this->delays = delays_;
}
Tape::~Tape(){
    file.close();
}

int Tape::read(){
    if (file.peek() == EOF) 
        return -1;
    file.read(buffer, int_size);
    file.seekg(-1*int_size, std::ios_base::cur);
     std::string hex(buffer);
     int number = std::stoi(hex, nullptr, 16); 
     std::cout << number << std::endl;
     usleep(delays.read);
     return number;
};

bool Tape::write(int number){
    //const char* data;//std::to_string(number).c_str();
    std::string data;
    std::stringstream stream;
    stream << std::hex<<number;
    file.write(stream.str().c_str(), int_size);
    file.seekg(-1*int_size, std::ios_base::cur);
    usleep(delays.write);
    return 1;
};

bool Tape::move_forward() {
    usleep(delays.move_on_one);
    file.seekg(1*int_size, std::ios_base::cur);
    return 1;
};
bool Tape::move_back(){
    usleep(delays.move_on_one);
    if (file.tellg() == 0)
        return 0;
    file.seekg(-1*int_size, std::ios_base::cur);
    return 1;
};
bool Tape::move_to_beg(){
    usleep(delays.rewind);
    file.seekg(0, std::ios_base::beg);
    return 1;
};
bool Tape::move_to_end() {
    usleep(delays.rewind);
    file.seekg(-1*int_size, std::ios_base::end);
    return 1;
};

bool Tape::is_end(){
    if (file.peek() == EOF) 
        return 1;
    return 0;
};

Delays Tape::get_delays(){
    return this->delays;
};

void Tape::print(){
    this->move_to_beg();
    while (!this->is_end())
    {
        std::cout << this->read() <<" ";
        this->move_forward();
    }
    std::cout << std::endl;
    this->move_to_beg();
}

void Tape::fill_tape(int* list, int count){
    this->move_to_beg();
    for (size_t i = 0; i < count; i++)
    {
        this->write(list[i]);
        this->move_forward();
    }
    this->move_to_beg();
}
