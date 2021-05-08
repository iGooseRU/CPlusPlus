#include <iostream>
using namespace std;

class CRingBuffer {
private:
    int* buffer_;
    int head_;       // index of the future value
    int tail_;       // index of the older inserted value, except if empty / head_ == index
    int length_;


public:

    CRingBuffer(int length);
    void push_back(int data);
    void push_front(int data);
    void print() const;

};

// The buffer_ is initialized empty, head_ == tail_
// I can initialize the indexes by any other valid
// value, this is not relevant
CRingBuffer::CRingBuffer(int length)
    : head_(0)
    , tail_(0) {
    length_ = length;
    buffer_ = new int [length];
}

// push_back a new value,
void CRingBuffer::push_back(int data){
    buffer_[head_] = data;
    head_ = (head_ + 1) % length_;

    if (head_ == tail_)
        tail_ = (tail_ + 1) % length_;
}

void CRingBuffer::push_front(int data){

}

// print the content and indexes
void CRingBuffer::print() const {

    /*for (int p = tail_; p != head_; p = (p + 1) % length_)
        cout << buffer_[p] << ' ';*/

    for (int i = 0; i < length_; i++){
        std::cout << buffer_[i] << " ";
    }
    cout << " (head_= " << head_ << ", tail_ = " << tail_ << ')' << endl;
}

int main()
{
    CRingBuffer test(7);

    test.print();

    test.push_back(1);
    test.print();

    test.push_back(2);
    test.print();

    test.push_back(3);
    test.print();

    test.push_back(4);
    test.print();

    test.push_back(5);
    test.print();

    test.push_back(6);
    test.print();

    test.push_back(7);
    test.print();

    test.push_back(8);
    test.print();

    test.push_back(9);
    test.print();

    return 0;
}