/**
* user:  lugli
* fname: Francesco
* lname: Lugli
* task:  candele
* score: 26.0
* date:  2020-11-25 14:04:58.775420
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < int , int > ii;
typedef pair < ll, int > ill;

void brucia(int N, vector<int> &M, vector<int> &B, vector<long long> &T) {
	T[0] = 0;
	const ll veryLong = 1LL<<62;
	for (int i = 1; i < N; i++)
	{
		T[i] = veryLong;
	}
	
	vector < vector < ii > > g(N, vector < ii > (0));
	
	vector < ii > mS(N);
	for (int i = 0; i < N; i++)
	{
		mS[i] = make_pair(M[i], i);
	}
	sort(mS.begin(), mS.end());
	
	//creo il pogchamp grafo
	stack<int> s;
	stack<int> s2;
	for (int i = 0; i < N; i++)
	{
		int j = mS[i].second;
		while(s.size() && B[s.top()] < M[j]) 
		{
			s.pop();
		}
		if(s.size()>0)
		{
			if (M[s.top()] == M[j])
			{
				g[j].push_back(make_pair(s.top(), abs(M[j] - M[s.top()])));
			}
			g[s.top()].push_back(make_pair(j, abs(M[j] - M[s.top()])));
		}
		if(M[j] < B[j])
		{
			while(s.size() && B[s.top()] <= B[j])
			{
				if (M[s.top()] == M[j])
				{
					g[j].push_back(make_pair(s.top(), abs(M[j] - M[s.top()])));
					g[s.top()].push_back(make_pair(s.top(), abs(M[j] - M[s.top()])));
				}
				s.pop();
			}
			s.push(j);
		}

		while(s2.size() && (M[s2.top()] >= B[j] || M[s2.top()] == M[j]))
		{
			if (M[s2.top()] == M[j])
			{
				g[s2.top()].push_back(make_pair(j,  abs(M[s2.top()] - M[j])));
			}
			g[j].push_back(make_pair(s2.top(), abs(M[s2.top()] - M[j])));
			s2.pop();
		}
		s2.push(j);
	}
	
	//press X to djkstra
	
	priority_queue < ill, vector < ill > , greater < ill > > q;
	
	q.push(make_pair(0, 0));
	while(!q.empty())
	{
		int n = q.top().second;
		ll d = q.top().first;
		q.pop();
		if (d > T[n])
		{
			continue;
		}
		
		for (int i = 0; i < g[n].size(); i++)
		{
			if (T[g[n][i].first] > d + (ll)g[n][i].second)
			{
				T[g[n][i].first] = d + (ll)g[n][i].second;
				q.push(make_pair(T[g[n][i].first], g[n][i].first));
			}
		}
	}
	
	for (int i = 1; i < N; i++)
	{
		if (T[i] == veryLong)
		{
			T[i] = -1;
		}
	}
}