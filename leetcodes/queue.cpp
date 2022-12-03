#include <iostream>

template<typename T>
struct Queue
{
    T queue[512];
    T* qp;

    Queue(): qp(&queue[0]) {}
    ~Queue() {delete[] queue; delete qp;}

    void add(T value)
    {
        *qp = value;
        qp++;
    }

    T pop()
    {
        
    }

};


int main(int argc, char** argv)
{
    Queue<int>* q = new Queue<int>();

    std::cout << &q->queue << std::endl;
    std::cout << q->qp << std::endl;
    std::cout << std::endl;
    q->add(10);
    q->add(20);
    q->add(30);
    q->add(40);
    std::cout << &q->queue << std::endl;
    std::cout << q->qp << std::endl;
    std::cout << q->queue[0] << std::endl;
    std::cout << q->queue[1] << std::endl;
    std::cout << q->queue[2] << std::endl;
    std::cout << q->queue[3] << std::endl;

    return 0;
}