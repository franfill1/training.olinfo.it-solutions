#include<bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef pair < int , int > ii;

int inf = 1000 * 1000;

main()
{
	int H, W;
	fin >> H >> W;
	
	vector < ii > t;
	
	ii st, en;
	
	vector < string > m(H);
	vector < vector < int > > dis(H, vector < int > (W, inf));
	for (int i = 0; i < H; i++)
	{
		fin >> m[i];
		for (int j = 0; j < W; j++)
		{
			if (m[i][j] == '@')
			{
				t.push_back(make_pair(i, j));
			}
			else if (m[i][j] == 'C')
			{
				st = make_pair(i, j);
			}
			else if (m[i][j] == 'M')
			{
				en = make_pair(i, j);
			}
		}
	}
		
	bool tu = false;
	
	queue < ii > q;
	q.push(st);
	dis[st.first][st.second] = 0;
	
	while(!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		int d = dis[x][y];
		q.pop();
		
		if (x == en.first && y == en.second)
		{
			break;
		}
		
		if (!tu && m[x][y] == '@')
		{
		    tu = true;
			for (ii p : t)
			{
				if (dis[p.first][p.second] > d + 1)
				{
					dis[p.first][p.second] = d + 1;
					q.push(p);
				}
			}
		}
		
		vector < int > dx {0, 0, 1, -1};
		vector < int > dy {1, -1, 0, 0};
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < H && ny >= 0 && ny < W)
			{
				if (m[nx][ny] != '#' && dis[nx][ny] > d + 1)
				{
					dis[nx][ny] = d + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	fout << dis[en.first][en.second];
}

