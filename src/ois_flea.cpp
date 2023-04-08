#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int d = 0;
	for (char c : s)
		if (c == 'R')
			d++;
		else
			d--;
	cout << abs(d) << "\n";
}
