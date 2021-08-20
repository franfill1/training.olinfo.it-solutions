#include<bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int N;
	fin >> N;
	vector < pair < int , int > > timeLine(0);
	
	for (int i = 0; i < N; i++)
	{
		int e, u;
		fin >> e >> u;
		
		pair < int , int > pE = make_pair(e, 1);
		pair < int , int > pU = make_pair(u, -1);
		
		timeLine.push_back(pE);
		timeLine.push_back(pU);
	}
	
	sort(timeLine.begin(), timeLine.end());
	
	int p = 1;
	unsigned long long int ans = 0;
	
	for (int i = 0; i < timeLine.size(); i++)
	{
		if (timeLine[i].second == 1) //se avviene un'entrata
		{
			ans += p;
			p++;
		}
		else
		{
			p--;
			ans+= p;
		}
	}
	fout << ans;
}