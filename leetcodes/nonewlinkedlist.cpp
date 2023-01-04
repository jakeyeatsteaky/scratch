#include <iostream>

struct ListNode
{
    ListNode* next;
    int val;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int value) : val(value), next(nullptr){}
};

void printNodes(ListNode* list);
ListNode addNode(ListNode* list, int val);


int main(int argc, char** argv)
{
    std::cout << sizeof(ListNode) << std::endl;
    ListNode head;
    head.val = 0;
    ListNode list = addNode(&head, 10);
    ListNode list2 = addNode(&head, 20);
    ListNode list3 = addNode(&head, 30);
    ListNode list4 = addNode(&head, 40);

    printNodes(&head);
}

ListNode addNode(ListNode* list, int val)
{
    ListNode newNode;
    ListNode* current = list;
    while(current->next != nullptr){
        current = current->next;
    }
    newNode.val = val;
    current->next = &newNode;
    return newNode;
}

void printNodes(ListNode* list)
{
    ListNode* current = list;
    while(current->next != nullptr){

        std::cout << "Value: " << current->val << std::endl;
        std::cout << "Memory Location: " << current << std::endl;
        std::cout << "Next's Memory Location: " << current->next << std::endl;
        std::cout << "Memory Offset: " << current - current->next << std::endl;
        printf("Memory offset: %x\n", current - current->next);
        std::cout << "------------------------\n";
        current = current->next;
    }
    std::cout << "Value: " << current->val << std::endl;
    std::cout << "Memory Location: " << current << std::endl;
    std::cout << "Next's Memory Location: " << current->next << std::endl;
    std::cout << "------------------------\n";
}