#include<bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int N;
	fin >> N;
	
	vector < int > carte(N);
			
	int totOnes = 0;
	int totZeros = 0;
	
	for (int i = 0; i < N; i++)
	{
		fin >> carte[i];
		
		totOnes += carte[i] % 2;
		totZeros += !(carte[i] % 2);
	}
		
	vector <int> r(0);
	
	int ones = 0;
	int zeros = 0;
	
	
	for (int i = 0; i < N; i++)
	{
		int carta = carte[i];
		
		if (carta % 2 && ones >= zeros && (totOnes - ones) > (totZeros - zeros))
		{
			r.push_back(carta);
		}
		else if (!(carta % 2) && ones <= zeros && (totOnes - ones) < (totZeros - zeros))
		{
			r.push_back(carta);
		}
		
		ones += carta % 2;
		zeros += !(carta % 2);	
	}
	
	fout << r.size() << "\n";
	
	for (int i = 0; i < r.size(); i++)
	{
		fout << r[i] << " ";
	}
	
	
	return 0;
}

