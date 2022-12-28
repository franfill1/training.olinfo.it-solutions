#include<bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int N;
	fin >> N;
	
	stack<int>fibonacci;
	fibonacci.push(1);
	
	int f = 0;
	int l = 1;
	while(fibonacci.top() < N)
	{
		fibonacci.push(f + l);
		f = l;
		l = fibonacci.top();
	}
	
	if (fibonacci.top() > N)
	{
		fibonacci.pop();
	}
	
	int size = fibonacci.size();
	
	bool ar[size] = {0};
	int i = 0;
	
	while(N > 0)
	{
		while(fibonacci.top() > N)
		{
			fibonacci.pop();
			i++;
		}
		ar[i] = 1;
		N -= fibonacci.top();
		fibonacci.pop();
		i++;
	}
	
	for (int i = size - 1; i >= 0; i--)
	{
		fout << ar[i];
	}
	
	return 0;
}

