//
// Created by dima_ on 6/5/2023.
//
#ifndef DELAYED_TAPE_H
#define DELAYED_TAPE_H

#include <fstream>
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <string>
#include "ITape.h"


struct Delays{
    int read;
    int write;
    int move_on_one;
    int rewind;
};

class Tape: public ITape {
    static const int int_size = sizeof(int);

    std::fstream file;
    Delays delays;
    char buffer[int_size] ;
public:
    Tape(char* tape_name, Delays delays_, bool clear);
    ~Tape();
    int read();
    bool write(int number);
    bool move_forward() ;
    bool move_back();
    bool move_to_beg();
    bool move_to_end();
    bool is_end();
    Delays get_delays();
    void print();
    void fill_tape(int* list, int count);
};

#endif

