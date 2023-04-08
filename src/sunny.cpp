#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,m,h,s;
	
	cin>>n>>m>>h>>s;
	
	vector < vector < pair < int , int > > > g(n);
	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}

	
	int partenza = h-1;
	int indiceMin;
	int min = 50001;
	int ans = 0;
	
	if(h == s)
	{
		cout<<ans<<endl;
		return 0;	
	}
	
	vector < bool > vis(n, false);
	for(int i=0;i<g[partenza].size();i++)
	{
		if (vis[partenza]) break;
		if(partenza == s-1)
		{
			cout<<ans<<endl;
			return 0;
		}
		
		if(g[partenza][i].second < min)
		{
			min = g[partenza][i].second;
			indiceMin = g[partenza][i].first;
		}
		
		if(i == g[partenza].size()-1)
		{
		    vis[partenza] = true;
			min = 50001;
			i=-1;
			ans++;
			partenza = indiceMin;
		}
	}
	
	
	cout<<-1<<endl;
	
}