#include <bits/stdc++.h>

using namespace std;



int main ()
{
	ifstream fin;
	fin.open("input.txt");
	ofstream fout;
	fout.open("output.txt");
	
	unsigned long long int t;
	fin >> t;
	fout << (-1LL+(long long int)sqrt(8LL*t+1LL))/2LL;
	return 0;
}

