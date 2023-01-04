#include <memory>
#include <iostream>
#include <assert.h>

template <typename T>
struct ListNode
{
    T data;
    std::shared_ptr<ListNode<T>> next;

    ListNode<T>(T value): data(value), next(nullptr) {};
    ListNode<T>(){};
};

typedef std::shared_ptr<ListNode<int>> ListNode_pi;

void push_back(std::shared_ptr<ListNode<int>> list, int value);
void push_list(std::shared_ptr<ListNode<int>> newlist, std::shared_ptr<ListNode<int>> listtopush);
int sizeOf(std::shared_ptr<ListNode<int>> list);
ListNode_pi search(ListNode_pi list, int key);
std::shared_ptr<ListNode<int>> deleteNode(std::shared_ptr<ListNode<int>> list, int key);
std::shared_ptr<ListNode<int>> deleteIndex(std::shared_ptr<ListNode<int>> list, int index);
std::shared_ptr<ListNode<int>> getIndexNode(std::shared_ptr<ListNode<int>> list, int index);
int getIndexValue(std::shared_ptr<ListNode<int>> list, int index);
void printNodes(std::shared_ptr<ListNode<int>> list);

void append(std::shared_ptr<ListNode<int>> *node, std::shared_ptr<ListNode<int>> *tail);
std::shared_ptr<ListNode<int>> mergeSortedLists(ListNode_pi list1, ListNode_pi list2);

bool doesItCycle(std::shared_ptr<ListNode<int>> list);
std::shared_ptr<ListNode<int>> doesItCycleNode(std::shared_ptr<ListNode<int>> list);

std::shared_ptr<ListNode<int>> sortedMerge(std::shared_ptr<ListNode<int>> list1, std::shared_ptr<ListNode<int>> list2);

int main(int argc, char** argv)
{
    std::shared_ptr<ListNode<int>> list1(new ListNode<int>(1));
    std::shared_ptr<ListNode<int>> list2(new ListNode<int>(1));
    std::shared_ptr<ListNode<int>> newList;

    push_back(list1, 2);
    push_back(list1, 2);
    push_back(list1, 4);
    push_back(list1, 7);
    push_back(list1, 10);

    push_back(list2, 3);
    push_back(list2, 4);
    push_back(list2, 5);
    push_back(list2, 9);


    printNodes(list1);
    printNodes(list2);

    newList = sortedMerge(list1, list2);
    printNodes(newList);

    return 0;
}


std::shared_ptr<ListNode<int>> sortedMerge(std::shared_ptr<ListNode<int>> list1, std::shared_ptr<ListNode<int>> list2)
{
    std::shared_ptr<ListNode<int>> newNode(new ListNode<int>());
    while(list1 && list2)
    {
        int data;
        if(list1->data < list2->data)
        {
            data = list1->data;
            list1 = list1->next;
        }
        else 
        {
            data = list2->data;
            list2 = list2->next;
        }
        push_back(newNode, data);

    }

    if(list1)
    {
        push_list(newNode, list1);
    }

    if(list2)
    {
        push_list(newNode, list2);
    }

    return newNode->next;
}

void push_list(std::shared_ptr<ListNode<int>> newlist, std::shared_ptr<ListNode<int>> listtopush)
{
    std::shared_ptr<ListNode<int>> current = listtopush;
    while(current->next != nullptr)
    {
        push_back(newlist, current->data);
        current = current->next;
    }
    push_back(newlist, current->data);
}

void push_back(ListNode_pi list, int value)
{
    ListNode_pi current = list;
    while(current->next)
    {
        current = current->next;
    }

    ListNode_pi newNode(new ListNode<int>(value));

    current->next = newNode;

}

int sizeOf(std::shared_ptr<ListNode<int>> list)
{
    int count = 0;
    while(list)
    {
        count++;
        list = list->next;
    }

    return count;
}

ListNode_pi search(ListNode_pi list, int key)
{
    std::shared_ptr<ListNode<int>> current = list;

    while(current && current->data != key)
    {
        current = current->next;
    }
    return current;
}

std::shared_ptr<ListNode<int>> deleteNode(std::shared_ptr<ListNode<int>> list, int key)
{
    std::shared_ptr<ListNode<int>> temp = list;
    std::shared_ptr<ListNode<int>> prev = nullptr;
    if(list->data == key)
    {
        temp = temp->next;
        list->next = nullptr;
        return temp;
    }
    while(temp)
    {
        prev = temp;

        if(temp->data == key)
        {
            prev->next = temp->next;
            temp->next = nullptr;
            return list;
        }

        temp = temp->next;
    }

    std::cout << "Key not found in list" << std::endl;
    return list;

}

void printNodes(std::shared_ptr<ListNode<int>> list)
{
    std::shared_ptr<ListNode<int>> current = list;

    while(current)
    {
        std::cout << current->data << std::endl;
        current = current->next;
    }
    std::cout << "---------------------\n";
}

std::shared_ptr<ListNode<int>> deleteIndex(std::shared_ptr<ListNode<int>> list, int index)
{
    assert(index < sizeOf(list));
    std::shared_ptr<ListNode<int>> prev = getIndexNode(list, index-1);
    std::shared_ptr<ListNode<int>> nodeToDelete = getIndexNode(list, index);

    prev->next = nodeToDelete->next;
    nodeToDelete->next = nullptr;

    return list;
}

std::shared_ptr<ListNode<int>> getIndexNode(std::shared_ptr<ListNode<int>> list, int index)
{
    int count = 0;
    assert(count < sizeOf(list));

    while(count != index)
    {
        list = list->next;
        count++;
    }

    return list;
}

int getIndexValue(std::shared_ptr<ListNode<int>> list, int index)
{
    int count = 0;
    assert(count < sizeOf(list));    

    while(count != index)
    {
        list = list->next;
        count++;
    }

    return list->data;
}

std::shared_ptr<ListNode<int>> mergeSortedLists(ListNode_pi list1, ListNode_pi list2)
{
    std::shared_ptr<ListNode<int>> dummy_head(new ListNode<int>());
    std::shared_ptr<ListNode<int>> tail = dummy_head;

    while(list1 && list2)
    {
        append(list1->data <= list2->data ? &list1 : &list2, &tail);
    }

    tail->next = list1 ? list1 : list2;
    return dummy_head->next;
}

void append(std::shared_ptr<ListNode<int>> *node, std::shared_ptr<ListNode<int>> *tail)
{   (*tail)->next = *node;
    *tail = *node;
    *node = (*node)->next;
}

bool doesItCycle(std::shared_ptr<ListNode<int>> list)
{
    std::shared_ptr<ListNode<int>> slowPtr = list;
    std::shared_ptr<ListNode<int>> fastPtr = list;
    while (slowPtr && fastPtr)
    {
        if(slowPtr == fastPtr)
            return true;

        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        
    }
    
    return false;
}

std::shared_ptr<ListNode<int>> doesItCycleNode(std::shared_ptr<ListNode<int>> list)
{
    std::shared_ptr<ListNode<int>> slowPtr = list;
    std::shared_ptr<ListNode<int>> fastPtr = list;
    while (slowPtr && fastPtr)
    {
        if(slowPtr == fastPtr)
            return slowPtr;

        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        
    }
    
    return NULL;

}