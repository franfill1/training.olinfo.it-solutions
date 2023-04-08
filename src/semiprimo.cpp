#include<bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int N;
	fin >> N;
	
	vector < bool > prime(N , true);
	
	int first = 0;
	int second = 0;
	
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i < prime.size(); i++)
	{
		if (prime[i])
		{
			if (N % i == 0 && first == 0)
			{
				first = i;
				N = N / i;
				if (N <= i && prime[N])
				{
					second = N;
					break;
				}
				if (N == 1)
				{
					break;
				}
			}
			if (first != 0 && N == i)
			{
				second = N;
				break;
			}
			
			for (int j = 2; i * j < prime.size(); j++)
			{
				prime[i * j] = false;
			}
		}
	
	}
	if (second != 0)
	{
		fout << first << " " << second;
	}
	else
	{
		fout << "-1";
	}

	
	
	return 0;
}
