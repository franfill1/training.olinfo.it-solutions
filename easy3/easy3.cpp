#include <bits/stdc++.h>

using namespace std;

int main ()
{
	ifstream fin;
	fin.open("input.txt");
	ofstream fout;
	fout.open("output.txt");
	
	
	int N;
	fin >> N;
	
	int par1 = -1;
	int par2 = -1;
	int dis1 = -1;
	int dis2 = -1;
	
	for (int i = 0; i < N; i++)
	{
		int el;
		fin >> el;
		if (el % 2 == 0)
		{
			if (el > par1)
			{
				par2 = par1;
				par1 = el;
			}
			else if (el > par2)
			{
				par2 = el;
			}
		}
		else if (el % 2 == 1)
		{
			if (el > dis1)
			{
				dis2 = dis1;
				dis1 = el;
			}
			else if (el > dis2)
			{
				dis2 = el;
			}
		}
	}
	
	int ans = -1;
	if (par2 != -1)
	{
		ans = par1 + par2;
	}
	if (dis2 != -1 && dis1 + dis2 > ans)
	{
		ans = dis1 + dis2;
	}
	
	fout << ans;
	
	return 0;
}

