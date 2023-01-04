#include <iostream>
struct ListNode {
    int val;
    ListNode* next;

};

class MyLinkedList {
public:

    MyLinkedList() : val(-1), next(nullptr) {}
    MyLinkedList(int value) : val(value), next(nullptr) {}
    
    int get(int index) {
        int currentIndex = 0;
        MyLinkedList* current = this;
        while(current){
            if(currentIndex == index)
                return current->val;
            current = current->next;
            currentIndex++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        // We cant assign the this pointer so here we have to insert the new node AFTER this, and assign the new "head value" to this.
        // the new node will actually be placed after this. 

        int idx1 = this->val;
        this->val = val;
        MyLinkedList* newIdx1 = new MyLinkedList(idx1);
        MyLinkedList* store = this->next;
        this->next = newIdx1;
        newIdx1->next = store;
        if(this->next->val == -1){
            this->next = nullptr;
            delete this->next;
        }
    }
    
    void addAtTail(int val) {
        if(this->val == -1)
        {
            this->val = val;
            return;
        }
        MyLinkedList* newTail = new MyLinkedList(val);
        MyLinkedList* current = this;
        while(current->next){
            current = current->next;
        }
        current->next = newTail;

        
    }
    
    void addAtIndex(int index, int val) {
        int currentIdx = 0;

        if(index == 0){
            this->addAtHead(val);
            return;
        }
        MyLinkedList* current = this;
        while(current){
            if(currentIdx == index-1){
                MyLinkedList* newLink = new MyLinkedList(val);
                if(current->next){
                    MyLinkedList* store = current->next;
                    newLink->next = store;
                }
                current->next = newLink;
                break;
            }
            else{
                current = current->next;
                currentIdx++;
            }
        }

    }
    
    void deleteAtIndex(int index) {
    // Edge cases:  x--delete the first node--x
    //              x--delete in the middle--x
    //              delete the last node
        if(index == 0 && this->next){               // Delete the first node
            this->val = this->next->val;
            MyLinkedList* store = this->next->next;
            MyLinkedList* toBeDeleted = this->next;
            this->next = store;
            delete toBeDeleted;
            return;
        }
        else if(index == 0 && !this->next) {
            this->val = -1;
            return;
        }
        int currentIdx = 1;
        MyLinkedList* prevCurrent = this;
        while(prevCurrent){
            if(currentIdx == index){
                if(!prevCurrent->next)
                    return;
                else if(!prevCurrent->next->next) {
                    MyLinkedList* toBeDeleted = prevCurrent->next;
                    prevCurrent->next = nullptr;
                    delete toBeDeleted;
                    return;
                }
                else if(prevCurrent->next->next){
                    MyLinkedList* store = prevCurrent->next->next; 
                    MyLinkedList* toBeDeleted = prevCurrent->next;
                    prevCurrent->next = store;
                    delete toBeDeleted;
                    return;
                }
            }
            else{
                prevCurrent = prevCurrent->next;
                currentIdx++;
            }
        }
        
    }

    void print(){
        std::cout << "\n-----------------------------\n";
        MyLinkedList* current = this;
        while(current->next){
            std::cout << current->val << std::endl;
            current = current->next;
        }
        std::cout << current->val << std::endl;
        std::cout << "-------------------\n";
    }

    int val;
    MyLinkedList* next;
};

MyLinkedList* baseCase();
void testDelete();

int main(int argc, char** argv){
    MyLinkedList* myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(1);
    myLinkedList->addAtTail(3);
    myLinkedList->addAtIndex(1,2);
    std::cout << myLinkedList->get(1) << std::endl;
    myLinkedList->deleteAtIndex(1);


    
}

MyLinkedList* baseCase(){
    MyLinkedList* test = new MyLinkedList(2);
    test->next = new MyLinkedList(3);
    test->next->next = new MyLinkedList(4);
    test->next->next->next = new MyLinkedList(5);
    test->addAtHead(1);
    test->print();
    return test;
}

void testDelete(){
    // Test Delete in Middle
    MyLinkedList* test = baseCase();
    test->deleteAtIndex(2);
    test->print();
    delete test;
    // Test Delete first
    MyLinkedList* test1 = baseCase();
    test1->deleteAtIndex(0);
    test1->print();
    delete test1;

    // Test Delete last
    MyLinkedList* test2 = baseCase();
    test2->deleteAtIndex(4);
    test2->print();
    delete test2;

    // Test Delete bigger than size
    MyLinkedList* test3 = baseCase();
    test3->deleteAtIndex(5);
    test3->print();
    delete test3;
}