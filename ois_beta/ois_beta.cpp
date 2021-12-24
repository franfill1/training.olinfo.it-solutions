#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	set < int > f;

	int x = -1, el;
	while(N--)
	{
		cin >> el;
		if (f.count(el))
		{
			if (x != -1 && x != el)
			{
				cout << "YES\n";
				return 0;
			}
			x = el;
		}
		f.insert(el);
	}
	cout << "NO\n";
}
