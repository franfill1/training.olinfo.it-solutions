#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int H, W;
	fin >> H >> W;
	
	vector < vector < bool > > lava(H);
	vector < vector < bool > > vis(H);
	vector < vector < int > > dis(H);
	for (int i = 0; i < H; i++)
	{
		lava[i].resize(W);
		vis[i].resize(W, false);
		dis[i].resize(W);
		for (int j = 0; j < W; j++)
		{
			char c;
			fin >> c;
			lava[i][j] = (c == '#');
		}
	}
	queue < pair < int , int > > q;
	vis[0][0] = true;
	q.push({0, 0});
		
	while(!q.empty())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();
		
		for (int dy = - 2; dy <= 2; dy++)
		{
			int ny = y + dy;
			for (int dx = abs(dy) - 2; dx <= 2 - abs(dy); dx++)
			{
				int nx = x + dx;
				if (nx < W && ny < H && nx >= 0 && ny >= 0)
				{
					if (!lava[ny][nx] && !vis[ny][nx])
					{
						dis[ny][nx] = dis[y][x] + 1;
						vis[ny][nx] = true;
						q.push(make_pair(ny, nx));
					}
				}
			}
		}
	}
	fout << dis[H-1][W-1];
}