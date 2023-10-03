#pragma once
#include <new>
//Слияние
void Merge(int* A, int p, int q, int r)
{
	int* SortA = new(std::nothrow) int[r + 1];
	if (!SortA) return;
	int i = p, j = q + 1, k = p;
	while (i <= q && j <= r)
	{
		if (A[i] < A[j]) { SortA[k] = A[i]; i++; k++; }
		else { SortA[k] = A[j]; j++; k++; }
	}
	while (i <= q) { SortA[k] = A[i]; i++; k++; }
	while (j <= r) { SortA[k] = A[j]; j++; k++; }
	for (i = p; i < k; i++) { A[i] = SortA[i]; }
	delete[] SortA;
}
//Сортировка слиянием
void Sort(int* A, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		Sort(A, p, q);
		Sort(A, q+1, r);
		Merge(A, p, q, r);
	}
}