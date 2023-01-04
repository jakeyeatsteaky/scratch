CC = g++

CFLAGS = -g -Wall -Wextra -std=c++17 -pedantic 

allocator: mem_manager/allocator.cpp
	$(CC) $(CFLAGS) -o allocator mem_manager/allocator.cpp
