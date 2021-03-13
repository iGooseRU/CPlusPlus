#include <iostream>
#include <cmath>
#include <string>

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

    bool operator==(CPoint &a){
        if (x_ == a.get_pointX() && y_ == a.get_pointY()){
            return true;
        }
        return false;
    }

    ~CPoint(){};

    void set_point(float x, float y){
        this -> x_ = x;
        this -> y_ = y;
    };

    float get_pointX(){
        return x_;
    }

    float get_pointY(){
        return y_;
    }
};

std::ostream& operator<< (std::ostream &out, CPoint &point){
    out << point.get_pointX() << " " << point.get_pointY();
    return out;
}

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

    ~CBrokenLine(){};

    bool check_locked(){
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

    float get_LineLength(CPoint &a1, CPoint &a2){
        return sqrt(pow((a2.get_pointX() - a1.get_pointX()), 2) +
                               pow((a2.get_pointY() - a1.get_pointY()), 2));
    }


    float get_perimeter(){
        float result = 0;
        for (int i = 1; i < length_; i++){
            result += get_LineLength(array_[i - 1], array_[i]);
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

    int get_length_(){
        return length_;
    }
};

class CLock_brokenLine : public CBrokenLine{

public:
    CLock_brokenLine(CBrokenLine &a){
        a.check_locked();
        length_ = a.get_length_();
        array_ = a.get_array_();
    }

     CLock_brokenLine(){}

    ~CLock_brokenLine(){};
};

class CPolygon : public CLock_brokenLine{

public:
    void check_ConvexShape();

    CPolygon(CLock_brokenLine &a){
        length_ = a.get_length_();
        array_ = a.get_array_();

        check_ConvexShape();

        std::cout << "The polygon has " << length_ - 1 << " vertexes" << std::endl;

        bool flag = false;
        CPoint current = array_[0];

        for (int i = 1; i < length_; i++) {
            if (current.get_pointX() != array_[i].get_pointX()){
                flag = true;
                break;
            }
        }

        if (!flag){
            throw "All points on one X line";
        }

        flag = false;
        for (int i = 1; i < length_; i++) {
            if (current.get_pointY() != array_[i].get_pointY() ){
                flag = true;
                break;
            }
        }
        if (!flag){
            throw "All points on one Y line";
        }

    }
    void get_square(){
        int n = length_ - 1;
        float sum1 = 0;
        float sum2 = 0;
        float result;
        for (int i = 0; i < n; i++){
            sum1 = sum1 + array_[i].get_pointX() * array_[i + 1].get_pointY();
        }

        for (int i = 0; i < n; i++){
            sum2 = sum2 + array_[i + 1].get_pointX() * array_[i].get_pointY();
        }

        result = 0.5 * abs(sum1 - sum2 + array_[n].get_pointX() * array_[0].get_pointY()
         - array_[0].get_pointX() * array_[n].get_pointY());
        std::cout << "The square of polygon = " << result << std::endl;
    }

     CPolygon(){};
    ~CPolygon(){};
};


void CPolygon::check_ConvexShape(){
    for (int i = 1; i < length_; i++){
     //   std::cout << array_[i] << std::endl;
        float res = (array_[i].get_pointX() - array_[i - 1].get_pointX()) *
                           (array_[i + 1].get_pointY() - array_[i].get_pointY()) -
                                (array_[i].get_pointY() - array_[i - 1].get_pointY()) *
                                      (array_[i + 1].get_pointX() - array_[i].get_pointX());
        if (res >= 0) {
            try
            {
                throw -3;
            }
            catch (int a)
            {
                std::cerr << "ERROR, the line doesn't convex: " << a << '\n';
            }
        }
    }
}




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




};



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

};


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


class CRegular_Polygon : public CPolygon{

public:
    CRegular_Polygon(CPolygon &a){
        length_ = a.get_length_();
        array_ = a.get_array_();

        a.check_ConvexShape();

        std::cout << "The polygon has " << length_ -1 << " vertexes" << std::endl;

        float temp;
        float first_line = get_LineLength(array_[0], array_[1]);
        for (int i = 2; i < length_; i++){
            temp = get_LineLength(array_[i - 1], array_[i]);
        }

        if (temp != first_line){
            try {throw -6;}
            catch (int a) {
                std::cerr << "The polygon is not regular: " << a << std::endl;
            }
        } else {
            std::cout << "The polygon is regular" << std::endl;
            get_perimeter();
            get_length_();
        }
    }

};


int main(){

    CPoint a(0, 0);
    CPoint b(2, 3);
    CPoint c(4, 4);
    CPoint d(6, 0);
    CPoint e(0, 0);



    std::cout << "==================================================" << std::endl;
    std::cout << "\t Broken Line" << std::endl;
    CBrokenLine BrLine;
    BrLine.add_point(a);
    BrLine.add_point(b);
    BrLine.add_point(c);
    BrLine.add_point(d);
    BrLine.add_point(e);

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