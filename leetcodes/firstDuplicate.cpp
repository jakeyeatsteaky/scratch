#include <iostream>
#include <vector>
#include <set>
#include <deque>

char solution(std::string s) {
 
       std::set<char> set;
       std::deque<char> queue;
       
       for(char c : s)
       {
           std::set<char>::iterator it = set.find(c);
           
           if(it == set.end())
           {
               set.insert(c);
               queue.push_back(c);
           }
           else if(c == queue.front())
           {
               queue.pop_front();
           }
           else if(c == queue.back())
           {
               queue.pop_back();
           }
       }
       
       std::cout << set.size() << std::endl;
       std::cout << queue.size() << std::endl;
       
       std::set<char>::iterator it = set.find(queue.front());
       
       if(queue.empty())
       {
           return '_';
       }
        
        return queue.front();
        
        
}


int main(int argc, char** argvs)
{
    std::string s = "abcdefghijklmnopqrstuvwxyziflskecznslkjfabe";

    std::cout << solution(s) << std::endl;

    return 0;
}