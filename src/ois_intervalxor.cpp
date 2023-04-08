#pragma gcc Optimize("O3")
#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin >> q;
	while(q--)
	{
		int a;
		cin >> a;
		switch (a % 4) {
			case 0:
			{	
				cout << a << " " << (1<<(32-__builtin_clz(a)))-1 << "\n";
				break;
			}
			case 1:
			{
				cout << 1 << " " << a << "\n";
				break;
			}
			case 2:
			{
				cout << a+1 << " " << (1<<(32-__builtin_clz(a+1)))-1 << "\n";
				break;
			}
			case 3:
			{
				cout << 0 << " " << a << "\n";
				break;
			}
		}
	}
}
