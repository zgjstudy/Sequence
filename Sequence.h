#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <fstream>

using std::string;

class Sequence
{
private:
	int _a;
	int _t;
	int _c;
	int _g;
	int data[100000];
	enum DATANB
	{
		A = 1,
		T = 2,
		C = 3,
		G = 4,
	};

public:
	Sequence(string filename);

	int length();

	int numberOf(char base);

	string longestConsecutive();

	string longestRepeated();
};

#endif // SEQUENCE_H~~~


