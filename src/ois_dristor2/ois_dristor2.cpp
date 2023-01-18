#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector < int > col(M, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int x;
			cin >> x;
			col[j] += x<<i;
		}
	}

	vector < vector < int > > bes(M+1, vector < int > (1<<N, 0));
	vector < vector < int > > cnt(M+1, vector < int > (1<<N, 1));

	for (int j = M-1; j >= 0; j--)
	{
		for (int c = 0; c < 1<<N; c++)
		{
			bes[j][c] = bes[j+1][c];
			cnt[j][c] = cnt[j+1][c];
			for (int i = 0; i < N; i++)
				if ((c & (1<<i)) && (col[j] & (1<<i)))
				{
					int nc = c ^ (1<<i);
					if (bes[j][c] < bes[j+1][nc] + 1)
						bes[j][c] = bes[j+1][nc] + 1, cnt[j][c] = cnt[j+1][nc];
					else if (bes[j][c] == bes[j+1][nc] + 1)
						cnt[j][c] += cnt[j+1][nc];
					cnt[j][c] %= 1000000007;
				}
		}
	}
	cout << cnt[0][(1<<N)-1] << "\n";
}
