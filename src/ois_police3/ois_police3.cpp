#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int N;
	cin >> N;
	ll a = 0, b = 0, w;
	while(N--)
	{
		cin >> w;
		b = min(a, b) + w;	
		swap(a, b);
	}
	cout << min(a, b) << "\n";
}
