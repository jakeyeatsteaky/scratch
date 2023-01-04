#include <iostream>
#include <vector>

std::vector<int> quickSort(std::vector<int> array);
void quickSortHelper(std::vector<int> &array, int startIdx, int endIdx);
void swap(int &a, int &b);
void print(std::vector<int> array);

int main(int argc, char** argv)
{
    std::vector<int> array = {8,5,2,9,5,6,3};

    print(array);
    array = quickSort(array);   std::cout << "\n";
    print(array); 
    
    return 0;
}

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

std::vector<int> quickSort(std::vector<int> array)
{
    quickSortHelper(array, 0, array.size()-1);
    return array;
}

void quickSortHelper(std::vector<int> &array, int startIdx, int endIdx)
{
    // check if the array is length 1, in which case it is sorted
    if(endIdx <= startIdx)
        return;

    // initiate variables with pivot always being the first index
    int pivot = startIdx;
    int left = startIdx + 1;
    int right = endIdx;

    while(right >= left)        
    {
        // Check case for right and left pointer swap
        if(array[left] > array[pivot] && array[right] < array[pivot])
            swap(array[right], array[left]);
        
        if(array[left] <= array[pivot])
            left++;
        
        if(array[right] >= array[pivot])
            right--;
    }

    swap(array[pivot], array[right]);

    int sizeLeftSubArray = right - 1 - startIdx;
    int sizeRightSubArray = endIdx - (right + 1);

    bool isLeftSubArraySmaller = sizeLeftSubArray < sizeRightSubArray;

    if(isLeftSubArraySmaller)
    {
        quickSortHelper(array, startIdx, right - 1);
        quickSortHelper(array, right + 1, endIdx);
    }

    else
    {
        quickSortHelper(array, right + 1, endIdx);
        quickSortHelper(array, startIdx, right - 1);
    }
}

void print(std::vector<int> array)
{
    for(int nums : array)
    {
        std::cout << nums <<std::endl;
    }
}