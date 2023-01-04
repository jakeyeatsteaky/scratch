#include <queue>
#include <iostream>
#define SECONDS 300
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        std::priority_queue<int> maxHeap;

        maxHeap.push(investigator(root));
        if(root->left)
            maxHeap.push(investigator(root));
        if(root->right)
            maxHeap.push(investigator(root->right));

        return maxHeap.top();
    }

    int investigator(TreeNode* node){
        int count = 0;
        TreeNode* leftInvestigator = node;
        TreeNode* rightInvestigator = node;
        while(leftInvestigator){
            leftInvestigator = leftInvestigator->left;
            if(!leftInvestigator)
                break;
            count++;
        }
        while(rightInvestigator){
            rightInvestigator = rightInvestigator->right;
            if(!rightInvestigator)
                break;
            count++;
        }
        return count;
    }

};

int main(int argc, char** argv){
    Solution* solution = new Solution();

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(1);

    std::cout << solution->diameterOfBinaryTree(root) << std::endl;

}