//
// Created by dima_ on 6/5/2023.
//
#include <string.h>
#include "SortTape.h"
#include "Tape.h"

void read_config(Delays& delay){
    FILE* delay_file = fopen("config.txt", "r");
    if (delay_file != nullptr) {
        char action[256];
        int value;

        while (fscanf(delay_file, "%[^:]: %d\n", action, &value) != EOF) {
            if (strcmp(action, "read") == 0) {
                delay.read = value;
            } else if (strcmp(action, "write") == 0) {
                delay.write = value;
            } else if (strcmp(action, "move_on_one") == 0) {
                delay.move_on_one = value;
            } else if (strcmp(action, "rewind") == 0) {
                delay.rewind = value;
            }
        }

        fclose(delay_file);
    }

}

int main(int argc, char *argv[]){
    Delays delays;
    read_config(delays);

    char* input_filename = argv[1];
    char* output_filename = argv[2];

    //std::cout << input_filename << std::endl;

    Tape input( input_filename, delays, 0); // //"./input.txt"

    //int list[10] ={12, 20000, 0, 443, 2,  5, 63, 0, 2, 90};
    //input.fill_tape( list, 10);
    std::cout << "input: ";
    input.print();
    Tape output(output_filename, delays, 1); //"./output.txt"
    SortTape sorter;
    sorter.sort(input, output);
    std::cout << "output: ";
    output.print();
    return 0;
}