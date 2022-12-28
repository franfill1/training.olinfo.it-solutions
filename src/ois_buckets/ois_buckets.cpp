#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	set < int > s;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		s.insert(x);
	}
	if (s.size() == N)
		cout << "Ok\n";
	else
		cout << "Impossible\n";
}
