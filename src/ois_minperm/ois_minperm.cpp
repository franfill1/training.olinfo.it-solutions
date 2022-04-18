#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector < int > P(N);
	for (int &x : P) 
	{
		cin >> x;
		x--;
	}
	vector < int > D(K);
	for (int &d : D) cin >> d;
	
	vector < int > C(N, -1);
	vector < vector < int > > S;
	for (int i = 0; i < N; i++)
	{
		if (C[i] == -1)
		{
			int c = S.size();
			C[i] = c;
			S.push_back({});
			S[c].push_back(P[i]);
			queue < int > q;
			q.push(i);
			while(!q.empty())
			{
				int x = q.front();
				q.pop();
				for (int k = 0; k < K; k++)
				{
					int d = D[k];
					int y = x+d;
					if (y < N && C[y] == -1)
					{
						C[y] = c;
						q.push(y);
						S[c].push_back(P[y]);
					}
					y = x-d;
					if (y >= 0 && C[y] == -1)
					{
						C[y] = c;
						q.push(y);
						S[c].push_back(P[y]);
					}
				}
			}
		}
	}
	
	for (int c = 0; c < S.size(); c++) sort(S[c].rbegin(), S[c].rend());
	vector < int > np(N);
	for (int i = 0; i < N; i++)
	{
		np[i] = S[C[i]].back();
		S[C[i]].pop_back();
	}
	for (int i = 0; i < N; i++)
	{
		cout << np[i]+1 << " ";
	}
	cout << "\n";

}


