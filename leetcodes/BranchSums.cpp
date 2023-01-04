#include <iostream>
#include <vector>

using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

vector<int> branchSums(BinaryTree *root) {
    std::vector<int> sums;
    calculateBranchSums(root, 0, sums);
    return sums;
}

void calculateBranchSums(BinaryTree* node, int runningSum, std::vector<int> sumList)
{
    if (node == nullptr)
        return;
    int newRunningSum = runningSum + node->value;
    //if leaf, add running sum to the vector;
    if(node->left == nullptr && node->right == nullptr)
    {
        sumList.push_back(newRunningSum);
        return;
    }
    calculateBranchSums(node->left, newRunningSum, sumList);
    calculateBranchSums(node->right, newRunningSum, sumList);  
}

int main(int argc, char** argvs)
{
    BinaryTree* tree = new BinaryTree(1);
    tree->left = new BinaryTree(2);
    tree->right = new BinaryTree(3);
    tree->left->left = new BinaryTree(4);
    tree->left->right = new BinaryTree(5);
    tree->left->left->left = new BinaryTree(8);
    tree->left->left->right = new BinaryTree(9);
    tree->left->right->left = new BinaryTree(10);
    tree->right->left = new BinaryTree(6);
    tree->right->right = new BinaryTree(7);

    std::vector<int> vec;

    vec = branchSums(tree);


    return 0;
}