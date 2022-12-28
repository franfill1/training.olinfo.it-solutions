#include <bits/stdc++.h>
using namespace std;

#define MAXB 100000

int sushi(int N, int B, vector<int> A) 
{
	bitset < MAXB + 1 > O;
	O.set(0, 1);
	
	int p = 0;
	while(true)
	{
		auto n = O;
		for (int i = 0; i < N; i++)
		{
			n |= n<< (A[i]<<p);
		}
		if (n.test(B))
		{
			break;
		}
		else
		{
			O = n;
			p++;
			if (1<<p > B)
			{
				return -1;
			}
		}
	}
		
	int ans = 1<<p;
	for (p--; p >= 0; p--)
	{
		auto n = O;
		for (int i = 0; i < N; i++)
		{
			n |= n << (A[i]<<p);
		}
		if (!n.test(B))
		{
			ans |= (1<<p);
			O = n;
		}
	}
	
	return ans;
}