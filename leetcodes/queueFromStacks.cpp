#include <iostream>
#include <stack>

class MyQueue {
public:
    std::stack<int> stack1;
    std::stack<int> stack2;
    MyQueue() {
 
    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int popVal = stack2.top();
        stack2.pop();
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return popVal;
    }
    
    int peek() {
        while(stack1.size() > 1){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int peekVal = stack1.top();
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return peekVal;
    }
    
    bool empty() {
        return stack1.empty();
    }
};

int main(int argc, char** argv){
    MyQueue* queue = new MyQueue();

    queue->push(1);
    queue->push(2);
    std::cout << queue->peek() << std::endl;
    std::cout << queue->pop() << std::endl;
    std::cout << std::boolalpha << queue->empty() << std::endl;
}