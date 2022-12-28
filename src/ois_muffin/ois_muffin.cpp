#include<iostream>
using namespace std;

int main()
{
 	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, K;
	cin >> N >> K;
	int T[N];
	for (int i = 0; i < N; i++)
	{
		cin >> T[i];
	}
	
	int sum = 0;
	for (int i = 0; i < K; i++) 
	{
		sum += T[i];
	}
	
	int ans = sum;
	for (int i = K; i < N; i++)
	{
		sum += T[i] - T[i-K];
		if (sum > ans)
		{
			ans = sum;
		}
	}
	cout << ans << "\n";
}
