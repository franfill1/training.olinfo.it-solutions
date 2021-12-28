#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef unsigned long long int ull;

int main() 
{
	ull N;
	fin >> N;
	priority_queue < ull , vector < ull > , greater < ull > > pq;

	for (int i = 0; i < N; i++)
	{
		ull el;
		fin >> el;
		pq.push(el);
	}
	
	ull ans = 0;
	for (int i = 0; i < N-1; i++)
	{
		ull x = pq.top();
		pq.pop();
		ull y = pq.top();
		pq.pop();
		ans += x + y;
		pq.push(x + y);
	}
	fout << ans << "\n";
}