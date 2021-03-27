#include <iostream>
#include <cmath>
#include <string>
#include "CPoint.h"
#include "CBrokenLine.h"
#include "CLock_brokenLine.h"
#include "CPolygon.h"
#include "CTriangle.h"
#include "CTrapezoid.h"
#include "CRegular_Polygon.h"


/* Поставьте доп балл за исключения пожалуйста... */


std::ostream& operator<< (std::ostream &out, CPoint &point){
    out << point.get_pointX() << " " << point.get_pointY();
    return out;
}


int main(){

    CPoint a(0, 0);
    CPoint b(3, 4);
    CPoint c(6, 0);
    CPoint d(0, 0);
   // CPoint e(0, 0);



    std::cout << "==================================================" << std::endl;
    std::cout << "\t Broken Line" << std::endl;
    CBrokenLine BrLine;
    BrLine.add_point(a);
    BrLine.add_point(b);
    BrLine.add_point(c);
    BrLine.add_point(d);
   // BrLine.add_point(e);

    BrLine.print_BrokenLine();
    BrLine.get_perimeter();



    std::cout << "==================================================" << std::endl;
    std::cout << "\t Locked Broken Line" << std::endl;
    CLock_brokenLine first_LockedBrokenLine(BrLine);
    first_LockedBrokenLine.get_perimeter();
    first_LockedBrokenLine.print_BrokenLine();


    std::cout << "==================================================" << std::endl;
    std::cout << "\t Polygon" << std::endl;
    CPolygon first_polygon(first_LockedBrokenLine);
    first_polygon.get_perimeter();
    first_polygon.get_square();
    first_polygon.check_ConvexShape();


    std::cout << "==================================================" << std::endl;
    std::cout << "\t Triangle" << std::endl;
    CTriangle first_triangle(first_polygon);


    std::cout << "==================================================" << std::endl;
    std::cout << "\t Trapezoid" << std::endl;
    CTrapezoid first_trapezoid(first_polygon);


    std::cout << "==================================================" << std::endl;
    std::cout << "\t Regular Polygon" << std::endl;
    CRegular_Polygon first_RPolygon(first_polygon);



    return 0;
}