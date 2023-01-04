#include <iostream>
#include <vector>
#include <cstdlib>

int binarySearchpp(int target, std::vector<int> array);
int binarySearch(int target, int size, int* array);

int main(int argc, char** argv)
{
    std::cout << (int)'(' + ')' << std::endl;
    std::cout << (int)')' << std::endl;
    std::cout << (int)'[' << std::endl;
    std::cout << (int)']' << std::endl;
    std::cout << (int)'{' << std::endl;
    std::cout << (int)'}' << std::endl;

}


int binarySearchpp(int target, std::vector<int> array)
{
    int left = 0;
    int right = array.size() - 1;
    while(left <= right)
    {
        int midpoint = left + (right - left) / 2;

        if(array[midpoint] < target)        // Target is on the right side of midpoint
            left = midpoint + 1;
        else if (array[midpoint] == target)
            return midpoint;
        else                                // Target is on the left side of midpoint
            right = midpoint - 1;
    }


    
}

int binarySearch(int target, int size, int* array)
{
    int left = 0;
    int right = size - 1; 

    while(left <= right)
    {
        int midpoint = left + (right - left) / 2;

        if(array[midpoint] < target)
            left = midpoint + 1;
        else if(array[midpoint] == target)
            return midpoint;
        else
            right = midpoint - 1;
    }

    return -1;
}