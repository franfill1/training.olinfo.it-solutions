#include<iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	cin >> N;

	int A[N];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	
	int par1=-1, par2=-1;
	int dis1=-1, dis2=-1;
	for (int i = 0; i < N; i++)
	{
		if (A[i] % 2 == 0)
		{
			if (A[i] > par1)
			{
				par2 = par1;
				par1 = A[i];
			}
			else if (A[i] > par2)
			{
				par2 = A[i];
			}
		}
		else
		{
			if (A[i] > dis1)
			{
				dis2 = dis1;
				dis1 = A[i];
			}
			else if (A[i] > dis2)
			{
				dis2 = A[i];
			}
		}
	}
	
	int ans = -1;
	if (par1 + par2 > dis1 + dis2 && par2 != -1)
	{
		ans = par1 + par2;
	}
	else if (dis2 != -1)
	{
		ans = dis1 + dis2;
	}
	
	cout << ans;
}
