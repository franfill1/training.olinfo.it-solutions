#include<bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

main(){
	int N, K;
	fin >> N >> K;
	
	unordered_map < string , int > m;
	string s;
	
	for (int i = 0; i < N; i++)
	{
		char c;
		fin >> c;
		s += c;
	}
	
	for (int i = 0; i <= N - K; i++)
	{
		string t;
		for (int j = i; j < i + K; j++)
		{
			t += s[j];
		}
		m[t]++;
	}
	
	string ans = "";
	for (auto it : m)
	{
		if (it.second > m[ans])
		{
			ans = it.first;
		}
	}
	for (int i = 0; i < K; i++)
	{
		fout << ans[i] << " ";
	}
}

