#include<bits/stdc++.h>
using namespace std;

int gpu(int n, int m, int v[]) 
{
	auto check = [&](int k)
	{
		priority_queue < int , vector < int > , greater < int > > pq;
		for (int i = 0; i < k; i++) pq.push(0);

		int a = 0;
		for (int i = 0; i < n; i++)
		{
			a = max(a, pq.top() + v[i]);
			pq.push(pq.top() + v[i]);
			pq.pop();
		}
		return a<=m;
	};

	int a=0, b=1;
	while(!check(b)) b<<=1;
	
	while(a < b-1)
	{
		int m = (a+b) /2;
		if (!check(m)) a = m;
		else b = m;
	}
	return b;
}
