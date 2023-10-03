#include <iostream>
#include "MergeSort.h"

using namespace std;
int main()
{
	int A[8] = { 5,2,4,6,1,3,2,6 };
	int i;

	cout << "Exist array: ";
	for (i = 0; i < 8; ++i)
		cout << A[i] << " ";
	cout << endl;

	Sort(A, 0, 7);

	cout << "Sort array: ";
	for (i = 0; i < 8; ++i)
		cout << A[i] << " ";
	cout << endl;

	return 0;
}
