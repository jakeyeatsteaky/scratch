#include <iostream>
#include <stack>

class BrowserHistory {
public:
    BrowserHistory(std::string homepage) : m_url(homepage), homepage(homepage){
        std::stack<std::string> history;
        history.push(homepage);
        m_history = history;
        pos = &m_history.top();
    }
    
    void visit(std::string url) {
        if(*pos != m_history.top()){
            while(*pos != m_history.top()){
                m_history.pop();
            }
        }
        m_history.push(url);
        pos = & m_history.top();
    }
    
    std::string back(int steps) {
        std::stack<std::string>* tempStack = &m_history;
        while(*pos != tempStack->top()){
            tempStack->pop();
        }

        if(steps > tempStack->size())
            steps = tempStack->size();
        tempStack = &m_history;
        for(int i = 0; i < steps; i++)
        {
            tempStack->pop();
        }
        if(!m_history.empty())
            pos = &m_history.top();
        else
            *pos = tempStack->top();

        return *pos;
    }
    
    std::string forward(int steps) {
        std::stack<std::string> tempStack = m_history;
        while(*pos != tempStack.top()){
            tempStack.pop();
        }
        int possibleStepsForward = m_history.size() - tempStack.size();
        if(steps > possibleStepsForward)
            steps = possibleStepsForward;
        int pop = possibleStepsForward - steps;
        for(int i = 0; i < pop; i++)
        {
            m_history.pop();
        }
        pos = &m_history.top();

        return *pos;
    }
    std::string homepage;
    std::string m_url;
    std::stack<std::string> m_history;
    std::string* pos;

};

int main(int argc, char** argv)
{
    std::stack<std::string> stack;
    stack.push("string1");
    std::string* position;
    position = &stack.top();
    std::cout << stack.top() << std::endl;
    std::cout << & stack.top() << std::endl;
    std::cout << position << std::endl;
    std::cout << *position << std::endl;
    // BrowserHistory* browser = new BrowserHistory("www.leetcode.com");
    // browser->visit("www.google.com");
    // browser->visit("www.facebook.com");
    // browser->visit("www.youtube.com");
    // browser->back(1);
    // browser->back(1);
    // browser->forward(1);
    // browser->visit("www.linkedin.com");
    // browser->forward(2);
    // browser->back(2);
    // browser->back(7);
    return 0;
}

