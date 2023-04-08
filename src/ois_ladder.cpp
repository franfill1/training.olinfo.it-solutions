#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int A[n];
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	int ans = A[0];
	for (int i = 1; i < n; i++)
	{
		if (A[i] - A[i-1] > ans)
		{
			ans = A[i] - A[i-1];
		}
	}
	cout << ans << "\n";
}
