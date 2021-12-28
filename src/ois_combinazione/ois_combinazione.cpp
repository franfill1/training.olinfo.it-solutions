#include<iostream>
#include<iomanip>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<string>
#include<stdlib.h>
#include<fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int N;

typedef struct
{
	int val;
	int ndx;
} TarrEl;

int compare(const void * a, const void * b)
{
	//return ((TarrEl*)a->val - (TarrEl*)b->val);

	const TarrEl* x = (TarrEl*)a;
	const TarrEl* y = (TarrEl*)b;

	if (x->val < y->val)
		return 1;
	else if (x->val > y->val)
		return -1;

	return 0;

}

int main()
{
	fin >> N;

	TarrEl *arr;

	arr = (TarrEl*)calloc(N, sizeof(TarrEl));

	TarrEl *a = arr;

	for (int i = 0; i < N; i++)
	{
		int val;

		fin >> a->val;
		a->ndx = i;
		a++;
	}

	qsort(arr, N, sizeof(TarrEl), compare);

	a = arr;
	int j = 0;
	long ris = 0;
	for (int i = 0; i < N; i++)
	{
		ris += abs(j - a->ndx);
		j = a->ndx;
		a++;
	}
	fout << ris;
	return 0;

}