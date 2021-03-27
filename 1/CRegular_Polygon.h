//
// Created by 86532 on 17.03.2021.
//

#ifndef MAIN_CPP_CREGULAR_POLYGON_H
#define MAIN_CPP_CREGULAR_POLYGON_H
#include "CPolygon.h"

class CRegular_Polygon : public CPolygon{

public:
    CRegular_Polygon(CPolygon &a);
    ~CRegular_Polygon()= default;

};

#endif //MAIN_CPP_CREGULAR_POLYGON_H
