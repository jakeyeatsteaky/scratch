#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <assert.h>

void addressFun();
void characterArraysAndPointers();
void print(const char* array);
void multiDimensionalArrays();
void printMulti(int (*A)[2][2]); // could also use: void printMulti(int A[][2][2]);
void returnPointersFromFunctions();
int* wrongReturnAdd(int* a, int* b);
int* rightReturnAdd(int* a, int* b);
void dummyFunction(int* a);
void functionPointers();
int square(int* a);
void callbacks();
void A();
void B(void (*ptr)());
char* stringFromUnsigned(unsigned u);
// Write a function that returns the lowercase character of the character passed into the function
char toLowercase(char letter);

int main(int argc, char *argv[])
{
    // addressFun();
    // printf("\n\n------------------ Next Exercise -----------------------\n\n");

    // characterArraysAndPointers();
    // printf("\n\n------------------ Next Exercise -----------------------\n\n");

    // multiDimensionalArrays();
    // printf("\n\n------------------ Next Exercise -----------------------\n\n");

    //returnPointersFromFunctions();
    // printf("\n\n------------------ Next Exercise -----------------------\n\n");

    //functionPointers();
    // printf("\n\n------------------ Next Exercise -----------------------\n\n");
    
    //callbacks();

    char letter = 'G';

    printf("%c\n", letter);
    printf("%d\n", letter);

    printf("%c\n", toLowercase(letter));
    printf("%d\n", toLowercase(letter));


    return 0;



}

void addressFun()
{
    int a;
    int *p;
    a = 5;
    p = &a;

    std::cout << "a: " << a << std::endl;
    std::cout << "&a: " << &a << std::endl;
    std::cout << "p: " << p << std::endl;
    std::cout << "p+1: " << (p + 4) << std::endl; // increments the hex address by 4 bytes
    std::cout << "&p: " << &p << std::endl;
    std::cout << "*p: " << *p << std::endl;

    int var = 10;                         // stored on the stack
    int *pp = (int *)malloc(sizeof(int)); // malloc returns a void*, thus the c-style cast.
                                          // malloc returns the address at which 4 bytes of memory have been allocated.
    pp = &var;
    printf("The memory address of var = %p\n", &var);
    printf("The value of var = %d\n", var);
    printf("The value of pp = %p\n", pp);
    printf("The memory address of pp = %p\n", &pp);
    printf("The dereference of *pp = %d\n\n", *pp);

    int b = 1025;
    int *point = &b;
    printf("The memory address of b = %d\n", point);
    printf("The memory address of point = %d\n", &point);
    printf("The value of b = %d\n", *point);
    printf("size of integer: %d\n", sizeof(int));
    char *p0 = (char *)point;
    printf("The memory address of p0 = %d\n", &p0);
    printf("The value of b = %d\n", *p0);
    printf("The value of b+1 = %d\n", *(p0 + 1));
}

void characterArraysAndPointers()
{
    // char buffers for strings need to be string_length + 1 for \0 character
    char string[20];
    string[0] = 'J';
    string[1] = 'A';
    string[2] = 'K';
    string[3] = 'E';
    string[4] = '\0';
    printf("%s\n", string);

    char string2[] = "JAKEY";  // string literal has an implicit null terminator.  using string literals, size can be implicit
    for(int i = 0; i < 6; i++)
    {
        printf("\n%c",string2[i]);
    }

    printf("\n Size of string:  %d\t Length of string:  %d", sizeof(string), strlen(string));
    printf("\n Size of string2: %d\t Length of string2: %d", sizeof(string2), strlen(string2));
    printf("\n\nEven though string is terminated at 5 characters, its size is still relative to the buffer created for it\nHowever, its length is accurate to the number of characters in the string.\nSize refers to memory allocated for this particular object.  Length is more specific and refers to (general) string lengths\n");

    char* p_string;
    p_string = string;  // this is valid syntax and compiler will assume the pointer to string starts at the first value of string
    printf("\n%c%c%c%c\n", *p_string, *(p_string+1), *(p_string+2), *(p_string+3));

     
    print(string);              // A C Array will always be passed by reference to a function. 

    //char* name = "JakeJake";    // Setting a character pointer to a string literal has an implicit const.  This is an immutable string (valid only in C, not C++)
    //print(name);
    

}

void print(const char* array) 
{
    printf("Calling Print() function. . .\t");
    int i = 0;
    while(array[i] != '\0')
    {
        printf("%c", array[i]);
        i++;
    }

    printf("\n");
}

void multiDimensionalArrays()
{
    int A[3][2][2] = {
        { {1,2}, {3,4} },
        { {5,6}, {7,8} },
        { {9,10}, {11,12} }
    };
    int B[2][3] = {{133,2,3}, {4,5,6}};              // The stride for this array would be 12 bytes (each index has a 1-D array with3 integers)       
    int (*p)[3] = B;                                        // p is a pointer to a 1D array with 3 integers
 // int* p = B;                                             // invalid syntax because p is just an integer pointer, but B represents the address of a 1D array with 3 int.

    printf("\nAddress of B[0][0]:\t\t %#X", &B);
    printf("\nAddress of p (B[0][0]):\t\t %#X", p);
    printf("\nAddress of p (B[0][0]):\t\t %#X", p[0]);      // Expecting same as above
    printf("\nAddress of B[0][1]:\t\t %#X", &B[0][1]);      // Expecting 4 byte difference from above 
    p++;
    printf("\nAddress of B[1][0]:\t\t %#X", p);             // Expecting a 12 byte difference from B
    printf("\nAddress of B[1][1]:\t\t %#X", &B[1][1]);      // Expecting 4 byte increase from address p
    printf("\n %d\n", **B);      

    printMulti(A);
}

void printMulti(int (*A)[2][2])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                printf("%d ", A[i][j][k]);
            }
        }
    }
}

void returnPointersFromFunctions()
{
    // Using a pointer as the return value from a function has to be allocated from the heap or global
    int a = 4, b = 6;
    int* res = wrongReturnAdd(&a, &b);
    int wrong = *res;
    printf("Using wrongReturnAdd, you might get lucky\nwrongReturnAdd: %d\n", wrong);
    
    printf("\ncalling another function on the stack which might overwrite the memory location will result in this\n");
    int* res2 = wrongReturnAdd(&a, &b);
    int wrong2 = *res2;
    dummyFunction(&wrong2);
    printf("wrongReturnAdd: %d", wrong2);

    printf("\n\nA better way to return a function is to allocate it to a global variable or to the heap\n");
    int* right = rightReturnAdd(&a, &b);
    printf("rightReturnAdd: %d\n", *right);
    
}

int* wrongReturnAdd(int* a, int* b)
{
    int num = (*a) + (*b);
    int* res = &num;
    return res;
}

int* rightReturnAdd(int* a, int* b)
{
    int* result = (int*)malloc(sizeof(int));
    int num = (*a) + (*b);
    result = &num;
    return result;
}

void dummyFunction(int* a)
{
    // It wasn't overriding the memory location, so I'm just changing it to look like junk.  regardless, the function working after it's memory location has technically been freed (since the scope of the called function has ended) is not guaranteed.
    *a = 123123123;
}

int square(int* a)
{
    return (*a)*(*a);
}

void functionPointers()
{
    int c = 0; 
    int a = 3;
    int (*funcPtr)(int*);       // Function pointer notation: dataType (*pointername)(argument list of data types)
    funcPtr = &square;          // Function pointer = the address of the function instruction set, can also just used the function name without &
    c = (*funcPtr)(&a);          // dereference the function pointer to call it, with argument list in parenthese
    printf("functionPointer: %d\n", c);
    
}

void callbacks()
{
    void (*p)() = A;            // Create the function pointer
    B(p);                       // Pass function pointer as argument to B
    printf("--------------------------------\n");
    B(A);                       // This is the same syntax because the name of a function is the same as the pointer to it's instruction

}

void A()        // A is a callback function.  When a reference is passed to a function, that reference is known as the callback function
{
    printf("Hello from A\n");
}

void B(void (*ptr)())
{
    ptr();
}


char* stringFromUnsigned(unsigned u)
{
    // Not the best design, this will allocate up to 5 characters (since unsigned 32 bit number can be up to 65,535), and uses the memory location of this static variable as the location for the return char

    static char* stringDigits = "?????"; //5 chars + '\0'
    char* pch;

    assert(u <= 65535);

    // Store the digits from u into stringDigits from back to front
    pch = &stringDigits[5]; // where the \0 char is
    assert(*pch == '\0');

    do
    {
        *--pch = (u % 10) + '0';
    } while (u /= 10 > 0);

    return pch;
}

char toLowercase(char letter)
{
    // Limit this to being uppercase letters only;
    assert(letter >= 65 && letter <= 91);

    return letter + 32;
}
