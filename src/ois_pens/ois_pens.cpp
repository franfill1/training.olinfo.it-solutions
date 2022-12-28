#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

main(){
	ll N;
	cin >> N;
	bool last = false;
	bool needed = false;
	
	ll ans = 0;
	for (ll i = 0; i < N; i++)
	{
		ll el;
		cin >> el;
		if (el == 0 && last)
		{
			el++;
		}
		if (el > 1 && needed)
		{
			el--;
		}
		else if (el <= 1 && needed)
		{
		    ans++;
		}
		
		if (el > 1)
		{
		    last = true;
		    needed = false;
		}
		if (el == 0)
		{
		    last = false;
		    needed = true;
		}
		if (el == 1)
		{
		    last = false;
		    needed = false;
		}
	}
	ans += needed;
	cout << ans;
}
