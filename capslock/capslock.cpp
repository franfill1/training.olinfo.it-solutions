#include <bits/stdc++.h>

using namespace std;

ifstream fin;
ofstream fout;

int main ()
{
	fin.open("input.txt");
	fout.open("output.txt");
	
	int N;
	fin >> N;
	string s = "";
	fin.get();
	for (int i = 0; i < N; i++)
	{
		char c = fin.get();
		if (isupper(c))
		{
			c = tolower(c);
		}
		else if (islower(c))
		{
			c = toupper(c);
		}
		
		s += c;
	}
	
	fout << s;
	
	return 0;
}

