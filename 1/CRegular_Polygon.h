//
// Created by 86532 on 17.03.2021.
//

#ifndef MAIN_CPP_CREGULAR_POLYGON_H
#define MAIN_CPP_CREGULAR_POLYGON_H
#include "CPolygon.h"

class CRegular_Polygon : public CPolygon{

public:
    CRegular_Polygon(CPolygon &a);
/*
    CRegular_Polygon(CPolygon &a){
        length_ = a.get_length_();
        array_ = a.get_array_();

        a.check_ConvexShape();

        std::cout << "The polygon has " << length_ -1 << " vertexes" << std::endl;

        float temp;
        float first_line = CPoint::get_LineLength(array_[0], array_[1]);
        for (int i = 2; i < length_; i++){
            temp = CPoint::get_LineLength(array_[i - 1], array_[i]);
            if (temp != first_line){
                try {
                    throw -6;
                }
                catch (int a) {
                    std::cerr << "The polygon is not regular: " << a << std::endl;
                }
            } else {
                std::cout << "The polygon is regular" << std::endl;
                get_perimeter();
                get_length_();
            }
        }
    }
*/
    ~CRegular_Polygon()= default;

};

#endif //MAIN_CPP_CREGULAR_POLYGON_H
