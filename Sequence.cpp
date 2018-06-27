#include "Sequence.h"

Sequence::Sequence(string filename)
{
	std::ifstream ifs;
	ifs.open(filename);
	if (!ifs.is_open())
	{
		std::cerr << "Can't open file!" << filename << std::endl;
		exit(0);
	}
	char c = ifs.get();

	_a = 0;
	_t = 0;
	_c = 0;
	_g = 0;
	int i = 0;
	while (c != EOF)
	{
		switch (c)
		{
		case 'A':
			_a++;
			data += 'A';
			break;
		case 'T':
			_t++;
			data += 'T';
			break;
		case 'C':
			_c++;
			data += 'C';
			break;
		case 'G':
			_g++;
			data += 'G';
			break;
		default:
			break;
		}
		c = ifs.get();
	}

	if (data.size() != _a + _t + _c + _g)
	{
		std::cerr << "ERROR in Reading" << std::endl;
	}
}

int Sequence::length()
{
	return data.size();
}

int Sequence::numberOf(char base)
{
	switch (base)
	{
	case 'A':
	case 'a':
		return _a;
		break;
	case 'T':
	case 't':
		return _t;
		break;
	case 'C':
	case 'c':
		return _c;
		break;
	case 'G':
	case 'g':
		return _g;
		break;
	default:
		std::cerr << "illegal base" << std::endl;
		break;
	}
}

string Sequence::longestConsecutive()
{
	string rt;
	int length = data.size();
	char start = 0;
	int maxlength = 1;
	int l = 1;

	for (int i = 1; i < length; ++i)
	{
		if (data[i] == data[i - 1])
		{
			l++;
			if (l > maxlength)
			{
				start = data[i];
				maxlength = l;
			}
		}
		else
		{
			l = 1;
		}
	}

	rt.assign(maxlength, start);
	
	return rt;
}

string Sequence::longestRepeated()
{
	
}

