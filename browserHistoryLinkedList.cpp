#include <iostream>

struct ListNode{
    std::string url;
    uint8_t next;
    uint8_t previous;
};

#define HISTORY_CAP 20
ListNode history1[HISTORY_CAP];

class BrowserHistory {
public:
    BrowserHistory(std::string homepage) : historyCount(0) {
        history[0].url = homepage;
        history[0].next = 1;
        history[0].previous = NULL;

        currentPosition = &history[0];
    }
    
    void visit(std::string url) {
        
    }
    
    std::string back(int steps) {
        
    }
    
    std::string forward(int steps) {
        
    }

    ListNode history[HISTORY_CAP];
    uint8_t historyCount;
    ListNode* currentPosition;
};

int main (int argc, char** argv){
    ListNode node;
    history1[9].url = "String 9";
    node.next = 9;

    std::cout << history1[node.next].url << std::endl;
    std::cout << &history1[node.next].url << std::endl;
    std::cout << &history1[node.next] << std::endl;

    std::cout << sizeof(ListNode) << std::endl;
    std::cout << sizeof(std::string) << std::endl;
    std::cout << sizeof(uint8_t) << std::endl;
    std::cout << sizeof(node) << std::endl;
}