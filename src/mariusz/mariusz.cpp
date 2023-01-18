#include<iostream>
#include<vector>
#include<cassert>
#define int long long
using namespace std;

const int MAX_E = 21;

struct arr
{
        int a, b, c;
        int v;
        arr(int a_, int b_, int c_, int v0) : a(a_), b(b_), c(c_), v(v0)
        {
        }

        arr()
        {
        }

        void step()
        {
                v = (a*v+b)%c;
        }
};

struct ship {
        int i;
        int dp[3][MAX_E];
        arr u, d, m;
        ship *prev = NULL;

        ship(arr u_, arr d_, arr m_, ship* prev_ = NULL)
        {
                u = u_, d = d_, m = m_;
                i = 0;
                prev = prev_;
        }

        void step()
        {
                i++;
                int ii = i % 3, jj = (i+2)%3, kk = (i+1)%3;
                for (int e = 0; e < MAX_E; e++)
                {
                        dp[ii][e] = dp[jj][min(e+1,MAX_E-1)] + u.v;
                        if (i > 1)
                                dp[ii][e] = min(dp[ii][e], dp[kk][e] + d.v);
                        if (prev && e)
                                dp[ii][e] = min(dp[ii][e], prev->get(i/2, e-1) + m.v);
                }
                u.step();
                d.step();
                m.step();
        }

        int get(int i_, int e)
        {
                if (i < i_)
                        step();
                assert(i == i_);
                return dp[i%3][e];
        }
};

main()
{
        int n, e;
        cin >> n >> e;
        int v, a, b, c;
        cin >> v >> a >> b >> c;
        arr u(a, b, c, v);
        cin >> v >> a >> b >> c;
        arr d(a, b, c, v);
        cin >> v >> a >> b >> c;
        arr m(a, b, c, v);
        vector < ship > V;
        V.emplace_back(u, d, m);
        for (int i = 1; i < MAX_E; i++)
                V.emplace_back(u, d, m, &V.back());
        for (int i = 0; i < n; i++)
                V.back().step();
        cout << V.back().get(n, min(MAX_E-1, e)) << "\n";
}