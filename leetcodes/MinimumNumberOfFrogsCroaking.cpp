#include <iostream>
#include <string>
#include <unordered_map>

/*
========================================================
LEETCODE: https://leetcode.com/problems/minimum-number-of-frogs-croaking/

You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.

Return the minimum number of different frogs to finish all the croaks in the given string.

A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.

*/
int minNumberOfFrogs(std::string croakOfFrogs);

int main(int argc, char** argvs){

    std::string c = "croakcroak";

    std::cout << minNumberOfFrogs(c) << std::endl;

    
    return 0;
}

int minNumberOfFrogs(std::string croakOfFrogs) {
    int c = 0;
    int r = 0;
    int o = 0;
    int a = 0;
    int k = 0;
    int result = 0;
    int numExpected = 0;
        
    if(croakOfFrogs[0] != 'c')
        return -1;
        
    for(auto &letter : croakOfFrogs)
    {
        if(letter == 'c'){
            c++;
            numExpected++;
        }
        else if(letter == 'r')
            r++;
        else if(letter == 'o')
            o++;
        else if(letter == 'a')
            a++;
        else if(letter == 'k'){
            k++;
            numExpected--;
        }
            
        result = std::max(result, numExpected);
            
        if(c >= r && r >= o && o >= a && a >= k)
            continue;
        else
            return -1;
    }
        
    if(c != r || r != o || o != a || a != k)
        return -1;
    return result;
}

