#include <iostream>
#include <vector>
#include <string>

class Node {
public:
  std::string name;
  std::vector<Node *> children;

  Node(std::string str) { name = str; }

  std::vector<std::string> depthFirstSearch(std::vector<std::string> *array) {
    
    array->push_back(name);

    for(int i = 0; i < children.size(); i++)
    {
        children[i]->depthFirstSearch(array);
    }

    return *array;
  }

  Node *addChild(std::string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};

int main (int argc, char** argvs)
{
    Node* node(new Node("root"));

    node->addChild("A0");
    node->addChild("A1");
    node->addChild("A2");

    node->children[0]->addChild("B00");
    node->children[0]->addChild("B01");
    node->children[1]->addChild("B10");
    node->children[1]->addChild("B11");
    node->children[2]->addChild("B20");

    node->children[0]->children[0]->addChild("C000");

    node->children[2]->children[0]->addChild("C200");

    std::vector<std::string> array;
    node->depthFirstSearch(&array);


    for(std::string &names : array)
    {
        std::cout << names << std::endl;
    }







    return 0;
}
