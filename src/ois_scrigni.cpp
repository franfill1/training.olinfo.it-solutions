#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	long long n;
	fin >> n;
	fout << ((long double)n*((long double)n-1))/4;
}
