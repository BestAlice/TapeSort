//
// Created by dima_ on 6/5/2023.
//
#ifndef ITAPE_H
#define ITAPE_H

class ITape {
public:
    virtual int read() = 0;
    virtual bool write(int number) = 0;
    virtual bool move_forward() = 0;
    virtual bool move_back() = 0;
    virtual bool move_to_beg() = 0;
    virtual bool move_to_end() = 0;
};

#endif
