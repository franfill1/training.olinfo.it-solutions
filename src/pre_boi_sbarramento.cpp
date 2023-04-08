#include <vector>
#include <iostream>
#include <utility>
#include <queue>
using namespace std;

typedef pair < long long , int > state;

long long fuggi(int N, int M, vector <int> A, vector <int> B, vector <int> T, vector <int> R){
	vector < vector < pair < int , int > > > blue(N);
	vector < vector < pair < int , int > > > red(N);
	for(int i = 0; i < M; i++)
	{
		if (R[i])
			red[B[i]].emplace_back(A[i], T[i]);
		else
			blue[B[i]].emplace_back(A[i], T[i]);
	}

	vector < long long > dRed(N, 1ll<<60), dBlu(N, 1ll<<60);
	priority_queue < state , vector < state > , greater < state > > pq;
	dRed[N-1] = dBlu[N-1] = 0;
	pq.emplace(0, N-1);
	while(!pq.empty())
	{
		auto [d, x] = pq.top();
		pq.pop();
		if (d > dBlu[x])
			continue;
		for (auto [y, w] : red[x])
		{
			long long nd = dBlu[x] + w;
			if (dRed[y] > dBlu[x] + w)
			{
				if (dRed[y] > dBlu[y] && nd < dBlu[y])
				{
					dBlu[y]--;
					pq.emplace(dBlu[y], y);
				}
				dRed[y] = dBlu[x] + w;
			}
		}
		for (auto [y, w] : blue[x])
		{
			long long nd = dBlu[x] + w;
			if (dRed[y] < nd)
				nd--;
			if (dBlu[y] > nd)
			{
				dBlu[y] = nd;
				pq.emplace(nd, y);
			}
		}
	}
	return dBlu[0];
}
