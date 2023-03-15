#pragma once
//: C04:CppLib.h
// C-like library converted to C++
class Stash {
	int size; // Size of each space
	int quantity; // Number of storage spaces
	int next; // Next empty space
	// Dynamically allocated array of bytes:
	unsigned char* storage;
	// Functions!
	public:
		Stash(int size);
		~Stash();
		int add(const void* element);
		void* fetch(int index);
		int count();
	private:
		void inflate(int increase);
}; ///:~
