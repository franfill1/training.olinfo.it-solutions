#include <bits/stdc++.h>

using namespace std;

ifstream fin;
ofstream fout;

int main ()
{
	fin.open("input.txt");
	fout.open("output.txt");
	
	int H0, M0;
	fin >> H0 >> M0;
	int H1, M1;
	fin >> H1 >> M1;
	
	M0 += H0 * 60;
	M1 += H1 * 60;
	
	if (M1 < M0)
	{
		M1 += 24 * 60;
	}
	
	int M = M1 - M0;
	
	int H = M / 60;
	M = M % 60;
	
	fout << H << " " << M;
	
	return 0;
}
