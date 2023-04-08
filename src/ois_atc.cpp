#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector < string > m(n);
	for (string &s : m) cin >> s;

	vector < vector < int > > d(n, vector < int > (n, n*n));

	vector < int > dx {1, -1, 0, 0};
	vector < int > dy {0, 0, 1, -1};

	deque < tuple < int , int , int , int > > dq;
	dq.push_front({0, 0, 0, 0});
	d[0][0] = 0;

	while(!dq.empty())
	{
		auto [x, y, f, id] = dq.front();
		dq.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && m[nx][ny] != '#')
			{
				int nd = id + (f != i && m[x][y] != 'T');
				if (nd <= d[nx][ny])
				{
					d[nx][ny] = nd;
					if (nd != id)
					{
						dq.push_back({nx, ny, i, nd});
					}
					else
					{
						dq.push_front({nx, ny, i, nd});
					}
				}
			}
		}
	}

	if (d[n-1][n-1] == n*n) cout << -1 << "\n";
	else cout << d[n-1][n-1] << "\n";
}
