#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N;
	fin >> N;
	map < char , int > m;
	char sla;
	for (int i = 0; i < N / 4; i++)
	{
		char sign;
		fin >> sla;
		fin >> sign;
		fin >> sla >> sla;
		m[sign]++;
	}
	fout << min(m['+'], m['-']);
}
