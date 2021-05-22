#include <iostream>
#include <exception>
using namespace std;

class CRingBuffer {

private:
    int* buffer_;
    int head_;
    int tail_;
    int capacity_;
    int size_;


public:
    explicit CRingBuffer(int capacity);
    int* shiftRight(int data);
    void pushBack(int data);
    void pushFront(int data);
    int popFront();
    int popBack();
    int getFromHead();
    int getFromTail();
    void setHead(int data);
    void setTail(int data);
    void print() const;
    void setCapacity(int newCapacity);
    int* del(int newCapacity);


    int operator[] (int index){
        return buffer_[index];
    }
};


CRingBuffer::CRingBuffer(int capacity)
    : head_(0)
    , tail_(0)
    , size_(0){
    capacity_ = capacity;
    buffer_ = new int [capacity] {};
}

int* CRingBuffer::shiftRight(int data){
    int* newBuffer = new int [capacity_] {};
    newBuffer[0] = data;

    for(int i = 1; i < capacity_; i++){
        newBuffer[i] = buffer_[i - 1];
    }

    delete []buffer_;
    return newBuffer;

}

// pushBack a new value,
void CRingBuffer::pushBack(int data){
    buffer_[head_] = data;
    head_ = (head_ + 1) % capacity_;

    if (head_ == tail_)
        tail_ = (tail_ + 1) % capacity_;

    size_++;
    if (size_ > capacity_)
            size_ = capacity_;
}

void CRingBuffer::pushFront(int data){
    buffer_ = shiftRight(data);
    tail_ = (tail_ + 1) % capacity_;

    size_++;

    if (size_ > capacity_)
        size_ = capacity_;
}

int CRingBuffer::popFront(){
    int temp = buffer_[head_];
    buffer_[head_] = 0;
    head_ = (head_ + 1) % capacity_;
    size_--;
    if (size_ < 0)
         size_ = 0;

    return temp;
}

int CRingBuffer::popBack(){
    int temp = buffer_[tail_];
    buffer_[tail_] = 0;
    tail_ = (tail_ - 1) % capacity_;

    size_--;
    if (size_ < 0)
          size_ = 0;

    return temp;
}

void CRingBuffer::setCapacity(int newCapacity){

    buffer_ = del(newCapacity);
    capacity_ = newCapacity;
}

int* CRingBuffer::del(int newCapacity){
    int* newBuffer = new int[newCapacity] {};

    if (newCapacity <= capacity_) {
        for (int i = 0; i < newCapacity; i++) {
            newBuffer[i] = buffer_[i];
        }
    } else {
        for (int i = 0; i < capacity_; i++) {
            newBuffer[i] = buffer_[i];
        }
    }

    delete[] buffer_;
    return newBuffer;
}

int CRingBuffer::getFromHead(){
    return (size_ > 0) ? buffer_[head_ - 1] :
                                    throw std::invalid_argument("There isn't head in buffer");
}


int CRingBuffer::getFromTail(){
    return (size_ > 0) ? buffer_[tail_] :
                                    throw std::invalid_argument("There isn't tail in buffer");
}

// only for change data
void CRingBuffer::setHead(int data){
    buffer_[head_ - 1] = data;
}


void CRingBuffer::setTail(int data){
    buffer_[tail_] = data;
}



void CRingBuffer::print() const {

    for (int i = 0; i < capacity_; i++){
        std::cout << buffer_[i] << " ";
    }
    cout << " (head_= " << head_ << ", tail_ = " << tail_ << ')' << endl;
}

int main()
{
    CRingBuffer test(3);

    test.print();

    test.pushBack(1);
    test.print();

    test.pushBack(2);
    test.print();

    test.pushBack(3);
    test.print();

    test.pushBack(4);
    test.print();

    test.setCapacity(8);
    test.print();

    test.setHead(10);
    test.setTail(20);
    test.print();

    std::cout << "The head element is: " << test.getFromHead() << std::endl;
    std::cout << "The tail element is: " << test.getFromTail() << std::endl;

    test.pushFront(2);
    test.popFront();
    test.popBack();

    return 0;
}