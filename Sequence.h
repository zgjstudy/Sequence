#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>

using std::string;

class Sequence
{
private:
	int _a;
	int _t;
	int _c;
	int _g;
	std::string data;

public:
	Sequence(string filename);

	int length();

	int numberOf(char base);

	string longestConsecutive();

	string longestRepeated();
};

#endif // SEQUENCE_H~~~