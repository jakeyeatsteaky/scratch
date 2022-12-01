#include <iostream>
#include <queue>
#include <map>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

void printList(ListNode *head);

void printTree(TreeNode *root);

void push_back(ListNode* list, int val);

ListNode *leafList(TreeNode *root, ListNode *list);

int main(int argc, char **argv)
{
    std::map<int,int> map;
    map[1]++;
    map[2]++;
    map[4]++;
    map[3]++;
    map[1]++;
    map[2]--;

    std::map<int,int>::iterator it = map.begin();
    for(; it != map.end(); it++)
    {
        std::cout << it->first << ", " << it->second << std::endl;
    }

    return 0;
}

ListNode *leafList(TreeNode *root, ListNode *list)
{
    if (!root->left && !root->right)
    {
        push_back(list, root->val);
        return list;
    }
    leafList(root->left, list);
    leafList(root->right, list);
    return list;
}

void push_back(ListNode* list, int val)
{
    ListNode* current = list;
    while(current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new ListNode(val);
}

void printList(ListNode *head)
{
    ListNode *current = head;
    while (current->next != nullptr)
    {
        std::cout << current->val << std::endl;
        current = current->next;
    }

    std::cout << current->val << "\n-------------------------------\n";
}

void printTree(TreeNode *root)
{
    std::queue<TreeNode *> queue;

    queue.push(root);
    std::cout << "[";
    while (!queue.empty())
    {
        TreeNode *current = queue.front();
        std::cout << current->val << " ";
        if (current->left)
            queue.push(current->left);
        if (current->right)
            queue.push(current->right);
        queue.pop();
    }
    std::cout << "] \n---------------------\n";
}