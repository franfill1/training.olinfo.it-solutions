#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

typedef int ull;


int modPow(int b, int e, int M)
{
	if (e == 0)
	{
		return 1;
	}
	int ans = e%2 ? b : 1;
	int n = modPow(b, e>>1, M);
	
	ans *= n;
	ans %= M;
	ans *= n;
	ans %= M;
	
	return ans;
}

int conta(int N, int K, vector<int>& V)
{
	const int M = 46337;
		
	vector < int > inv(M);
	for (int i = 1; i < M; i++)
	{
		inv[i] = modPow(i, M - 2, M);
	}
	
	ull found = 0;
	ull occ[K] = {1};
	for (ull i = 0; i < K; i++)
	{
		occ[i] = 0;
	}
		
	ull panLen = 1;
	ull pos = 1;
		
	ull a = 0, b = 0;
	for (ull i = 0; found < K; i++)
	{
		if(occ[V[i]] == 0)
		{
			b = i;
			found++;
		}
		occ[V[i]]++;
	}
	for (ull i = 0; i < K; i++)
	{
		pos *= occ[i];
		pos %= M;
	}
	ull curAns = pos;
	panLen = b;
	
	while(true)
	{ 
		if (occ[V[a]] > 1)
		{
			pos*= inv[occ[V[a]]--];
			pos %= M;
			pos *= occ[V[a++]];
			pos %= M;
			if (b - a < panLen)
			{
				panLen = b - a;
				curAns = pos % M;
			}
			else if (b - a == panLen)
			{
				curAns += pos % M;
				curAns %= M;
			}
		}	
		else 
		{
			if(b == N - 1)
			{
				break;
			}
			
			b++;
			pos *= inv[occ[V[b]]];
			pos %= M;
			occ[V[b]]++;
			pos *= occ[V[b]];
			pos %= M;
			if (b - a < panLen)
			{
				panLen = b - a;
				curAns = pos % M;
			}
			else if (b - a == panLen)
			{
				curAns += pos % M;
				curAns %= M;
			}
		}
	}
	return curAns;
}