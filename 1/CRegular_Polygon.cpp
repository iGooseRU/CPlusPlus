//
// Created by 86532 on 17.03.2021.
//

#include "CRegular_Polygon.h"

CRegular_Polygon::CRegular_Polygon(CPolygon &a){
    length_ = a.get_length_();
    array_ = a.get_array_();

    a.check_ConvexShape();

    std::cout << "The polygon has " << length_ -1 << " vertexes" << std::endl;

    double temp;
    double first_line = CPoint::get_LineLength(array_[0], array_[1]);
    for (int i = 2; i < length_; i++){
            temp = CPoint::get_LineLength(array_[i - 1], array_[i]);
            if (temp != first_line) {
                try {
                    throw -6;
                }
                catch (int a) {
                    std::cerr << "The polygon is not regular: " << a << std::endl;
                }
                exit(-6);
            }
    }

        std::cout << "The polygon is regular" << std::endl;
        get_perimeter();
        get_length_();
}