#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector < vector < int > > g;
vector < map < int , long long > > dp;
vector < int > d, w;

void calc(int x)
{
    for (int y : g[x]) 
    {
        calc(y);
        if (dp[y].size() > dp[x].size()) swap(dp[x], dp[y]);
    }

    for (int y : g[x])
    {
        for (auto [k, v] : dp[y]) 
        {
            dp[x][k] += v;
        }
    }

    if (d[x] != 0)
    {
        int day = d[x];
        int wei = w[x];
        dp[x][day] += wei;
        int sum = 0;
        auto it = dp[x].find(day);
        while(next(it) != dp[x].end() && sum + next(it)->second <= wei)
        {
            sum += next(it)->second;
            dp[x].erase(next(it));
        }
        
        if (next(it) != dp[x].end())
        {
            next(it)->second += sum - wei;
        }
    }
}

long long harvest(int n, int m, int k, vector<int>& p,
				  vector<int>& v, vector<int>& _d, vector<int>& _w) {
    g.resize(n);
    dp.resize(n);
    d.resize(n);
    w.resize(n);
    for (int i = 0; i < m; i++)
    {
        d[v[i]] = _d[i];
        w[v[i]] = _w[i];
    }
    
    for (int i = 1; i < n; i++) g[p[i]].push_back(i);
    calc(0);
    long long ans = 0;
    for (auto [k, v] : dp[0]) ans += v;
    return ans;
}
