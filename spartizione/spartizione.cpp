#include<bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int N, K; 
	fin >> N >> K;
	K--;
	
	int ans = 0;
	int tot = 0;
	int i = 1;
	
	while(tot + i + K <= N)
	{
		ans += i;
		tot += i + K;
		i++;
	}	
	ans += min(i, N - tot);
	fout << ans;
	
	return 0;
}
