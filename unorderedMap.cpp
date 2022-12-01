#include <iostream>
#include <unordered_map>
#include <string>

int main(int argc, char** argvs)
{
    std::unordered_map<std::string, int> hashMap;

    hashMap.insert(std::pair<std::string, int>("jake", 100));
    hashMap.insert(std::pair<std::string, int>("irina", 300));
    hashMap.insert(std::pair<std::string, int>("ellie`", 140));
    hashMap.insert(std::pair<std::string, int>("rory", 160));
    hashMap.insert(std::pair<std::string, int>("schwa", 500));

    std::unordered_map<std::string,int>::iterator it = hashMap.begin();

    for(; it != hashMap.end(); it++)
    {
        std::cout << it->first << std::endl;
        std::cout << it->second << std::endl;
        std::cout << "---------\n";
    }
}