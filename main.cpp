#include "Sequence.h"
#include <ctime>

using namespace std;

int main()
{
	clock_t start, end;

	Sequence S("dna.txt");
	cout << "Length: " << S.length() << endl;
	cout << "A     : " << S.numberOf('A') << endl;
	cout << "T     : " << S.numberOf('T') << endl;
	cout << "C     : " << S.numberOf('C') << endl;
	cout << "G     : " << S.numberOf('G') << endl << endl;

	cout << "Longest Consecutive:" << endl;
	start = clock();
	cout << S.longestConsecutive() << endl;
	end = clock();
	cout << "The time was: " << (1.0 * end - start)/ CLK_TCK << endl << endl;

	cout << "Longest Repeated:" << endl;
	start = clock();
	cout << S.longestRepeated() << endl;
	end = clock();
	cout << "The time was: " << (1.0 * end - start) / CLK_TCK << endl << endl;

	system("pause");

	return 0;
}
