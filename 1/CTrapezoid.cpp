//
// Created by 86532 on 17.03.2021.
//

#include "CTrapezoid.h"

void CTrapezoid::check_parallel() {
    float k = (array_[0].get_pointY() - array_[3].get_pointY()) /
              (array_[0].get_pointX() - array_[3].get_pointX());
    float k1 = (array_[1].get_pointY() - array_[2].get_pointY()) /
               (array_[1].get_pointX() - array_[2].get_pointX());
    if (k != k1){
        try {throw -7;}
        catch (int a) {
            std::cerr << "The trapezoid lines doesnt parallel: " << a <<std::endl;
        }
    } else {
        get_perimeter();
        get_square();
    }
}
