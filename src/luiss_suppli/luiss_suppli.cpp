#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector < int > suppli;

bool canSum(int sum)
{
	if (sum == 0)
	{
		return true;
	}
	else if (sum < 0)
	{
		return false;
	}
	else
	{
		bool ans = false;
		for (int i = 0; i < suppli.size(); i++)
		{
			if (canSum(sum - suppli[i]))
			{
				ans = true;
			}
		}

		return ans;
	}
	
}

int main()
{
	int N;
	fin >> N;
	
	suppli.resize(N);
	for (int i = 0; i < N; i++)
	{
		fin >> suppli[i];
	}
	
	int mi = suppli[0];
	for (int i = 0; i < N; i++)
	{
		mi = min(suppli[i], mi);
	}
	
	int combo = 0;
	int lastNot = -1;
	
	int i = 0;
	cout << mi << "\n";
	while(combo < mi)
	{
		if (canSum(i))
		{
			combo++;
			cout << i << " ok" << "\n";
		}
		else
		{
			combo = 0;
			lastNot = i;
		}
		i++;
	}
	
	fout << lastNot;
}
