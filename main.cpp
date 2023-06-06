//
// Created by dima_ on 6/5/2023.
//
#include "Tape.h"

int main(int argc, char *argv[]){
    Delays del{0, 0,0,0};
    Tape tape("./tmp/tape1.txt", del);
    tape.write(4);
    tape.move_forward();
    tape.write(5);
    tape.move_forward();
    tape.write(1);
    tape.move_to_beg();
    std::cout << tape.read() << std::endl;
    tape.move_back();
    std::cout << tape.read()<< std::endl;
    tape.move_forward();
    std::cout << tape.read()<< std::endl;
    tape.move_to_end();
    std::cout << tape.read()<< std::endl;
    tape.move_forward();
    return 0;
}