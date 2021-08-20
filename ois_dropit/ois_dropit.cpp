#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N;
	fin >> N;
	stack < int > pila;
	for (int i = 0; i < N; i++)
	{
		int blo;
		fin >> blo;
		
		while(blo > 0)
		{
			if(pila.empty())
			{
				pila.push(blo);
				blo = 0;
			}
			else if(pila.top() == blo)
			{
				pila.pop();
				blo = 0;
			}
			else if(pila.top() > blo)
			{
				int diff = pila.top() - blo;
				pila.push(blo);
				pila.push(diff);
				blo = 0;
			}
			else if(pila.top() < blo)
			{
				blo -= pila.top();
				pila.pop();
			}
		}
	}
	
	stack < int > ans;
	while(!pila.empty())
	{
		ans.push(pila.top());
		pila.pop();
	}
	fout << ans.size() << "\n";
	while(!ans.empty())
	{
		fout << ans.top() << " ";
		ans.pop();
	}
}
