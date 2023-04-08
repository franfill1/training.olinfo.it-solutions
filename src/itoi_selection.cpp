#include<vector>
#include<iostream>
using namespace std;
typedef long long ll;

int main()
{
	int n, m;
    cin >> n >> m;
    n++;
    vector < int > K(n+1);
    K[0] = -1;
    for (int i = 1; i < n; i++) cin >> K[i];
    K[n] = m;

    vector < vector < int > > dp(n+1);
	vector < short > opt(n+1, 0);
    for (int i = 0; i <= n; i++)
    {
        dp[i].resize(n-i+1, 0);
    }

    for (int l = 2; l <= n; l++)
    {
        for (int i = 0; i+l <= n; i++)
        {
			dp[i][l] = 1<<30;
			for (int q = opt[i]; q<=opt[i+1]+1; q++)
			{
				if (dp[i][l] > dp[i][q] + dp[i+q][l-q])
				{
					dp[i][l] = dp[i][q] + dp[i+q][l-q];
					opt[i] = q;
				}
			}
			if (K[i+l] - K[i] > 2) dp[i][l] += K[i+l]-K[i]-1;
        }
    }
    cout << dp[0][n] << "\n";
}
