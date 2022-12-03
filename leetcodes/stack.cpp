#include <iostream>
#include <assert.h>

template <typename T>
struct Stack
{
    Stack(): sp(&stack[0]){}
    ~Stack() { delete sp; delete[] stack;}

    T    stack[512];    // an array with 512 spots, 
    T*   sp;            // points to the start of the next highest location on the stack 
    T    pop();
    void push(T value);
    T    top();
    bool empty();
    void clear();
};

int main(int argc, char** argvs)
{
    Stack<int>* stk = new Stack<int>();

    std::cout << &stk->stack << std::endl;
    std::cout << stk->sp << std::endl;
    std::cout << stk->stack[0] << std::endl;
    std::cout << "Empty: " << std::boolalpha << stk->empty() << std::endl;
    std::cout << std::endl;
    stk->push(10);
    stk->push(20);
    stk->push(30);
    stk->push(40);
    stk->push(50);
    std::cout << &stk->stack << std::endl;
    std::cout << stk->sp << std::endl;
    std::cout << stk->stack[0] << std::endl;
    std::cout << "Empty: " << std::boolalpha << stk->empty() << std::endl;
    std::cout << std::endl;
    std::cout << stk->top() <<std::endl;
    std::cout << stk->pop() << std::endl;
    std::cout << stk->top() <<std::endl;
    std::cout << std::endl;
    stk->clear();
    return 0;
}

template <typename T>
void Stack<T>::push(T value)
{
    *sp = value;
    sp++;
}

template <typename T>
T Stack<T>::pop()
{
    assert(!empty());
    T retVal;
    sp--;
    retVal = *sp;
    *sp = 0xA3A3A3A3;

    return retVal;
}

template <typename T>
T Stack<T>::top()
{
    T retVal;
    sp--;
    retVal = *sp;
    sp++;

    return retVal;
}

template <typename T>
bool Stack<T>::empty()
{
    return(stack == sp);
}

template <typename T>
void Stack<T>::clear()
{
    while ((int*)&stack != sp)
    {
       std::cout << pop() << ": cleared from stack" << std::endl;
    }

    std::cout << &stack << std::endl;
    std::cout << sp << std::endl;
}