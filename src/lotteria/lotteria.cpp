#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N, M;
	fin >> N >> M;
	vector < vector < int > > memoSum(N, vector < int > (M+1, 0));
	memoSum[N-1][M] = 1;
	for (int m = M-1; m >= 1; m--)
	{
		memoSum[N-1][m] = (memoSum[N-1][m+1] + 1) % MOD;
	}
	
	for (int n = N-2; n >= 0; n--)
	{
		for (int m = M-1; m >= 1; m--)
		{
			memoSum[n][m] = (memoSum[n][m+1] + (m*2 <= M ? memoSum[n+1][m*2] : 0)) % MOD;
		}
	}
	
	fout << memoSum[0][1];
}
