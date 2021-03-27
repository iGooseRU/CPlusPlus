//
// Created by 86532 on 17.03.2021.
//

#ifndef MAIN_CPP_CPOINT_H
#define MAIN_CPP_CPOINT_H
#include <cmath>
#include <iostream>

class CPoint{
private:
    float x_;
    float y_;

public:
    /// Конструктор по-умолчанию
    CPoint(){
        x_ = 0.0;
        y_ = 0.0;
    }

    /// Конструктор с параметрами
    CPoint(float x, float y){
        x_ = x;
        y_ = y;
    }

    /// Оператор присваивания
    CPoint& operator= (const CPoint &point){
        x_ = point.x_;
        y_ = point.y_;
        return *this;
    }


    /// Конструктор копирования
    CPoint(const CPoint &point){
        x_ = point.x_;
        y_ = point.y_;
    }

    bool operator==(const CPoint &a) const{
        if (x_ == a.get_pointX() && y_ == a.get_pointY()){
            return true;
        }
        return false;
    }


    void set_point(float x, float y){
        this -> x_ = x;
        this -> y_ = y;
    };

    float get_pointX() const{
        return x_;
    }

    float get_pointY() const{
        return y_;
    }

    static double get_LineLength(CPoint &a1, CPoint &a2){
        return sqrt(pow((a2.get_pointX() - a1.get_pointX()), 2) +
                    pow((a2.get_pointY() - a1.get_pointY()), 2));
    }

    ~CPoint()= default;
};



#endif //MAIN_CPP_CPOINT_H
