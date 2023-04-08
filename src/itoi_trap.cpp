#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, L;
    cin >> N >> L;
    unordered_map < string , int > C;
    int n;
    cin >>n;
    vector < string > f(n);
    for (int i = 0; i < n; i++)
    {
    	cin >> f[i];
    	C[f[i]] = 0;
	}
	
	while(--N)
	{
		unordered_set < string > s;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string w;
			cin >> w;
			if (!s.count(w) && C.count(w))
			{
				C[w]++;
				s.insert(w);
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		cout << C[f[i]] << " ";
	}
}
