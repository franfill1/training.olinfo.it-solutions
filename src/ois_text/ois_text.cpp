#include <bits/stdc++.h>

using namespace std;

ifstream fin;
ofstream fout;

int main ()
{
	fin.open("input.txt");
	fout.open("output.txt");
	
	int N, K;
	fin >> N >> K;
	
	string ans = "";
	
	int spaceLeft = K;	
	
	for (int i = 0; i < N; i++)
	{
		string word;
		fin >> word;
		
		int size = word.length();
		
		if (size <= spaceLeft)
		{
			ans += word + " ";
			spaceLeft -= size + 1;
		}
		else
		{
			spaceLeft = K;
			ans += "\n" + word + " ";
			spaceLeft -= size + 1;
		}
	}
	
	fout << ans;
	
	return 0;
}