#include <iostream>
#include <vector>
#include <string>
#include <deque>

class Node {
public:
    std::string name;
    std::vector<Node *> children;

    Node(std::string str) { name = str; }

    std::vector<std::string> breadthFirstSearch(std::vector<std::string> *array) 
    {
        std::deque<Node*> queue;
        std::vector<std::string> retVec = {};
        queue.push_back(this);
        Node* current;

        while(!queue.empty())
        {
            current = queue.front();
            queue.pop_front();
            retVec.push_back(current->name);
            for(Node* kids : current->children)
            {
                queue.push_back(kids);
            }
        }
    
        return retVec;
    }

    Node *addChild(std::string name) {
        Node *child = new Node(name);
        children.push_back(child);
        return this;
    }
};  

int main(int argc, char** argv)
{

    return 0;
}