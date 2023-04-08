#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef long long ll;

const ll inf = -(1ll<<60);

int main()
{
	ll N, K, M, P, Q;
	fin >> N >> K >> M >> P >> Q;
	
	deque < ll > d; // lunghezza k
	
	deque < ll > par;
	deque < ll > dis;
	
	par.push_back(Q - P);
	d.push_back(Q - P);
	
	dis.push_back(P - Q - M);
	d.push_back(P - Q - M);
	
	if (N == 1)
	{
	    fout << P-Q-M;
	    return 0;
	}
	if (K == 1)
	{
		par.pop_front();
		d.pop_front();
	}
	
	ll ans = 0;
	for (ll i = 2; i <= N; i++)
	{
		ll ansPar = par.empty() ? inf : (-par.front() - (i % 2 == 1 ? M : 0));
		ll ansDis = dis.empty() ? inf : (-dis.front() - (i % 2 == 1 ? 0 : M));
		ans = max(ansPar, ansDis);
		d.push_back(ans);
		
		if (i >= K)
		{
    		if (((i - K) % 2 == 0))
    		{
    			if (d.front() == par.front())
    			{
    				par.pop_front();
    			}
    		}
    		else
    		{
    			if (d.front() == dis.front())
    			{
    				dis.pop_front();
    			}
    		}
    		d.pop_front();
		}
		
		if (i % 2 == 0)
		{
			while(!par.empty() && par.back() > ans)
			{
				par.pop_back();
			}
			par.push_back(ans);
		}
		else
		{
			while(!dis.empty() && dis.back() > ans)
			{
				dis.pop_back();
			}
			dis.push_back(ans);
		}
		
		
		
	}
	fout << ans;
}
