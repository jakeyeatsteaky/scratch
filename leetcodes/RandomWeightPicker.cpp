#include <iostream>
#include <vector>

class Solution {
public:
    Solution(std::vector<int> &w){
        int sum = 0;
        for(int i = 0; i < w.size(); i++)
        {
            sum += w[i];
            prefixSum.push_back(sum);
            std::cout << prefixSum[i] << std::endl;
        }
    }

    std::vector<int> prefixSum;
    
    int pickIndex() {

        int random = rand() / RAND_MAX;
        int target = random * prefixSum[prefixSum.size()-1];

        for(int i = 0; i < prefixSum.size(); i++)
        {
            if(target < prefixSum[i])
                return i;
        }

        return prefixSum.size() -1;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main(int argc, char** argvs)
{
    std::vector<int> w = {1,4,67,89};

    Solution* solution = new Solution(w);

    return 0;
}