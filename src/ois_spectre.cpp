#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int n;
	fin >> n;

	set < string > u;
	int ans = 0;

	string a, b, c;
	char s;

	for (int i = 0; i < n; i++)
	{
		fin >> a >> s >> b >> s >> c;
		if (!u.count(b) && !u.count(c))
			ans++;
		u.insert(a);
	}
	fout << ans << "\n";
}
