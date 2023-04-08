#include<iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;

	int A[n];
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		A[i] = a + b;
	}

	int best = -1;
	for (int i = 0; i < n; i++)
	{
		if (A[i] % 2 == 0 && best < A[i])
		{
			best = A[i];
		}
	}
	cout << best << "\n";
}
