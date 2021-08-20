#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef long long ll;

int main()
{
	ll a, b;
	fin >> a >> b;
	
	bool ok = true;
	ll ans = 0;
	while(a != 1 || b != 1)
	{
    	if (a % 2 && b % 2)
    	{
    		a = a * 3 + 1;
    		b = b * 3 + 1;
    	}
    	else if (a % 2)
    	{
    		a += 3;
    	}
    	else if (b % 2)
    	{
    		b += 3;
    	}
    	else
    	{
    		a>>=1;
    		b>>=1;
    	}
    	
    	if (ans > 1000000)
    	{
    	    ok = false;
    	    break;
    	}
    	
		ans++;
	}
	
	if (ok) fout << ans;
	else fout << -1;
}
