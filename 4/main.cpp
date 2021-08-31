#include <iostream>
#include <vector>
#include <array>
#include <cmath>

class CPoint{
public:
    double x;
    double y;
    double module = sqrt(x*x + y*y);

};

bool comparator ( CPoint left,  CPoint right)
{
    return left.module < right.module;
}


    // Возвращает true, если все элементы диапазона удовлетворяют
    // некоторому предикату. Иначе false
    template<typename T, typename P>
    bool all_of (T first, T last, P pred){

        T it = first;

        while (it != last){
            if (!pred(*it)){
                return false;

            }
            ++it;
        }

        return true;
    }

    // Возвращает true, если хотя бы один из элементов диапазона
    // удовлетворяет некоторому предикату. Иначе false
    template<typename T, typename P>
    bool any_of (T first, T last, P pred){

        T it = first;

        while (it != last){
            if (pred(*it))
                return true;

            ++it;
        }
        return false;
    }

    // Возвращает true, если все элементы диапазона не удовлетворяют
    // некоторому предикату. Иначе false
    template<typename T, typename P>
    bool none_of (T first, T last, P pred){

        T it = first;

        while (it != last){
            if (pred(*it))
                return false;
            ++it;
        }
        return true;
    }

    // Возвращает true, если ровно один элемент диапазона удовлетворяет
    // некоторому предикату. Иначе false
    template<typename T, typename P>
    bool one_of(T first, T last, P pred){

        int k = 0;
        T it = first;

        while (++it != last){
            if (pred(*it))
                ++k;

            if (k > 1)
                return false;
        }
        return true;
    }

    // Возвращает true, если все элементы диапазона находятся в
    // отсортированном порядке относительно некоторого критерия
    template <typename T, typename P>
    bool is_sorted(T first, T last, P pred){

        if (first == last)
            return false;

        T it = std::next(first);

        while (it != last){
            if (!pred(*(std::prev(it)), *it))
                return false;
            ++it;
        }
        return true;
    }


    // Возвращает true, если в диапазоне есть элемент, делящий все
    // элементы на удовлетворяющие и не удовлетворяющие некоторому предикату.
    // Иначе false.
    template <typename T, typename P>
    bool is_partitioned(T first, T last, P predicate){

        T it = first;

        while (it != last) {
            if (!predicate(*it))
                break;
            ++it;
        }

        while (it != last) {
            if (predicate(*it))
                return false;
            ++it;
        }
        return true;
    }


    // - находит первый элемент, не равный заданному
    template <typename T, typename P>
    T find_not (T first, T last, P element){

        T it = first;

        while (it != last){
            if (*it != element)
                return it;
            ++it;
        }
        return last;
    }


    // - находит первый элемент, равный заданному, с конца
    template <typename T, typename P>
    T find_backward (T first, T last, P element){

        T it = last;

        while (it != first){
            --it;
            if (*it == element)
                return it;
        }

        if (*first == element)
            return first;

        return last;
    }


    // Возвращает true, если заданная последовательность является
    // палиндромом относительно некоторого условия. Иначе false.
    template <typename T>
    bool is_palindrome(T first, T last){

        if (first == last)
            return true;

        T it_start = first;
        T it_finish = last;
        --it_finish;

        while (it_start != it_finish)
        {
            if (*it_start != *it_finish)
                return false;
            ++it_start;
            if (it_start == it_finish)
                return true;
            --it_finish;
        }
        return true;
}


int main() {

    std::vector<CPoint> pointVec = {{2,5}, {24,1}, {1,2}};
    std::array<int,5> foo = {-1,0,1,2,3};

    for (int i = 0; i <= 5; i++)
        std::cout << foo[i] << " ";
    std::cout << std::endl;

    if (all_of(foo.begin(), foo.end(), [](int i) { return i >= 0; })){
        std::cout << "All elements are >= than 0.\n";
    } else {
        std::cout << "There are some elements < 0\n";
    }

    if (any_of(foo.begin(), foo.end(), [](int i) { return i < 0; })){
        std::cout << "There is element < 0\n";
    } else {
        std::cout << "There are not any elements < 0\n";
    }

    if (is_sorted(pointVec.begin(), pointVec.end(), comparator )){
        std::cout << "All elements in range are sorted\n";
    } else {
        std::cout << "Elements are not sorted\n";
    }

    if (is_palindrome(foo.begin(), foo.end())){
        std::cout << "It is palindrome\n";
    } else {
        std::cout << "It is not palindrome\n";
    }


    return 0;
}
