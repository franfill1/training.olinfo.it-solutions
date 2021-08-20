#include <bits/stdc++.h>

#define maxv 400001

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	bitset<maxv> knap;
	int N, B;
	fin >> N >> B;
	knap.set(0, 1);
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int el;
		fin >> el;
		sum += el;
		knap |= knap<<el;
	}
	int ans = knap._Find_next(B-1);
	fout << (ans == maxv ? sum : ans);
}
