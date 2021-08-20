#include<bits/stdc++.h>

#define maxn 1000000

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef long long int ll;

ll B;
ll P;
vector < ll > D(10, 0);

vector < bool > isPrime(maxn, true);

ll price (string label)
{
	ll ans = B;
	ll n = 0, sum = 0, pro = 1, prop = -1;
	for (ll i = 0; i < label.size(); i++)
	{
		n *= 10;
		n += label[i] - '0';
		sum += label[i] - '0';
		ans += D[label[i] - '0'];
		if (prop == -1)
		{
			if (D[label[i] - '0'] != 0)
			{
				prop = 1;
				pro = label[i] - '0';
			}
			else if (label[i] != '1')
			{
				prop = 0;
			}
		}
		else if (prop == 1)
		{
			if (label[i] != '1')
			{
				prop = 0;
			}
		}
	}
	if (isPrime[n])
	{
		ans += n + P;
	}
	if (isPrime[sum])
	{
		ans += sum;
	}
	if (prop == 1)
	{
		ans += pro;
	}
	return ans;
}

main(){
	fin.tie(0);
	fout.tie(0);
	fstream::sync_with_stdio(0);
	isPrime[0] = false;
	isPrime[1] = false;
	for (ll i = 2; i < maxn; i++)
	{
		if (isPrime[i])
		{
			for (ll j = i*2; j < maxn; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	
	
	ll N;
	fin >> N;
	vector < string > L(N);
	for (ll i = 0; i < N; i++)
	{
		fin >> L[i];
	}
	fin >> B >> P;
	fin >> D[2] >> D[3] >> D[5] >> D[7];
	ll ans = 0;
	for (string label : L)
	{
		string ori = label;
		ll pri = 0;
		
		for (char c = '1'; c <= '9'; c++)
		{
			label[0] = c;
			pri = max(pri, price(label));
		}
		for (ll i = 1; i < ori.size(); i++)
		{
			label = ori;
			for (char c = '0'; c <= '9'; c++)
			{
				label[i] = c;
				pri = max(pri, price(label));
			}
		} 
		ans += pri;
	}
	fout << ans;
}
