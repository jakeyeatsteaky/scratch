#include <stdio.h>
#include <iostream>
#include <assert.h>

#define CAPACITY 40

char heap[CAPACITY] = {0};
size_t heap_size = 0;


void* heap_alloc(size_t size)
{
    assert(heap_size + size <= CAPACITY);

    void* result = heap + heap_size;
    heap_size += size;
    return result;
}


int main(int argc, char** argv)
{
    //assert(false && "TODO: figure out reinterpret cast for making these cases work");

    char* root = reinterpret_cast<char*>(heap_alloc(26));

    for(int i = 0; i < 26; ++i){
        root[i] = i + 'A';

    }

    int* rootint = reinterpret_cast<int*>(heap_alloc(10));
    for(int i = 0; i < 10; ++i){
       rootint[i] = i*10; 
    } 

}
