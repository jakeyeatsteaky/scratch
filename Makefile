CC = g++

CFLAGS = -g -Wall -Wextra -std=c++17 -pedantic 

allocator: allocator.cpp
	$(CC) $(CFLAGS) -o allocator allocator.cpp
