//
// Created by 86532 on 17.03.2021.
//

#ifndef MAIN_CPP_CBROKENLINE_H
#define MAIN_CPP_CBROKENLINE_H
#include "CPoint.h"

class CBrokenLine{

protected:
    int length_;
    CPoint *array_;

public:

    /// Конструктор по-умолчанию
    CBrokenLine(){
        length_ = 0;
        array_ = new CPoint[length_];
    }

    /// Оператор присваивания
    CBrokenLine& operator= (const CBrokenLine &obj){
        length_ = obj.length_;
        array_ = obj.array_;
        return *this;
    }

    /// Конструктор копирования
    CBrokenLine(const CBrokenLine &obj){
        length_ = obj.length_;
        array_ = obj.array_;
    }



    void check_locked(){
        if (array_[0] == array_[length_ - 1]){
            std::cout << "correct, the line is locked" << std::endl;
        } else {
            try
            {
                throw -1;
            }
            catch (int a)
            {
                std::cerr << "ERROR, the line doesn't locked: " << a << '\n';
            }
        }
    }

    void add_point(CPoint &obj){
        CPoint* arr = new CPoint[length_ + 1];

        for (int i = 0; i < length_; i++){
            arr[i] = array_[i];
        }

        arr[length_] = obj;
        delete[] array_;
        this -> array_ = arr;

        length_++;
    }



    virtual float get_perimeter(){
        float result = 0;
        for (int i = 1; i < length_; i++){
            result += CPoint::get_LineLength(array_[i - 1], array_[i]);
        }
        std::cout << "The perimeter is: " << result << std::endl;
        return result;
    }

    void print_BrokenLine(){
        for (int i = 0; i < length_; i++){
            std::cout << "( " << array_[i].get_pointX() << " ; " << array_[i].get_pointY() << " )" << std::endl;
        }
    }

    CPoint* get_array_(){
        return array_;
    }

    int get_length_() const{
        return length_;
    }

    ~CBrokenLine(){
        delete[] array_;
    }

};



#endif //MAIN_CPP_CBROKENLINE_H
