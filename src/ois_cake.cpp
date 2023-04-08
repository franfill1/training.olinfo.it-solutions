#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

ifstream fin;
ofstream fout;

int main ()
{
	fin.open("input.txt");
	fout.open("output.txt");
	
	ull N;
	cin >> N;
	cout << ( N % 2ULL ? (N/2ULL + 1ULL) * (N/2ULL + 2ULL) : (N/2ULL + 1ULL) * (N/2ULL + 1ULL) );
	
	return 0;
}

