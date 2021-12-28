#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int INF = 1<<30;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N;
	fin >> N;
	n = N + 2;
	
	adj.resize(n);
	capacity.resize(n, vector < int > (n, 0));
	
	for (int i = 1; i <= N; i++)
	{
		adj[0].push_back(i);
		adj[i].push_back(N+1);
	}
	
	for (int i = 1; i <= N; i++)
	{
		fin >> capacity[0][i];
	}
	for (int i = 1; i <= N; i++)
	{
		fin >> capacity[i][N+1];
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			fin >> capacity[i][j];
			if (capacity[i][j] != 0) adj[i].push_back(j);
		}
	}
	
	fout << maxflow(0, N+1);
}
