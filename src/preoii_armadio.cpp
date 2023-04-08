#include<bits/stdc++.h>
#define MAXN 4000000
using namespace std;
typedef pair < int , int > ii;

int phi[MAXN];
bool composite[MAXN];
vector < int > primes;

int calc(vector < ii > &p, int i=0, int v=1)
{
	if (i == p.size()) 
	{
		return phi[v-1];
	}
	int ans = 0;
	auto [prime, exp] = p[i];
	for (int e = 0; e <= exp; e++)
	{
		ans += calc(p, i+1, v);	
		v *= prime;
	}
	return ans;
}

void evadi(int Q, vector<int>& N) 
{
    for (int n = 2; n < MAXN; n++)
    {
        if (!composite[n]) 
        {
            primes.push_back(n);
            phi[n] = n-1;
        }

        for (int prime : primes)
        {
            if (n * prime >= MAXN) break;
            composite[n*prime] = true;
            if (n % prime == 0)
            {
                phi[n*prime] = phi[n] * prime;  
                break;
            }
            else
            {
                phi[n*prime] = phi[n] * (prime-1);
            }
        }
    }

    for (int q = 0; q < Q; q++)
    {
        int ans = 0;
        int n = N[q];
		vector < ii > p;
		for (auto prime : primes)
		{
			if (prime*prime > n) break;
			int exp = 0;
			while(n % prime == 0)
			{
				exp++;
				n /= prime;
			}
			if (exp) p.push_back({prime, exp});
		}
		if (n != 1)
		{
			p.push_back({n, 1});
		}
        N[q] = calc(p);
    }
}
