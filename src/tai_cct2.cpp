#include<bits/stdc++.h>
using namespace std;

int inf = 1<<30;
int speedrunna(int N, int K, int a, int b){
	int t = 1;
	int k = 1;
	vector < int > l (K + 1, inf);
	l[1] = 1;
	
	t *= a;
	t %= 1000;
	k *= b;
	k %= K;
	
	for (int i = 1; i < N; i++)
	{
		vector < int > n (K + 1, inf);
		
		for (int j = 0; j <= K; j++)
		{
			if (l[j] != inf)
			{
				int ni = min(K, (j + k));
				n[ni] = min(n[ni], l[j] + t);
				
				if (j == K) n[0] = min(n[0], l[j]); 
			}
		}
		
		l = n;
		
		t *= a;
		t %= 1000;
		k *= b;
		k %= K;
	}
	int ans = inf;
	for (int i = 0; i <= K; i++)
	{
		ans = min(ans, l[i]);
	}
	return ans;
}