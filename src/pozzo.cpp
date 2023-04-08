#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, d;
	cin >> n >> d;
	vector < pair < int , int > > g(n);
	int sum = 0;
	for (auto &[h, l] : g) 
	{
		cin >> h >> l;
		sum += h;
	}

	sort(g.begin(), g.end(), [] (pair <int,int> a, pair <int,int> b)
			{
				return a.first + a.second < b.first + b.second;
			});

	priority_queue < int > pq;
	int ans = 0;
	for (auto [h, l] : g)
	{
		cerr << h << " " << l << "\n";
		if (sum + l >= d)
		{
			ans++;
			sum -= h;
			pq.push(h);
		}
		else if (pq.size() && pq.top() > h)
		{
			sum -= h;
			sum += pq.top();
			pq.pop();
			pq.push(h);
		}
	}
	cout << ans << "\n";
}
