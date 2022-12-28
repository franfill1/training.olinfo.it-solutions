#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef pair < int , int > ii;

int main()
{
	int N;
	fin >> N;
	
	vector < vector < int > > T(N);
	int el;
	fin >> el;
	for (int i = 1; i < N; i++)
	{
		fin >> el;
		T[el].push_back(i);
	}
	
	vector < int > A(N);
	for (int i = 0; i < N; i++)
	{
		fin >> A[i];
	}
	
	priority_queue < ii > pq;
	pq.push({0, 0});
	while(!pq.empty())
	{
		int n = pq.top().second;
		pq.pop();
		fout << n << " ";
		for (auto ne : T[n])
		{
			pq.push(make_pair(A[ne], ne));
		}
	}
}
