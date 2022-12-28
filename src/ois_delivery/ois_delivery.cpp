#include <bits/stdc++.h>

using namespace std;

ifstream fin;
ofstream fout;

int main ()
{
	fin.open("input.txt");
	fout.open("output.txt");
	
	int N;
	fin >> N;
	
	int delDay;
	fin >> delDay;
	
	int ans = 0;
	
	for (int day = 1; day < N; day++)
	{
		int del;
		fin >> del;
		if (delDay > del + day)
		{
			ans++;
			delDay = del + day;
		}
	}
	
	fout << delDay << " " << ans;
	
	
	return 0;
}

