#include <iostream>

struct Node
{
    int value;
    Node* next;
};

Node* createNode(int value);
Node* addNode(Node* head, int value);
Node* reverse(Node* head);
void printNodes(Node* head);
int sum(Node* head);

int main(int argc, char* argv[])
{
    printf("%c, %c, %c, %c\n", argv[0], argv[1], argv[2], argv[3]);
    int *a = (int*)argv[0];
    int *b = (int*)argv[1];
    int *c = (int*)argv[2];
    int *d = (int*)argv[3];

    printf("%d, %d, %d, %d\n", *a, *b, *c, *d);

    Node* head = createNode(10);
    addNode(head, *a);
    addNode(head, *b);
    addNode(head, *c);
    addNode(head, *d);

    printNodes(head);
    printf("-------------------------------\n");
    head = reverse(head);
    printNodes(head);
    printf("-------------------------------\n");
    printf("%d\n", sum(head));
   
    return 0;
}


Node* createNode(int value)
{
    Node* newNode;
    newNode = (Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

Node* addNode(Node* head, int value)
{
    Node* newNode;
    newNode = (Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    Node* current = head;

    while(current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = nullptr;

    return head;
}

void printNodes(Node* head)
{
    Node* current = head;
    do
    {
        printf("%d\n", current->value);
        current = current->next;
    } while (current->next != nullptr);
    
    printf("%d\n", current->value);

}

Node* reverse(Node* head)
{
    Node* p1 = nullptr;
    Node* p2 = head;
    Node* p3;

    while(p2 != nullptr)
    {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }

    //printNodes(p1);
    return p1;
}

int sum(Node* head)
{
    Node* current = head;
    int sum = 0;
    while(current->next != nullptr)
    {
        sum += current->value;
        current = current->next;
    }
    sum += current->value;
    return sum;
}