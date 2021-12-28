#include<bits/stdc++.h>
using namespace std;

typedef pair < int , int > ii;

int best_score(int N, int K, vector<int> &monete)
{
	vector < int > memo(N + 1, -1);
	vector < int > total(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		total[i] = monete[i-1] + total[i-1];
	}
	
	deque < int > d;
	for (int i = 0; i <= N; i++)
	{
		if(i <= K) //la deque va riempita, non incremento il puntatore a sinistra
		{
			memo[i] = total[i];
		}
		else //la deque è già piena, incremento il puntatore a sinistra, e prendo l'elemento minore
		{
			if(memo[i-K-1] == d.front())
			{
				d.pop_front();
			}
			memo[i] = total[i] - d.front();
		}
		while(!d.empty() && d.back() > memo[i])
		{
			d.pop_back();
		}
		d.push_back(memo[i]);
	}
	return memo[N];
}