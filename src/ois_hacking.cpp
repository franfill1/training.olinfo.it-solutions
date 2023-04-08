#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	map < int , priority_queue < int , vector < int > , greater < int > > > P;
	for (int i = 0; i < N; i++)
	{
		int el;
		cin >> el;
		int p = el-2;
		if (!P[p].empty())
		{
			P[el].push(P[p].top());
			P[p].pop();
		}
		else
		{
			P[el].push(el);
		}
	}

	int ans = 0;
	for (auto &[k, pq] : P)
	{
		while(!pq.empty())
		{
			int v = pq.top();
			pq.pop();
			if (v != -k)
			{
				cout << 0 << "\n";
				return 0;
			}
			ans++;
		}
	}
	cout << ans << "\n";
}
