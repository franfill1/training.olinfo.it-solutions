#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll riciclo(int N, int M, vector<int> T, vector<int> P) 
{
    ll ans = 0;
    int c = 0;
    while(P[c] == 0 && c < M) c++;
    for (int p = 0; p < 30; p++)
    {
        for (int i = 0; i < N && c <= p && c < M; i++)
        {
            if ((T[i]>>p)&1)
            {
                int t = 1<<p;
                bool ok = true;
                while(c <= p && c < M && ok && P[c] != 0)
                {
                    ok = false;
                    int m = t/(1<<c);
                    m = min(m, P[c]);
                    t -= m*(1<<c);
                    P[c] -= m;
                    ans += m; 

                    while (c < M && P[c] == 0) 
                    {
                        c++;
                        ok = true;
                    }
                }
            }
        }
    }
    return ans;
}
