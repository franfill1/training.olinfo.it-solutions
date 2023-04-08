#include<iostream>
#include<string>
#include<vector>

using namespace std;

main()
{
	int n, k;
	cin >> n >> k;
	vector < char > s;
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		while(k && s.size() && s.back() < c) 
		{
			s.pop_back();
			k--;
		}
		s.push_back(c);
	}
	while(k--)
	{
		s.pop_back();
	}
	for (char c : s) cout << c;
	cout << "\n";
}
