#include <iostream>
#include <set>
#include <unordered_map>
#include <stack>
#include <vector>



struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    bool visited;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

typedef std::pair<TreeNode*,bool> pair;

void printTree(TreeNode* root);

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q);
void lcaHelper(TreeNode* root, TreeNode* find, std::unordered_map<TreeNode*,int>* map);

std::vector<std::vector<int>> rotate(std::vector<std::vector<int>>& matrix);

int main(int argc, char** argv)
{
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    std::vector<std::vector<int>> vector;
    vector.push_back({1,2,3});
    vector.push_back({4,5,6});
    vector.push_back({7,8,9});

    for(int i = 0; i < vector.size(); i++){
        for(int j = 0; j <vector.size(); j++){
            std::cout << vector[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::vector<std::vector<int>> newVBector = rotate(vector);

    for(int i = 0; i < newVBector.size(); i++){
        for(int j = 0; j <newVBector.size(); j++){
            std::cout << newVBector[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}
std::vector<std::vector<int>> rotate(std::vector<std::vector<int>>& matrix) {
        std::vector<int> tempVec;
        std::vector<std::vector<int>> illegalVector;
        for(int col = 0; col < matrix.size(); col++){
            std::vector<int> temp;
            
            for(int row = matrix.size()-1; row >= 0; row--){
                temp.push_back(matrix[row][col]);
            }
            illegalVector.push_back(temp);
        }
        return illegalVector;
}

void lcaHelper(TreeNode* root, TreeNode* find, std::unordered_map<TreeNode*,int>* map)
{
    TreeNode* current = root;
    (*map)[current]++;
    if(!current->left && !current->right)
        return;
    if(current == find)
        return;

    if(current->left)
        lcaHelper(current->left, find, map);
    if(current->right)
        lcaHelper(current->right, find, map);


}

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root->val >= p->val && root->val >= q->val)
        lca(root->left, p, q);
    else if (root->val < p->val && root->val < q->val)
        lca(root->right, p,q);
    else
        return root;
}



void printTree(TreeNode* root)
{
    TreeNode* current = root;
    
    if(!current->left && !current->right)
    {
        std::cout << current->val << " ";
        return;
    }

    if(current->left)
        printTree(current->left);

    std::cout << current->val << " ";

    if(current->right)
        printTree(current->right);


}

