#include <iostream>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        std::queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty())
        {
            if(queue.front() == nullptr)
            {    
                queue.pop();
                continue;
            }
            TreeNode* current = queue.front();
            swapChildren(current);
            queue.push(current->left);
            queue.push(current->right);
            queue.pop();

        }

        return root;
    }

    TreeNode* invertTreeRecursively(TreeNode* root)
    {
        if(root == nullptr)
            return root;
        swapChildren(root);
        invertTreeRecursively(root->left);
        invertTreeRecursively(root->right);

        return root;
    }

    void swapChildren(TreeNode* node)
    {
        TreeNode* temp = new TreeNode();
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};

void printTree(TreeNode* root);

int main(int argc, char** argv)
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    
    printTree(root); 

    Solution* solution = new Solution();
    TreeNode* newTree = new TreeNode();
    std::cout << "------------------\n";
    printTree(solution->invertTree(root));
    std::cout << "------------------\n";
    printTree(solution->invertTreeRecursively(root));

    return 0;
}


void printTree(TreeNode* root)
{
    TreeNode* current;
    std::queue<TreeNode*> queue;
    queue.push(root);
    while(!queue.empty())
    {
        current = queue.front();
        std::cout << current->val << std::endl;
        queue.pop();
        if(current->left || current->right)
        {   queue.push(current->left);
            queue.push(current->right);
        }
    }
}