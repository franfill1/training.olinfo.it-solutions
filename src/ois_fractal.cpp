#include <bits/stdc++.h>
#define mod 32749

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

void pro (vector < vector < int > > a, vector < vector < int > > b, vector < vector < int > > &r)
{
	r[0][0] = ((((a[0][0] * b[0][0])%mod) + ((a[0][1] * b[1][0])%mod))%mod);
	r[0][1] = ((((a[0][0] * b[0][1])%mod) + ((a[0][1] * b[1][1])%mod))%mod);
	r[1][0] = ((((a[1][0] * b[0][0])%mod) + ((a[1][1] * b[1][0])%mod))%mod);
	r[1][1] = ((((a[1][0] * b[0][1])%mod) + ((a[1][1] * b[1][1])%mod))%mod);
}

void modpow(vector < vector < int > > &m, int e)
{
	if (e == 0)
	{
		m[0][0] = 1;
		m[0][1] = 0;
		m[1][0] = 0;
		m[1][1] = 1;
		return;
	}
	
	if (e % 2)
	{
		vector < vector < int > > t = m;
		modpow(m, e/2);
		pro(m, m, m);
		pro(t, m, m);
	}
	else
	{
		modpow(m, e/2);
		pro(m, m, m);
	}
}

int main()
{
	int N;
	fin >> N;
	
	vector < vector < int > > M(2, vector < int > (2));
	M[0][0] = 3;
	M[0][1] = 2;
	M[1][0] = 3;
	M[1][1] = 3;
	
	modpow(M, N);
	
	fout << (M[0][0] % mod) << " " << (M[1][0] % mod);
}
