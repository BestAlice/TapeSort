//
// Created by alis on 06.06.23.
//

#include "SortTape.h"

    void SortTape::sort(Tape& input, Tape& output){
        Tape tape1("./tmp/t1.txt", input.get_delays(), 1);
        Tape tape2("./tmp/t2.txt", input.get_delays(), 1);
        Tape* tapeList[2] = {&tape1, &tape2};
        int i = 0;
        Tape* from;
        Tape*  to;

        is_sorted = sort_step(&input, &tape1);
        while(!is_sorted){
            from = tapeList[i];
            to = tapeList[1-i];
            i = 1-i;
            is_sorted = sort_step(from, to);
            //print(to);
        } ;
        sort_step(to, &output);
    }

    bool SortTape::sort_step(Tape* from, Tape* to){
        to->move_to_beg();
        from->move_to_beg();
        int past;
        int current;
        bool changed = 0;
        past = from->read();
        from->move_forward();
        while (!from->is_end()){
            current = from->read();
            if (current < past){
                to->write(current);
                changed =1;
            }else{
                to->write(past);
                past = current;
            };

            to->move_forward();
            from->move_forward();
        }
        //to->move_forward();
        if (past > current){
            to->write(past);
        } else {
            to->write(current);
        }
        return !changed;

    }
