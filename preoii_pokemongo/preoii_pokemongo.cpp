#include<math.h>
#include<iostream>
#include<vector>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
using namespace std;
typedef long long ll;

bool attack(int);

int N, K;

vector < vector < int > > gr;

int get (int n, int k)
{
	int m = lower_bound(gr[k].begin(), gr[k].end(), n) - gr[k].begin();
	return gr[k][m] - gr[k][m-1];
}

bool b;
void init(int _N, int _K) 
{
	N = _N;
	b = (K = _K) == 1;
	if (K != 1)
	{
    	gr.resize(K+1);
    	gr[2].push_back(0);
    
    	for (int m = 1; gr[2][m-1] < N; m++)
    	{
    		gr[2].push_back(gr[2][m-1] + m);
    	}
    	for (int k = 3; k <= K; k++)
    	{
    		gr[k].push_back(0);				
    		for (int m = 1; gr[k][m-1] < N; m++)
    		{
    			gr[k].push_back(gr[k][m-1] + gr[k-1][m-1] + 1);
    		}	
    	}
	}
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
