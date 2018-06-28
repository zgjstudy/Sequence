#include "Sequence.h"

int pstrcmp(const void* p1, const void* p2)
{
	return strcmp(*(const char**)p1, *(const char**)p2);
}

int comlen(char* p1, char* p2)
{
	int i = 0;
	while (p1[i] == p2[i++]);
	return --i;
}

Sequence::Sequence(string filename)
{
	std::ifstream ifs;
	ifs.open(filename.data());
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
	char start = data[0];
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
	string rt;
	int len = data.size();
	char* c = new char[len + 100];
	char** a = new char*[len + 100];
	int maxlen = -1, maxi = 0;

	int i = 0;
	while (i < len)
	{
		a[i] = &c[i];
		c[i] = data[i++];
	}
	c[i] = 0;
	qsort(a, i, sizeof(char*), pstrcmp);

	for (int i = 0; i < len - 1; ++i)
	{
		if (comlen(a[i], a[i + 1]) > maxlen)
		{
			maxlen = comlen(a[i], a[i + 1]);
			maxi = i;
		}
	}
	
	rt.assign(a[maxi], maxlen);

	delete[]c;
	delete[]a;

	return rt;
}

