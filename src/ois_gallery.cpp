#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map < double , vector < double > > m;
	for (int i = 0; i < n; i++)
	{
		double x, y; cin >> x >> y;
		m[y].push_back(x);
	}

	double ax;
	for (double x : (*m.begin()).second)
	{
		ax += x;
	}
	
	ax /= ((*m.begin()).second).size();

	for (auto &p : m)
	{
		vector < double > v = p.second;
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			if (ax - v[i] != v[v.size()-i-1] - ax)
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
}
