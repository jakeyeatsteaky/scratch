#include <assert.h>
#include <iostream>
#include <list>
#include <cmath>

struct Node 
{
    Node(int value) : data(value), next(nullptr) {};

    int data;
    Node* next;
};

struct LinkedList
{
    LinkedList(): head(nullptr), tail(nullptr) {};

    Node* head;
    Node* tail;

    void pushBack(int value)
    {
        Node* current = this->head;

        while(current->next != nullptr)
        {
            current = current->next;
        }

        Node* newNode = new Node(value);

        current->next = newNode;

    }

    void print()
    {
        Node* current = head;

        while(current->next != nullptr)
        {
            std::cout << current->data << std::endl;
            current = current->next;
        }

        std::cout << current->data << std::endl;
    }

    int sizeOf()
    {
        int count = 0;
        Node* current = this->head;

        if(current->next == nullptr)
            return count; 
        
        while(current->next != nullptr)
        {
            count++;
            current = current->next;
        }

        count++;
        return count;
    }

    Node* getIdx(int idx)
    {
        int size = this->sizeOf();
        assert(idx < size);

        if(idx == 0)
            return head;

        int pos = 0;
        
        Node* current = this->head;
        while(pos < idx)
        {
           current = current->next;
           pos++; 
        }

        return current;
    }

    void insert(int value, int idxToInsert)
    {
        Node* p1 = this->getIdx(idxToInsert-1);
        Node* p2 = this->getIdx(idxToInsert);

        Node* newNode = new Node(value);
        p1->next = newNode;
        newNode->next = p2;
    }

    void deleteNode(int idx)
    {
        assert(idx < sizeOf());

        Node* prev = getIdx(idx - 1);
        Node* nodeToDelete = getIdx(idx); 

        if(idx == 0)
        {
            head = head->next;
            return;
        }
        
        if(idx == sizeOf() - 1)
        {
            prev->next = nullptr;
            return;
        }   

        prev->next = prev->next->next;
        nodeToDelete->next = nullptr;

        // Edge cases: if nodeToDelete is first node, or last node
    }

    void sortList()
    {
        Node* p1 = head;
        Node* p2 = head->next;
        Node* p3 = head->next->next;

        while(p2 != nullptr && p3 != nullptr)
        {
            if(p2->data < p1->data)
            {
                int temp;
                temp = p2->data;
                p2->data = p1->data;
                p1->data = temp;
            }
            else if(p3 != nullptr)
            {
                if(p3->data < p2->data)
                {
                    int temp;
                    temp = p3->data;
                    p3->data = p2->data;
                    p2->data = temp;
                }
            }

            p1 = p1->next->next;
            p2 = p2->next->next;
            p3 = p3->next->next;
        }
    }

};

LinkedList* merge(LinkedList* list1, LinkedList* list2)
{
    Node* preHead = new Node(INT16_MIN);

    
}



int main(int argc, char** argv)
{
    LinkedList* list = new LinkedList();
    LinkedList* list2 = new LinkedList;

    Node* head = new Node(1);
    Node* head2 = new Node(1);

    list->head = head;
    list2->head = head2;

    list->pushBack(2);
    list->pushBack(4);

    list2->pushBack(3);
    list2->pushBack(4);

    list->print();
    std::cout << "\n";

    list2->print();
    std::cout << "\n";

    LinkedList* newList = merge(list, list2);

    newList->print();

    


    return 0;


}

