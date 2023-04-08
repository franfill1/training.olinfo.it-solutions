#include<iostream>
#include<iomanip>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<string>
#include<stdlib.h>
#include<fstream>

using namespace std;
main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int n;
	fin >> n;
	
	int i, j, wine[n];
	for (i=0; i<n; i++)
		fin >> wine[i];
	
	int ans[n]={1};
	for (int i = 0; i < n; i++)
	{
	    ans[i] = 1;
	}
	
	for (int i=0; i<n; i++)
	{
		for(int j=0;j < i - 1;j++)
		{
			if (wine[i]>=wine[j])
				ans[i]=max(ans[j] + 1,ans[i]);
		}
	}		
	
	int tot=0;
	
	for(i=0;i<n;i++)
		tot=max(tot,ans[i]);
		
	fout << tot;
}
