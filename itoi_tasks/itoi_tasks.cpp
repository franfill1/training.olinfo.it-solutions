#include<vector>
#include<queue>
#include<iostream>
#define int long long
using namespace std;
typedef priority_queue < int , vector < int > , greater < int > > pq;

int n, c;
vector < pq > M;
vector < vector < int > > g;
vector < int > v;

void calc(int x, int p=-1)
{
        for (int i = 0; i <= c; i++) M[x].push(0);
        for (int y : g[x]) calc(y, x);

        int l = M[x].top() + v[x];
        M[x].pop();
        while(!M[x].empty())
        {
                int a = M[x].top();
                l = min(l, a);
                M[p].push(l);

                M[p].pop();
                M[x].pop();
                l = a + v[x];
        }
        M[p].push(l);
        M[p].pop();
}

signed main()
{
        cin >> n >> c;
        g.resize(n);
        v.resize(n);
        M.resize(n+1);
        for (int i = 0; i <= c; i++) M[n].push(0);
        int r;
        for (int i = 0; i < n; i++)
        {
                int p;
                cin >> p >> v[i];
                if (p==-1) r=i;
                else g[p].push_back(i);
        }
        calc(r, n);
        int ans = M[n].top();
        cout << ans << "\n";
}