#include <bits/stdc++.h>

using namespace std;

int main ()
{
	ifstream fin;
	fin.open("input.txt");
	ofstream fout;
	fout.open("output.txt");
	
	
	int N;
	fin >> N;
	
	int ans = -1;
	for (int i = 0; i < N; i++)
	{
		int el1, el2;
		fin >> el1 >> el2;
		int sum = el1 + el2;
		
		if (sum % 2 == 0)
		{
			if (sum > ans)
			{
				ans = sum;
			}
		}
	}
	
	fout << ans;
	
	return 0;
}

