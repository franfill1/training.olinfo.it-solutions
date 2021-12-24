#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int P[300];
ll dp[300][301][300];
int main()
{
	int A, B;
	ll K;
	cin >> A >> B >> K;
	P[0] = 1;
	for (int i = 1; i < B; i++)
	{
		P[i] = (P[i-1]*10)%A;
	}

	int f;
	ll temp = 0;
	for (int p = 0; p < B; p++)
	{
		for (int s = 0; s <= B; s++)
		{
			for (int m = 0; m < A; m++)
			{
				if (p == 0)
				{
					int c = B - s;
					if (c < 10 && c > 0 && (m + c)%A == 0) 
					{
						dp[p][s][m] = 1;
					}
					else 
					{
						dp[p][s][m] = 0;
					}
					continue;
				}
				for (int c = 1; c < 10; c++)
				{
					int ns = s + c;
					int nm = (m+(c*P[p])%A)%A;
					if (ns > B) break;
					dp[p][s][m] += dp[p-1][ns][nm];
				}
			}	
		}
		temp += dp[p][0][0];
		if (temp >= K) 
		{
			temp -= dp[p][0][0];
			f = p;
			break;;
		}
	}
	K -= temp;

	int s = 0, m = 0;
	for (int p = f; p >= 0; p--)
	{
		ll temp = 0;
		int c;
		for (c = 1; c < 10; c++)
		{
			int ns = s + c;
			int nm = (m+(c*P[p])%A)%A;

			assert(ns <= B);
			
			if (p > 0) temp += dp[p-1][ns][nm];
			else temp += (ns == B && nm == 0);
			if (temp >= K)
			{
				s = ns;
				m = nm;	
				if (p) temp -= dp[p-1][ns][nm];
				break;
			}
		}
		cout << c;
		K -= temp;
	}
	cout << "\n";
}
