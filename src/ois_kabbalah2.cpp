#include <bits/stdc++.h>

using namespace std;

typedef int ull;

int revv(int n)
{
	int ans = 0;
	int p = 1;
	while(p <= 1000)
	{
		ans *= 10;
		ans += (n/p)%10;
		p *= 10;
	}
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	
	vector < ull > occ(10000);
	
	vector < int > rev(10000);
	for (int i = 0; i < 10000; i++)
	{
	    rev[i] = revv(i);
	}
	
	vector < int > ver(M, 0);
	
	vector < int > diag1(M, 0);
	vector < int > diag2(M, 0);
	
	for (int j = 0; j < N; j++)
	{
		vector < int > row(M);
		int n = 0;
		for (int i = 0; i < 4; i++)
		{
			char c;
			cin >> c;
			n *= 10;
			row[i] = c - '0';
			n += row[i];
		}
		occ[n]++; occ[rev[n]]++;
		for (int i = 4; i < M; i++)
		{
			char c;
			cin >> c;
			row[i] = c - '0';
			n *= 10;
			n += row[i];
			n %= 10000;
			occ[n]++; occ[rev[n]]++;
		}
				
		for (int i = 0; i < M; i++)
		{
			ver[i] *= 10;
			ver[i] += row[i];
			ver[i] %= 10000;
			if (j > 2) 
			{
				occ[ver[i]]++; occ[rev[ver[i]]]++;
			}
		}
		
		for (int i = 1; i < M; i++)
		{
			diag1[i-1] = (diag1[i] * 10)%10000 + row[i-1];
		}
		diag1[M-1] = row[M-1];

		for (int i = M-2; i >= 0; i--)
		{
			diag2[i+1] = (diag2[i] * 10)%10000 + row[i+1];
		}
		diag2[0] = row[0];

		if (j > 2)for (int i = 0; i < M-3; i++)
		{
			occ[diag1[i]]++; occ[rev[diag1[i]]]++;
		}
		if (j > 2) for (int i = 3; i < M; i++)
		{
			occ[diag2[i]]++; occ[rev[diag2[i]]]++;
		}
	}
	
	int ans = 1000;
	for (int i = 1000; i < 10000; i++)
	{
		if (occ[ans] < occ[i])
		{
			ans = i;
		}
	}
	cout << ans << " " << occ[ans];
}