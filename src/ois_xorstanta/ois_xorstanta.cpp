#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		
		int xorN;
		switch(N % 4)
		{
			case(0):
			{
				xorN = N;
				break;
			}
			case(1):
			{
				xorN = 1;
				break;
			}
			case(2):
			{
				xorN = N + 1;
				break;
			}
			case(3):
			{
				xorN = 0;
				break;
			}
			default:
			{
				break;
			}
		}
		
		int i = 0;
		int p = 32 - __builtin_clz(N);
		int mask = (1<<p)-1;
		int ans = mask + ((~xorN)&mask);
		cout << ans << "\n";
	}
	
	
	return 0;
}
