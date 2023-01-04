#include <iostream>

class BST
{
public:
    int value;
    BST* left;
    BST* right;

    BST(int val) : value(val), left(nullptr), right(nullptr){}
};

void traverseAndPrint(BST* root);

int main(int argc, char** argv){
    BST* root = new BST(10);
    root->left = new BST(9);
    root->right = new BST(15);
    root->left->left = new BST(2);
    root->left->right = new BST(5);
    root->left->left->left = new BST(1);
    root->right->right = new BST(22);

    traverseAndPrint(root);
}

void traverseAndPrint(BST* root){
    if(root->left)
        traverseAndPrint(root->left);
    std::cout << root->value << std::endl;
    if(root->right)
        traverseAndPrint(root->right);
}