#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int ip = 0;
	for (int m = 0; m < M; m++)
	{
		int a, b;
		cin >> a >> b;
		if (ip == a) ip = b;
		else if (ip == b) ip = a;
	}
	cout << ip << "\n";
}

