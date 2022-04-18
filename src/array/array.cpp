#include<iostream>
int main()
{
	int N, M, s=0, e;
	std::cin >> N;
	M = N;
	while(N--)
	{
		std::cin >> e;	
		s += e;
	}
	std::cout << s << " " << double(s) / M << "\n";
}
