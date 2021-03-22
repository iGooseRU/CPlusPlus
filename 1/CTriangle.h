//
// Created by 86532 on 17.03.2021.
//

#ifndef MAIN_CPP_CTRIANGLE_H
#define MAIN_CPP_CTRIANGLE_H
#include "CPolygon.h"

class CTriangle : public CPolygon{
public:

    CTriangle(CPolygon &a){
        length_ = a.get_length_();
        array_ = a.get_array_();

        if (length_ -1 != 3){
            try
            {
                throw -4;
            }
            catch (int a)
            {
                std::cerr << "Triangle has " << length_ -1 << " vertexes instead 3:  " << a << '\n';
            }
        } else {
            get_perimeter();
            get_square();
        }
    };

    ~CTriangle()= default;

};


#endif //MAIN_CPP_CTRIANGLE_H
