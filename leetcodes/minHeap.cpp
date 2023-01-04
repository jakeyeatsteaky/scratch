#include <iostream>
#include <vector>

class MinHeap {
public:
  std::vector<int> heap;

  MinHeap(std::vector<int> vector): heap(vector) { /*heap = buildHeap(vector);*/ }

  std::vector<int> buildHeap(std::vector<int> &vector) {
    // 1) Find the lowest parent
    // 2) Sift down for that node
    // 3) continue on for the rest of the parents
    int lastIdx = vector.size() - 1;
    int parentIdx = lastIdx-1/2;
    for(int i = parentIdx; i >=0; i--){
        siftDown(i,lastIdx,vector);
    }
    
    return vector;
  }

  void siftDown(int currentIdx, int endIdx, std::vector<int> &heap) {
    if(currentIdx == endIdx)
        return;
    int leftIdx = currentIdx*2 + 1;
    int rightIdx = leftIdx++;
    if(leftIdx > heap.size()-1)
        return;
    int swapIdx;
    heap[leftIdx] < heap[rightIdx]? swapIdx = leftIdx : swapIdx = rightIdx;

    if(heap[currentIdx] > heap[swapIdx]){
        int temp = heap[currentIdx];
        heap[currentIdx] = heap[swapIdx];
        heap[swapIdx] = temp;
        siftDown(swapIdx, endIdx, heap);
    }
    return;
    
  }

  void siftUp(int currentIdx, std::vector<int> &heap) {
    int parentIdx = (currentIdx - 1) / 2;
    if(heap[parentIdx] > heap[currentIdx]){
        int temp = heap[parentIdx];
        heap[parentIdx] = heap[currentIdx];
        heap[currentIdx] = temp;
        siftUp(parentIdx, heap);
    }
    return;
  }

  int peek() {
    if(!heap.empty())
        return heap[0];
    return -1;
  }

  int remove() {
    int nodeToBePopped = heap[0];
    int lastIdx = heap.size() -1;
    heap[0] = heap[lastIdx];
    heap.pop_back();
    siftDown(0,lastIdx-1,heap);
    return nodeToBePopped;
  }

  void insert(int value) {
    heap.push_back(value);
    int endIdx = heap.size() -1;
    siftUp(endIdx, heap);
  }
};

int main(int argc, char** argv){
    std::vector<int> toBeHeaped = {8,12,23,17,31,30,44,102,18};
    MinHeap* minheap = new MinHeap(toBeHeaped);
    
    minheap->insert(7);
    minheap->remove();
    

}