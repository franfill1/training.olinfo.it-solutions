#include<bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

main(){
	int N;
	fin >> N;
	vector < int > P(N);
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		fin >> P[i];
		ans += P[i];
	}
	
	sort(P.begin(), P.end(), greater < int > ());
	for (int i = 2; i < N; i += 3)
	{
		ans -= P[i];
	}
	fout << ans;
}

