#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stdlib.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
 {
	int N, k, maxG = 0, sp, r;
	fin >> k;
	fin >> N;
	int* values;
	values = (int*) calloc (N,sizeof(int));
	for (int i = 0; i < N; i++)
	{
		fin >> values[i];
	}
	for (int i = 0; i < N; i++)
	{
		sp = values[i];
		for (int j = 0; j < k + 1; j++)
		{
			if (i + j < N)
			{
				r = values[(i + j)];
				int g = r - sp;
				maxG = max(maxG, g);
			}
		}
	}
	fout << maxG;
}