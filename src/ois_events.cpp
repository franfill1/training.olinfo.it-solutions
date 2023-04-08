#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N, V;
	cin >> N >> V;
	int E[N], P[V];
	for (int i = 0; i < N; i++)
	{
		cin >> E[i];
	}
	for (int i = 0; i < V; i++)
	{
		cin >> P[i];
	}
	sort(E, E+N);
	sort(P, P+V);
	int ans = 0;
	int j = 0;
	for (int i = 0; i < V && j < N; i++)
	{
		if (E[j] <= P[i])
		{
			ans++;
			j++;
		}
	}
	cout << ans << "\n";
}
