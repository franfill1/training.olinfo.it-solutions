#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N, K;
	fin >> N >> K;
	
	priority_queue < pair < double , int > > pQ;
	
	for (int i = 0; i < N; i++)
	{
		double p, f;
		fin >> f >> p;
		pQ.push(make_pair(f - 3 * p / 2, i));
	}
	for (int i = 0; i < K; i++)
	{
		fout << pQ.top().second + 1  << "\n";
		pQ.pop();
	}
}
