#include <bits/stdc++.h>

using namespace std;

ifstream fin;
ofstream fout;

int main ()
{
	fin.open("input.txt");
	fout.open("output.txt");
	
	int N, V;
	fin >> N >> V;
	
	vector < int > e(0);
	vector < int > b(0);
	
	for (int i = 0; i < N; i++)
	{
		int el;
		fin >> el;
		e.push_back(el);
	}
	
	for (int i = 0; i < V; i++)
	{
		int el;
		fin >> el;
		b.push_back(el);
	}
		
	sort(e.begin(), e.end());
	sort(b.begin(), b.end());
	
	int ans = 0;
	
	int i = 0, j = 0;
	while(j < V && i < N)
	{
		if(b[j] >= e[i])
		{
			ans++;
			i++;
			j++;
		}
		else
		{
			j++;
		}
	}
	
	fout << ans;
	
	return 0;
}

