#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int N;
	cin >> N;
	int cnt = 0;
	char c;
	for (int i = 0; i < N; i++)
	{
	    cin >> c;
	    cnt += c == '_';
	}
	
	int K = 26 - (N - cnt);
	if (K < 0) 
	{
	    cout << 0 << "\n";
	    return 0;
	}
	long long ans = 1;
	while (cnt--) ans *= K--;
    cout << ans << "\n";
}


