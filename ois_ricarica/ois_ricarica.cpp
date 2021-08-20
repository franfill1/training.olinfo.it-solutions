#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef long long ll;

int main()
{
	int N;
	ll M;
	fin >> N >> M;
	
	ll pow = 0;
	ll ans = 0;
	ll A, B = 0;
	for (int i = 0; i < N; i++)
	{
		fin >> A;
		pow -= A - B - 1;
		ans = min(ans, pow);
		fin >> B;
		pow += B - A + 1;
	}
	pow -= M - B;
	ans = min(ans, pow);
	fout << max(0ll, -ans) + 1ll;
}
