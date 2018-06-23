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
	int i = 0;
	while (c != EOF)
	{
		switch (c)
		{
		case 'A':
			_a++;
			data[i++] = 1;
			break;
		case 'T':
			_t++;
			data[i++] = 2;
			break;
		case 'C':
			_c++;
			data[i++] = 3;
			break;
		case 'G':
			_g++;
			data[i++] = 4;
			break;
		default:
			break;
		}
		c = ifs.get();
	}
}

int Sequence::length()
{
	return _a + _t + _c + _g;
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
		std::cerr << "illegal base";
		break;
	}
}

string Sequence::longestConsecutive()
{
	string rt;
	int length = _a + _t + _c + _g;
	int start = 0;
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

	switch (start)
	{
	case 1:
		rt.assign(maxlength, 'A');
		break;
	case 2:
		rt.assign(maxlength, 'T');
		break;
	case 3:
		rt.assign(maxlength, 'C');
		break;
	case 4:
		rt.assign(maxlength, 'G');
		break;
	default:
		break;
	}

	return rt;
}

string Sequence::longestRepeated()
{
	string rt;
	int length = _a + _t + _c + _g;
	int start = 0;
	int maxlength = 0;
	int pti, ptj;
	int l = 0;

	for (int i = 0; i < length; ++i)
	{
		for (int j = i + 1; j < length; ++j)
		{
			pti = i;
			ptj = j;
			while (pti < length && ptj < length && data[pti++] == data[ptj++])
			{
				l++;
				if (l >= maxlength)
				{
					maxlength = l;
					start = i;
				}
			}
		}
	}

	for (int i = start; i < start + maxlength - 1; ++i)
	{
		switch (data[i])
		{
		case 1:
			rt[i] = 'A';
			break;
		case 2:
			rt[i] = 'T';
			break;
		case 3:
			rt[i] = 'C';
			break;
		case 4:
			rt[i] = 'G';
			break;
		default:
			break;
		}
	}

	return rt;
}

