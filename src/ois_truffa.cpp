#include<iostream>
#include<algorithm>
#include<vector>

int main()
{
	std::freopen("input.txt", "r", stdin);
	std::freopen("output.txt", "w", stdout);
	int N;
	std::cin >> N;
	int val = 0;
	std::vector < int > V;
	for (int i = 0; i < N; i++)
	{
		int e;
		std::cin >> e;
		if (e < 0) V.emplace_back(2*e);
		val += e;
	}
	int i = 0;
	std::sort(V.begin(), V.end());
	while(val <= 0)
	{
		val -= V[i++];
	}
	std::cout << i << "\n";
}
