//: C04:CppLibTest.cpp
//{L} CppLib
// Test of C++ library
#include "Stash3.h"
#include "require.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
	Stash intStash(sizeof(int));
	for (int i = 0; i < 100; i++)
		intStash.add(&i);
	for (int j = 0; j < intStash.count(); j++)
		cout << "intStash.fetch(" << j << ") = "
		<< *(int*)intStash.fetch(j)
		<< endl;
	// Holds 80-character strings:
	const int bufsize=80;
	Stash stringStash(sizeof(char) * bufsize);
	ifstream in("CppLibTest.cpp");
	assure(in, "CppLibTest.cpp");
	string line;
	while (getline(in, line))
		stringStash.add(line.c_str());
	int k = 0;
	char* cp;
	while ((cp = (char*)stringStash.fetch(k++)) != 0)
		cout << "stringStash.fetch(" << k << ") = "
		<< cp << endl;
	
} ///:~
