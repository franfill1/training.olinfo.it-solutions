#include<bits/stdc++.h>
using namespace std;

bool chiedi(int K);
void stato();
void sposta();

void indovina(int N, int A, int B, int C, int h[]) 
{
    if (B == 1)
    {
int k = 20;
    int s = N/k;

    set < int > rem;
    for (int i = 0; i < N; i++) rem.insert(i);

    vector < set < int > > c(k);
    for (int i = 0; i < N; i++)
    {
        if ((i+1) % s == 0)
        {
            int j = i / s;
            for (int r : rem)
            {
                if (chiedi(r))
                {
                    c[j].insert(r);
                }
            }
            for (int r : c[j]) rem.erase(r);
        }
        if (i < N-1) sposta();
    }

    stato();
    sposta();
    for (int i = N-2; i >= 0; i--)
    {
        int j = (i+1)/s;
        bool b = false;
        for (int r : c[j])
        {
            if (!chiedi(r))
            {
                h[i+1] = r;
                b = true;
                break; 
            }
        }
        assert(b);
        assert(c[j].count(h[i+1]));
        c[j].erase(h[i+1]);
        if (i > 0) sposta();
    }
    h[0] = *(c[0].begin());
    return;
    }
    map < int , set < int > > m;
    for (int i = 0; i < N; i++) m[N-1].insert(i);
    m[-1].size();

    for (int c = 0; c < 5; c++)
    {
        map < int , set < int > > nm;
        for (int x = 0; x < N; x++)
        {
            auto ib = m.lower_bound(x);
            auto ia = prev(ib);
            int b = ib->first;
            int a = ia->first;

            if (x != b && x != a && x == (b+a)/2)
            {
                for (int r : m[b])
                {
                    if (chiedi(r))
                    {
                        nm[x].insert(r);
                    }
                }
                for (int r : nm[x])
                {
                    m[b].erase(r);
                }
            }
            if (x < N-1) sposta();
        }
        for (auto s : nm)
        {
            m[s.first] = s.second;
        }
        nm.clear();
        stato();

        for (int x = N-1; x >= 0; x--)
        {
            auto ib = m.lower_bound(x);
            auto ia = prev(ib);
            int b = ib->first;
            int a = ia->first;

            if (x != b && x != a && x == (b+a)/2)
            {
                for (int r : m[b])
                {
                    if (chiedi(r))
                    {
                        nm[x].insert(r);
                    }
                }
                for (int r : nm[x])
                {
                    m[b].erase(r);
                }
            }
            if (x) sposta();
        }
        for (auto s : nm)
        {
            m[s.first] = s.second;
        }
        stato();
    }

    for (int i = 0; i < N; i++)
    {
        h[i] = *(m[i].begin());
    }
}
