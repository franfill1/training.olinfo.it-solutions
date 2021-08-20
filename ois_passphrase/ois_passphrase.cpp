#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	
	vector < char > s;
	for (int i = 0; i < n; i++)
	{
		char c; cin >> c;
		while(k && !s.empty() && s.back() < c)
		{
			s.pop_back();
			k--;
		}
		s.push_back(c);	
	}

	for (int i = 0; i < s.size()-k; i++) cout << s[i];
	cout << "\n";
}
