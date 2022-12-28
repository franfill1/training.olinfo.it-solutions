#include<iostream>
using namespace std;

int main()
{
 	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, M;
	cin >> N >> M;
	int f;
	cin >> f;
	
	int s;
	for (int i = 0; i < N-1; i++) cin >> s;
	
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == f) f = b;
		else if (b == f) f = a;
	}
	cout << f;
}

