//
// Created by alis on 06.06.23.
//

#ifndef YADRO_SORTTAPE_H
#define YADRO_SORTTAPE_H

#include "Tape.h"

class SortTape {
    int is_sorted;
    bool sorted = 0;
public:
    void sort(Tape& input, Tape& output);
    bool sort_step(Tape* from, Tape* to);
};


#endif //YADRO_SORTTAPE_H
