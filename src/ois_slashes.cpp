#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector < string > v(N);
	for (string &s : v) cin >> s;

	vector < vector < vector < bool > > > vis(N, vector < vector < bool > > (M, vector < bool > (4, false)));
	queue < tuple < int , int , int > > q;
	int ans = 0;
	for (int x = 0; x < N; x++) for (int y = 0; y < M; y++)
	{
		for (int k = 0; k < 4; k++) if (!vis[x][y][k])
		{
			ans++;
			q.emplace(x, y, k);
			vis[x][y][k] = true;
			while(!q.empty())
			{
				auto [x, y, k] = q.front();
				q.pop();
				int nk = k ^ (v[x][y] == '/' ? 1 : 2);
				if (!vis[x][y][nk])
				{
					vis[x][y][nk] = true;
					q.emplace(x, y, nk);
				}

				nk = 3 - k;
				int nx = x, ny = y;
				if (k == 0) nx = x-1;
				if (k == 1) ny = y-1;
				if (k == 2) ny = y+1;
				if (k == 3) nx = x+1;
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (!vis[nx][ny][nk])
				{
					vis[nx][ny][nk] = true;
					q.emplace(nx, ny, nk);
				}
			}
		}
	}
	cout << ans << "\n";
}
