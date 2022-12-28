#include <bits/stdc++.h>

#define M 1000000007

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
	ull N, K;
	fin >> N >> K;
	unordered_map < ull , int > nums;
	ull ans = 0;
	for (int i = 0; i < N; i++)
	{
		ull el;
		fin >> el;
		if (K % el == 0)
		{
			ull req = K/el;
			if (nums.find(req) != nums.end() )
			{
				ans += nums[req];
				ans %= M;
			}
			nums[el]++;
		}
	}
	fout << ans;
}
