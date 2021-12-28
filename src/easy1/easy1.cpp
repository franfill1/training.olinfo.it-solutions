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
		cin >> A[i];
	}

	int best = -1000;
	for (int i = 0; i < n; i++)
	{
		if (A[i] > best)
		{
			best = A[i];
		}
	}

	cout << best << "\n";
}
