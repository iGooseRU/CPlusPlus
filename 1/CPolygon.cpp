//
// Created by 86532 on 17.03.2021.
//

#include "CPolygon.h"

void CPolygon::check_ConvexShape(){
    for (int i = 1; i < length_ - 1; i++){
        float res = (array_[i].get_pointX() - array_[i - 1].get_pointX()) *
                    (array_[i + 1].get_pointY() - array_[i].get_pointY()) -
                    (array_[i].get_pointY() - array_[i - 1].get_pointY()) *
                    (array_[i + 1].get_pointX() - array_[i].get_pointX());
       // std::cout << res << "!!!" << std::endl;
        if (res > 0) {
            try
            {
                throw -3;
            }
            catch (int a)
            {
                std::cerr << "ERROR, the polygon doesn't convex: " << a << '\n';
            }
        }
    }
}

