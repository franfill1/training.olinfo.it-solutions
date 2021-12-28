#include<bits/stdc++.h>
#define MAXN 100001
using namespace std;

vector < int > g[MAXN];
vector < bool > r[MAXN];
int c[MAXN], n, a, b, x=0, m=0, i;
bool v[MAXN]; 

int main()
{
	cin >> n;
	for (i = 0; i < n-1; i++)
	{
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		r[a].push_back(false);
		r[b].push_back(true);
	}

	queue < int > q;
	q.push(1);
	v[1] = true;
	c[1] = 0;
		
	while(!q.empty())
	{
		a = q.front(); q.pop();
		m = min(m, c[a]);
		for (i = 0; i < g[a].size(); i++) 
		{
			b = g[a][i];
			if (!v[b])
			{
				v[b] = true;
				if (r[a][i])
				{
					x++;
					c[b] = c[a]-1;
				}
				else c[b] = c[a]+1;
				q.push(b);
			}
		}
	}
	cout << x+m << "\n";
	for (i = 1; i <= n; i++) if (c[i] == m) cout << i << " ";
}
