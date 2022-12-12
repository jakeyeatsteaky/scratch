#include <iostream>
#include <map>

class BST
{
public:
    int value;
    BST* left;
    BST* right;

    BST(int val) : value(val), left(nullptr), right(nullptr){}
};

void traverseAndPrint(BST* root);
int findClosestValueInBst(BST* tree, int target);
void helper(BST* tree, int target, std::map<int,int>* map);

int main(int argc, char** argv){
    BST* root = new BST(10);
    root->left = new BST(5);
    root->right = new BST(15);
    root->left->left = new BST(2);
    root->left->right = new BST(5);
    root->left->left->left = new BST(1);
    root->right->right = new BST(22);
    root->right->left = new BST(13);
    root->right->left->right = new BST(14);

    findClosestValueInBst(root, 12);
}

void traverseAndPrint(BST* root){
    if(root->left)
        traverseAndPrint(root->left);
    if(root->right)
        traverseAndPrint(root->right);
    std::cout << root->value << std::endl;
}

int findClosestValueInBst(BST *tree, int target) {
  std::map<int,int> map;
  helper(tree, target, &map);
  std::map<int,int>::iterator it = map.begin();
  int retval = it->first;
  if(retval > -1)
    return it->second;
  return -1;
}

void helper(BST* tree, int target, std::map<int,int>* map){
  if(tree->value == target){
    map->insert(std::pair<int,int>(0, target));
    return;
  }
  if(tree->left && tree->value > target)
    findClosestValueInBst(tree->left, target);
  if(tree->right && tree->value < target)
    findClosestValueInBst(tree->right, target);
  int least = abs(target - tree->value);
  map->insert(std::pair<int,int>(least,tree->value));
}