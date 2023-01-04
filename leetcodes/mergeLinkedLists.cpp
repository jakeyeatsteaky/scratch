#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printNode(ListNode* head);

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

void append(ListNode **lesserNode, ListNode **tail);

int main(int argc, char** argv)
{
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    list1->next->next->next = nullptr;
    
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    list2->next->next->next = nullptr;

    printNode(list1);
    printNode(list2);

    list1 = mergeTwoLists(list1, list2);
    printNode(list1);
    printNode(list2);




    return 0;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode* dummyHead = new ListNode();
    ListNode* tail = dummyHead;

    while(list1 && list2)
    {
        append(list1->val <= list2->val ? &list1 : &list2, &tail);
    }

    if(list1)
        tail->next = list1;
    else   
        tail->next = list2;

    return dummyHead->next;
}

void printNode(ListNode* head)
{
    ListNode* current = head;
    while(current != nullptr)
    {
        std::cout << current->val << std::endl;
        current = current->next;
    }
    std::cout << "-----------------\n";
}

void append(ListNode **lesserNode, ListNode **tail)
{
    (*tail)->next = *(lesserNode);
    *(tail) = *(lesserNode);
    *(lesserNode) = (*lesserNode)->next;
}