#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
    int B;
    fin >> B;
    
    unordered_set < string > bad;
    for (int i = 0; i < B; i++)
    {
    	string w;
    	fin >> w;
    	bad.insert(w);
	}
	
	int G;
	fin >> G;
	
	unordered_set < string > good;
	for (int i = 0; i < G; i++)
	{
		string w;
		fin >> w;
		good.insert(w);
	}
	
	int E;
	fin >> E;
	int goc = 0, bac = 0;
	
	while(E--)
	{
		int N;
		fin >> N;
		bool g = false;
		bool b = false;
		
		for (int i = 0; i < N; i++)
		{
			string w;
			fin >> w;
			if (bad.count(w))
			{
				b = true;
			}
			if (good.count(w))
			{
				g = true;
			}
		}
		
		if (b && !g)
		{
			bac++;
		}
		if (g && !b)
		{
			goc++;
		}
	}
	fout << bac << " " << goc << "\n";
}
