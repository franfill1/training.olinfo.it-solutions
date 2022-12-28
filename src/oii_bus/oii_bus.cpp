#include <vector>
#include <queue>
#include <utility>
using namespace std;

int pianifica(int N, int L, vector<vector<int>> F) 
{
	vector < vector < pair < int , int > > > list(N);
	vector < vector < int > > dist(L);
	for (int b = 0; b < L; b++)
	{
		dist[b].resize(F[b].size(), 1<<30);
		for (int f = 0; f < F[b].size(); f++)
			list[F[b][f]].emplace_back(b, f);
	}
	deque < pair < int , int > > q;
	vector < bool > vis(N, false);
	for (auto [b, f] : list[0])
	{
		q.emplace_back(b, f);
		dist[b][f] = 0;
	}
	vis[0] = true;
	while(!q.empty())
	{
		auto [b, f] = q.front();
		q.pop_front();
		int x = F[b][f];
		if (x == N-1)
			return dist[b][f];
		if (f+1 < F[b].size())
			if (dist[b][f+1] > dist[b][f])
			{
				dist[b][f+1] = dist[b][f];
				q.emplace_front(b, f+1);
			}
		if (!vis[x])
		{
			vis[x] = true;
			for (auto [b2, f2] : list[x])
			{
				if (dist[b2][f2] > dist[b][f]+1)
				{
					dist[b2][f2] = dist[b][f]+1;
					q.emplace_back(b2, f2);
				}
			}
		}
	}
    return -1;
}
