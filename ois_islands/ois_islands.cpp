#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N, M;
	fin >> N >> M;
	vector < vector < bool > > m(N);
	for (int i = 0; i < N; i++)
	{
		m[i].resize(M);
		for (int j = 0; j < M; j++)
		{
			int el;
			fin >> el;
			m[i][j] = el;
		}
	}
	
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (m[i][j])
			{
				bool is = true;
				queue < pair < int , int > > q;
				q.push(make_pair(i, j));
				while(!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					
					if(x == 0 || x == N-1 || y == 0 || y == M-1)
					{
						is = false;
					}
					
					vector < int > dx {-1, 1, 0, 0};
					vector < int > dy {0, 0, -1, 1};
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx >= 0 && nx < N && ny >= 0 && ny < M && m[nx][ny])
						{
							m[nx][ny] = false;
							q.push(make_pair(nx, ny));
						}
					}
				}
				ans += is;
			}
		}
	}
	fout << ans;
}