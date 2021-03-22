//
// Created by 86532 on 17.03.2021.
//

#ifndef MAIN_CPP_CLOCK_BROKENLINE_H
#define MAIN_CPP_CLOCK_BROKENLINE_H
#include "CBrokenLine.h"

class CLock_brokenLine : public CBrokenLine{

public:
    CLock_brokenLine(CBrokenLine &a){
        a.check_locked();
        length_ = a.get_length_();
        array_ = a.get_array_();
    }

    CLock_brokenLine(){}

    ~CLock_brokenLine()= default;
};


#endif //MAIN_CPP_CLOCK_BROKENLINE_H
