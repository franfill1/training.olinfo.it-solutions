#include<fstream>

using namespace std;

typedef unsigned long long int ull;

main (){
	ifstream fin ("input.txt");
	ofstream fout ("output.txt");
	
	ull N;
	fin >> N;
	int n;
	
	int ans[101];
	for (int i = 100; i >= 0; i--)
	{
	    ans[i] = 0;
	}
	
	for (ull i = 0; i < N; i++)
	{
	    fin >> n;
	    for (int j = 0; j < 101; j++)
	    {
	        ans[j] += n >= j;
	    }
	}
	for (int i = 100; i >= 0; i--)
	{
	    fout << ans[i] << " ";
	}
}