//
// Created by 86532 on 17.03.2021.
//

#ifndef MAIN_CPP_CPOLYGON_H
#define MAIN_CPP_CPOLYGON_H
#include "CLock_brokenLine.h"

class CPolygon : public CLock_brokenLine{

public:
    void check_ConvexShape();

    CPolygon(CLock_brokenLine &a){
        length_ = a.get_length_();
        array_ = a.get_array_();

        check_ConvexShape();

        std::cout << "The polygon has " << length_ - 1 << " vertexes" << std::endl;
    }

    void get_square(){
        int n = length_ - 1;
        double sum1 = 0;
        double sum2 = 0;
        double result;
        for (int i = 0; i < n; i++){
            sum1 = sum1 + array_[i].get_pointX() * array_[i + 1].get_pointY();
        }

        for (int i = 0; i < n; i++){
            sum2 = sum2 + array_[i + 1].get_pointX() * array_[i].get_pointY();
        }

        result = 0.5 * abs(sum1 - sum2 + array_[n].get_pointX() * array_[0].get_pointY()
                           - array_[0].get_pointX() * array_[n].get_pointY());
        std::cout << "The square of polygon = " << result << std::endl;
    }

    CPolygon(){};

    ~CPolygon()= default;
};




#endif //MAIN_CPP_CPOLYGON_H
