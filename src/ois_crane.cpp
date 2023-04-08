#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int inf = 1<<30;

struct crane
{
	int x, r; //x = position r = length of arm
	int t, k; //t = cost of turning k = cost of moving
	bool d;	//d = direction
};

int main()
{
	int D, N;
	fin >> D >> N;
	
	int mi = 0, ma = D;
	
	vector < crane > v;
	for (int i = 0; i < N; i++)
	{
		int x, r, t, k;
		bool d;
		fin >> x >> r >> t >> k >> d;
		v.push_back({x, r, t, k, d});
		
		mi = min(mi, x - r);
		ma = max(ma, x + r);
	}
	
	int t = ma-mi+1;
	int st = -mi;
	int nd = D-mi;
	
	vector < int > dist(t, inf);
	dist[st] = 0;
	
	for (int i = 0; i < N; i++)
	{
		v[i].x -= mi;
	}
	
	for (crane c : v)
	{
		int r = c.r;
		for (int i = r; i >= 1; i--)
		{
			for (int j = r; j >= 1; j--)
			{
				int sx, ex, cost;
				//CASO 1: da sinistra a sinistra
				sx = c.x - i; ex = c.x - j;
				cost = c.k * (abs(r - i) + abs(i - j));
				if (c.d)
				{
					cost += c.t;
				}
				dist[ex] = min(dist[ex], dist[sx] + cost);

				//CASO 2: da sinistra a destra
				sx = c.x - i; ex = c.x + j;
				cost = c.t + c.k * (abs(r - i) + abs(i - j));
				if (c.d)
				{
					cost += c.t;
				}
				dist[ex] = min(dist[ex], dist[sx] + cost);
				
				//CASO 3: da destra a sinistra
				sx = c.x + i; ex = c.x - j;
				cost = c.t + c.k * (abs(r - i) + abs(i - j));
				if (!c.d)
				{
					cost += c.t;
				}
				dist[ex] = min(dist[ex], dist[sx] + cost);
				
				//CASO 4: da destra a destra
				sx = c.x + i; ex = c.x + j;
				cost = c.k * (abs(r - i) + abs(i - j));
				if (!c.d)
				{
					cost += c.t;
				}
				dist[ex] = min(dist[ex], dist[sx] + cost);
			}
		}
	}
	
	fout << dist[nd];
}
