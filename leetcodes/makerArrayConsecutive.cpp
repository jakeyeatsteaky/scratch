#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> statues);

int main(int argc, char** argv)
{
    std::vector<int> statues = {6,2,3,8};
    solution(statues);
    return 0;
}


int solution(std::vector<int> statues){
    std::sort(statues.begin(), statues.end());
    int minStatues = 0;
    int i = 0;
    while(i < statues.size()-1){
        if(statues[i] + 1 == statues[i+1])
            i++;
        else{
            minStatues++;
            statues[i] = statues[i] + 1;
        }
    }
    return minStatues;
}