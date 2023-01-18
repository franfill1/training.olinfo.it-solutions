#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	stack < int > s;
	while(N--)
	{
		int x;
		cin >> x;
		while(s.size() && s.top() < x)
			s.pop();
		s.push(x);
	}
	cout << s.size() << "\n";
}
