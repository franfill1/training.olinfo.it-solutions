#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

vector < int > v;

int fraud(int l, int r)
{
	unordered_map < int , int > occ;
	for (int i = l; i < r; i++)
	{
		occ[v[i]]++;
	}
	int ma = v[l], mi = v[l];
	for (auto it : occ)
	{
		if (occ[ma] < it.second)
		{
			ma = it.first;
		}
		if (occ[mi] > it.second)
		{
			mi = it.first;
		}
	}
	
	int ans = occ[ma] * occ[mi];
	
	int newL = l;
	int newR;
	for (int i = l; i < r; i++)
	{
		if (i != l && occ[v[i-1]] == occ[mi])
		{
			newL = i;
		}
		if (occ[v[i]] == occ[mi])
		{
			newR = i;
			if (newR - newL > 0)
			{
				ans = max(ans, fraud(newL, newR));
			}
		}
	}
	newR = r;
	if (newR - newL > 0 && newL != l)
	{
		ans = max(ans, fraud(newL, newR));
	}
	
	return ans;
}

int main()
{
	int N;
	fin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
	{
		fin >> v[i];
	}
	fout << fraud(0, N);
}
