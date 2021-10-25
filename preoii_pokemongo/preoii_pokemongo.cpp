#include<math.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
using namespace std;
typedef long long ll;

inline bool attack(int);

int N, K;

ll eval(int b, int k)
{
	ll ans = 1;
	ll temp = 1;
	for (ll j = 1; j <= k; j++)
	{
	    temp *= (b-j+1);
	    temp /= j;
		ans += temp;
	}
	return ans;
}

int get(int n, int k)
{
	int a=0, b = 1;
	if (k == 2)
	{
	    --n;
	    n<<=1;
	    b = floor(sqrt(n));
	    if (b*b + b > n) b--;
	    return b+1;
	}
	else while(eval(b, k) <= n) b<<=2;
	while(a < b-1)
	{
		int m = (a+b)>>1;
		if (eval(m, k) > n)
		{
			b = m;
		}
		else
		{
			a = m;
		}
	}
	return eval(a, k-1);
}

bool b;
void init(int _N, int _K) 
{
	N = _N;
	b = (K = _K) == 1;
}

int l, r, k, m;
int new_pokemon() 
{
    l = 0;
    if (b) 
    {
        while(l < N && attack(l))l++;
        return l;
    }
	else
	{
    	r = N, k = K;
    	while(l != r && k != 1)
    	{
    	    m = l + get(r-l, k) - 1;
    		if (attack(m))
    		{
    			l = m+1;	
    		}
    		else
    		{
    			r = m;
    			k--;
    		}
    	}
    	while(l < r && attack(l)) ++l;
    	return l;
	}
}

