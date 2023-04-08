#include <vector>
#include <utility>
#include <queue>
using namespace std;

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D) {
    vector < pair < int , int > > g[N];
    for (int i = 0; i < M; i++) g[X[i]].emplace_back(Y[i], P[i]);
    D.assign(N, -1);
    int c = N;
    priority_queue < pair < int , int >  > pq;
    pq.emplace(0, 0);
    D[0] = 0;
    
    while(!pq.empty())
    {
    	auto [d, x] = pq.top();
    	pq.pop();
    	if (-d > D[x]) continue;
    	c--;
    	if (!c) break;
    	for (auto [y, w] : g[x]) if (D[y] > -d + w || D[y] == -1)
    	{
    		D[y] = -d + w;
    		pq.emplace(d-w, y);
		}
	}
}