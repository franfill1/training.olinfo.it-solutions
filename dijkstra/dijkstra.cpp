#include <bits/stdc++.h>

using namespace std;

ifstream fin;
ofstream fout;

/*
	Nome del programma: Dijkstra
*/

typedef long long ll;
typedef pair < ll, ll > pll;
const ll inf = 1ll<<60;

int main () {
	fin.open("input.txt");
	fout.open("output.txt");
	
	ll N, M;
	fin >> N >> M;
	
	ll s, f;
	fin >> s >> f;
	s--; f--;
	
	vector < vector < pll > > g(N);
	
	for (ll i = 0; i < M; i++) {
		ll a, b, w;
		fin >> a >> b >> w;
		a--; b--;
		
		g[a].push_back({b, w});
	}
	
	vector < ll > D(N, inf);
	D[s] = 0;
	
	priority_queue < pll, vector < pll >, greater < pll > > pq;
	pq.push({0, s});
	
	while (!pq.empty()) {
		ll n = pq.top().second;
		ll d = pq.top().first;
		
		pq.pop();
		
		for (pll nep : g[n]) {
			ll ne = nep.first;
			ll w = nep.second;
			
			ll nd = w + d;
			
			if (D[ne] > nd) {
				D[ne] = nd;
				pq.push({nd, ne});
			}
		}
	}
	
	fout << D[f];
	
	
	return 0;
}
