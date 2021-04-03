#include <iostream>
#include <map>

class CPolinomial{

protected:
    std::map<int, float> MyMap_;

public:
    CPolinomial() {
        MyMap_.emplace(1,1);
    }

    CPolinomial(const std::map<float, int>& myMap)
    {
        for (const auto& obj : myMap)
        {
            if (obj.second < 0)
                try
                {
                    throw -1;
                }
                catch (int a)
                {
                    std::cerr << "Degree must be > 0:  " << a << '\n';
                }
        }

        for (const auto element : myMap)
        {
            MyMap_[element.second] = element.first;
        }
    }

    CPolinomial(const CPolinomial& other) = default;

    void get_map(int num){
        auto it = MyMap_.find(num);
        std::cout << it -> second;
    }

    CPolinomial& operator=(const CPolinomial& other){
        if (*this != other){
            MyMap_ = other.MyMap_;
            return *this;
        }
        return *this;
    }

    CPolinomial operator-() const{
        CPolinomial polinomial;
        for (const auto& pair : MyMap_){
            polinomial.MyMap_[pair.first] = -pair.second;
        }
        return polinomial;
    }

    CPolinomial operator+(const CPolinomial& other) const{
        int deg;
        double coefficient;
        CPolinomial polinomial;

        for (const auto& pair : MyMap_){
            deg = pair.first;
            coefficient = pair.second;
            polinomial.MyMap_[deg] += coefficient;
        }

        for (const auto& pair : other.MyMap_){
            deg = pair.first;
            coefficient = pair.second;
            polinomial.MyMap_[deg] += coefficient;
        }
        return polinomial;
    }

    CPolinomial operator-(const CPolinomial& other) const{
        int deg;
        double coefficient;
        CPolinomial polinomial = *this;
        for (const auto& pair : other.MyMap_){
            deg = pair.first;
            coefficient = pair.second;
            polinomial.MyMap_[deg] -= coefficient;
        }
        return polinomial;
    }


    CPolinomial& operator+=(const CPolinomial& obj){
        auto temp = *this + obj;
        return temp;
    }

    CPolinomial& operator-=(const CPolinomial& obj){
        auto temp = *this - obj;
        return temp;
    }

    CPolinomial operator*(int num) const{
        int deg;
        double coefficient;
        CPolinomial temp;
        for (const auto& pair : MyMap_){
            deg = pair.first;
            coefficient = pair.second;
            temp.MyMap_[deg] = coefficient * num;
        }
        return temp;
    }

    CPolinomial operator*(const CPolinomial& obj) const{
        CPolinomial temp;
        int deg;
        double coefficient;
        for (const auto& pair1 : MyMap_){
            for (const auto& pair2 : obj.MyMap_){
                coefficient = pair1.second * pair2.second;
                deg = pair1.first + pair2.first;
                temp.MyMap_[deg] += coefficient;
            }
        }
        return temp;
    }

    CPolinomial operator/(int number) const{
        CPolinomial temp;
        int deg;
        double coefficient;
        for (const auto& pair : MyMap_){
            deg = pair.first;
            coefficient = pair.second;
            temp.MyMap_[deg] = coefficient / number;
        }
        return temp;
    }

    CPolinomial& operator*=(const CPolinomial& obj){
        auto temp = *this * obj;
        return temp;
    }

    CPolinomial& operator/=(int num){
        auto temp = *this / num;

        return temp;
    }

    float operator[](int deg){
        return MyMap_[deg];
    }

    friend bool operator==(const CPolinomial &left, const CPolinomial &right);
    friend bool operator!=(const CPolinomial &left, const CPolinomial &right);

    friend std::ostream& operator<<(std::ostream& out, const CPolinomial& polynom);
    friend std::istream& operator>>(std::istream& in, CPolinomial& polynom);

};

bool operator==(const CPolinomial& left, const CPolinomial &right) {
    auto it1 = left.MyMap_.begin();
    auto it2 = right.MyMap_.begin();

    while (it1 != left.MyMap_.end()){
        if ((it1->first != it2->first) || (it1->second != it2->second))
            return false;
        it1++; it2++;
    }
    return true;
}

bool operator!=(const CPolinomial &left, const CPolinomial &right) {
    auto it1 = left.MyMap_.begin();
    auto it2 = right.MyMap_.begin();
    while (it1 != left.MyMap_.end()){
        if ((it1->first != it2->first) || (it1->second != it2->second))
            return true;
        it1++; it2++;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const CPolinomial& obj)
{
    auto it_1 = obj.MyMap_.end();
    auto it_2 = obj.MyMap_.begin();

    it_1--;

    if (it_1 -> second != 0)
        out << it_1 -> second << "x^" << it_1 -> first << " ";
    it_1--; it_2--;

    for (it_1; it_1 != it_2; it_1--)
    {
        if (it_1 -> first == 0)
        {
            if (it_1 -> second > 0)
                out << "+ " << it_1->second << " ";
            else if (it_1 -> second < 0)
                out << "- " << -it_1 -> second << " ";
        }

        else if (it_1 -> first < 0)
            out << "- " << -it_1->second << "x^" << it_1->first << " ";
        else if (it_1->first > 0)
            out << "+ " << it_1->second << "x^" << it_1->first << " ";

    }

    out << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, CPolinomial& obj)
{
    int k, deg;
    double coefficient;
    std::cout << "Enter amount: " << std::endl;
    in >> k;
    for (int i = 0; i < k; i++)
    {
        in >> coefficient >> deg;
        obj.MyMap_[deg] = coefficient;
    }
    return in;
}

int main()
{
    CPolinomial polinomial_1({ {2,1}, {3,0} });
    CPolinomial polinomial_2({ {4,3}, {6,5} });
    // CPolinomial polinomial_3;

    std::cout <<  polinomial_1;
    std::cout << -polinomial_1;
    std::cout <<  polinomial_2;
    // std::cout << polinomial_3;



    std::cout << polinomial_1 + polinomial_2;

    return 0;
}