//
// Created by 86532 on 17.03.2021.
//

#ifndef MAIN_CPP_CTRAPEZOID_H
#define MAIN_CPP_CTRAPEZOID_H
#include "CPolygon.h"


class CTrapezoid : public CPolygon {

public:

    void check_TrapVertex();
    void check_parallel();


    CTrapezoid(CPolygon &a){
        length_ = a.get_length_();
        array_ = a.get_array_();

        if (length_ -1 != 4){       /// проверка на кол-во вершин
            try
            {
                throw -4;
            }
            catch (int a)
            {
                std::cerr << "Trapezoid has " << length_ -1 << " vertexes instead 4:  " << a << '\n';
            }
        }

        check_parallel();

    };

    ~CTrapezoid()= default;

};


#endif //MAIN_CPP_CTRAPEZOID_H
