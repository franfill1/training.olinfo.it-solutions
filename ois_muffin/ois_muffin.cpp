#include<bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int N, K;
	fin >> N >> K;
	
	vector < int > muffins(N);
	
	for (int i = 0; i < N; i++)
	{
		fin >> muffins[i];
	}
	
	int a = 0, b = K - 1;
	int curSum = 0;
	for (int i = 0; i < K; i++)
	{
		curSum += muffins[i];
	}
	int totPob = N - K + 1;
	
	int ans = curSum;
	
	for (int i = 1; i < totPob; i++)
	{
		curSum -= muffins[a];
		a++;
		b++;
		curSum += muffins[b];
		
		ans = max(ans, curSum);
	}
	
	fout << ans;
}