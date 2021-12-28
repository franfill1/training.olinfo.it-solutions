#include<iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int A[N];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	
	int sum = A[0];
	for (int i = 1; i < N; i++)
	{
		if (A[i] == -1)
		{
			A[i] = A[i-1];
		}
		sum += A[i];
	}
	cout << sum;
}
