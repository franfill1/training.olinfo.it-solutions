#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N;
	fin >> N;
	vector < string > Q(N);
	for (int i = 0; i < N; i++)
	{
		fin >> Q[i];
	}
	
	unordered_map < string , string > en;
	for (int i = 0; i < 10; i++)
	{
		string e;
		fin >> e;
		en[e] = i + '0';
	}
	
	for (int i = 0; i < N; i++)
	{
		string ans = "";
		string temp = "";
		for (char ch : Q[i])
		{
			temp += ch;
			if (en.count(temp))
			{
				ans += en[temp];
				temp = "";
			}
		}
		fout << ans << "\n";
	}
}
