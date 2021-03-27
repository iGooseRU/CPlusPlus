#include <iostream>

class CPolynom{
protected:
    int n_, k_;
    double x_;
    double *c_;

public:
    CPolynom(){
        n_ = 1;
        k_ = 1;
        this -> c_ = new double [(n_ - k_) + 1];
        c_[0] = 1;
    }

    CPolynom(int n, int k){
        this -> n_ = n;
        this -> k_ = k;
        this -> c_ = new double [(n - k) + 1];  /// n >= k;
        for (int i = n; i >= k; i--){
            std::cout << "Enter coefficient " << i << ":\n";
            std::cin >> c_[i - k_];
        }
    }

    void show_polynom(){
        for (int i = n_; i >= k_; i--){
            if (i == k_){
                std::cout << "(" << c_[i - k_] << ")*(x^" << i << ")";
            } else
            std::cout << "(" << c_[i - k_] << ")*(x^" << i << ")+";
        }
        std::cout << std::endl;
    }

    CPolynom& operator=(const CPolynom &obj){
        n_ = obj.n_;
        k_ = obj.k_;
        x_ = obj.x_;
        c_ = new double [(n_ - k_) + 1];
        for (int i = obj.n_; i >= obj.k_; i--){
            c_[i - k_] = obj.c_[i - k_];
        }
        return *this;
    }

    friend bool operator==(const CPolynom &left,const CPolynom &right);
    friend bool operator!=(const CPolynom &left,const CPolynom &right);
    friend CPolynom operator+(const CPolynom &left,const CPolynom &right);
    friend CPolynom operator-(const CPolynom &left,const CPolynom &right);
    friend CPolynom operator-(const CPolynom &obj);

};

    bool operator==(const CPolynom &left,const CPolynom &right){
        if(left.k_ == right.k_ &&  left.n_ == right.n_){
            for (int i = left.n_; i >= left.k_; i--){
                if (left.c_[i - left.k_] != right.c_[i - right.k_])
                    return false;
            }
            return true;

        } else return false;

    }

    bool operator!=(const CPolynom &left,const CPolynom &right){
        if(left.k_ == right.k_ &&  left.n_ == right.n_){
            for (int i = left.n_; i >= left.k_; i--){
                if (left.c_[i - left.k_] != right.c_[i - right.k_])
                    return true;
            }
            return false;

        } else return true;
    }

    CPolynom operator-(const CPolynom &obj){
        CPolynom new_object = obj;
        for (int i = obj.n_; i >= obj.k_; i--){
           new_object.c_[i - obj.k_] *= -1;
        }
        return new_object;
    }


int main() {
    CPolynom polynom_1;
    CPolynom polynom_2(100,2);
    polynom_1.show_polynom();
    polynom_2.show_polynom();
    std::cout << (polynom_1 != polynom_2) << std::endl;
    polynom_1 = polynom_2;
    std::cout << (polynom_1 != polynom_2) << std::endl;
    polynom_1.show_polynom();
    polynom_2 = -polynom_2;
    polynom_2.show_polynom();
    return 0;
}
