#include<iostream>
using namespace std;

int main()
{
	int N, D;
	cin >> N >> D;
	int P[N];
	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
	}
	
	int i = 0;
	long long ans = 0;
	for (int j = 0; j < N; j++)
	{
		while(P[j] - P[i] >= D)
		{
			i++;
		}
		ans += j - i;
	}
	cout << ans << "\n";
}
