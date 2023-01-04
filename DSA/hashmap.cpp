#include <iostream>
#include <list>
#include <cstring>

#define HASHGROUPS 10;
// hashtable to implement a phone book - 905 - Ellie

struct HashTable
{
    static const int hashGroups = HASHGROUPS;
    std::list<std::pair<int, std::string>> table[hashGroups]; // list 1 idx 0. list 2 idx 1 . . .

    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, std::string value);
    void removeItem(int key);
    std::string searchTable(int key);
    void printTable();
};

bool HashTable::isEmpty() const
{
    int sum{};
    for(int i {}; i < hashGroups; i++)
    {
        sum += table[i].size();
    }

    if(!sum)
        return true;
    return false;
}

int HashTable::hashFunction(int key)
{
    return key % hashGroups;    // Ex) Key = 905, output = 5;
}

void HashTable::insertItem(int key, std::string value)
{
    int hashValue = hashFunction(key);
    auto& cell= table[hashValue];
    auto begin_it = begin(cell);
    bool keyExists = false;
    for(; begin_it != end(cell); begin_it++)
    {
        if(begin_it->first == key)
        {
            keyExists = true;
            begin_it->second = value;
            std::cout << "[WARNING] Key exists" << std::endl;
            break;
        }
    }

    if(!keyExists)
        cell.emplace_back(key,value);

    return;
}

void HashTable::removeItem(int key)
{
    int hashValue = hashFunction(key);
    auto& cell= table[hashValue];
    auto begin_it = begin(cell);
    bool keyExists = false;
    for(; begin_it != end(cell); begin_it++)
    {
        if(begin_it->first == key)
        {
            keyExists = true;
            begin_it = cell.erase(begin_it); 
            std::cout << "[INFO] Item Removed" << std::endl;
            break;
        }
    }

    if(!keyExists)
        std::cout << "[WARNING] Item Not Found" << std::endl;
    
    return;
}

void HashTable::printTable()
{
    for(int i{}; i < hashGroups; i++)
    {
        if(table[i].size() == 0) continue;

        auto begin_it = table[i].begin();
        for(; begin_it != table[i].end(); begin_it++)
        {
            std::cout << "[INFO] Key: " << begin_it->first << " Value: " << begin_it->second << std::endl;
        }
    }

    return;
}

int main (int argc, char** argv)
{
    HashTable ht;
    if(ht.isEmpty())
        std::cout << "Hash table is empty." << std::endl;
    
    ht.insertItem(905, "Ellie");
    ht.insertItem(843, "Jake");
    ht.insertItem(124, "Irina");
    ht.insertItem(156, "Roois");
    ht.insertItem(345, "Chickens");
    ht.insertItem(345, "Chickens2");

    ht.printTable();

    ht.removeItem(843);
    ht.removeItem(122);

    if(ht.isEmpty())
        std::cout << "uh oh" << std::endl;
    else
        std::cout << "good job" << std::endl;

    
}