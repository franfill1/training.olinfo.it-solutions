#include<bits/stdc++.h>
#define MAXN 10000000
using namespace std;
typedef long long ll;
ll minxt[MAXN], miprv[MAXN], manxt[MAXN], maprv[MAXN];

ll conta(int N, vector<int> A) 
{
    {
    	stack < ll > ma, mi;
    	for (ll i = 0; i < N; i++)
    	{
    		while(ma.size() && A[ma.top()] <= A[i]) ma.pop();
    		while(mi.size() && A[mi.top()] >= A[i]) mi.pop();
    		maprv[i] = ma.size() ? ma.top() : -1;
    		miprv[i] = mi.size() ? mi.top() : -1; 
    		ma.push(i);
    		mi.push(i);
    	}
    }

    {
        stack < ll > ma, mi;
        for (ll i = N-1; i >= 0; i--)
    	{
    		while(ma.size() && A[ma.top()] <= A[i]) ma.pop();
    		while(mi.size() && A[mi.top()] >= A[i]) mi.pop();
    		manxt[i] = ma.size() ? ma.top() : N;
    		minxt[i] = mi.size() ? mi.top() : N; 
    		ma.push(i);
    		mi.push(i);
	    }
    }
	
	ll ans = 0;
	for (ll i = 0; i < N; i++)
	{
		ll l = maprv[i], r = manxt[i];
		ll x=miprv[i], y=i;
		ll cx=0, cy=0;
		while(x > l && y < r)
		{
			x = miprv[x];
			y = minxt[y];
		}
		if (x <= l) 
			for (x = miprv[i]; x > l; x = miprv[x]) ans += (0ll + min(r, minxt[x]) - i) * (x - max(l, miprv[x]));
		else  
			for (y = i; y < r; y = minxt[y]) ans += (0ll + max(l, miprv[y]) - l) * (min(r, minxt[y]) - y);
	}
	return ans;
}