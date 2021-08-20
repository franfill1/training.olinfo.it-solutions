#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N;
	fin >> N;
	
	unordered_map < int , int > m; //ad ogni altezza associa il numero di registrazioni dell'altezza
	vector < int > freq(105000, 0); //ad ogni altezza associa il numero di registrazioni dell'altezza
	
	int h = 5000;
	freq[h]++;
	for (int i = 0; i < N; i++)
	{
		int delta;
		fin >> delta;
		h += delta;
		freq[h]++;
	}
	
	int ans = 5000;
	for (int i = 0; i < freq.size(); i++)
	{
		int hei = i;
		int fre = freq[i];
		
		if (fre > freq[ans])
		{
			ans = hei;
		}
	}
	fout << ans;
}
