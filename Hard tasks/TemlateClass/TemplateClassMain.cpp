#include <iostream>
#include "vec_iterator.h"

using namespace std;

int main()
{
	Vec <int> V(5);
	int i = 0;
	vec_iterator <int> IV(V);
	while (!IV.end())
		IV.next() = (++i);
	IV.rewind();
	cout << "V=";
	do {
		cout << IV.next() << " ";
	} while (!IV.end());
	cout << endl;
	return 0;
}