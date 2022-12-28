#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
vector<long long> calcola(int T, int M, vector<long long> S, vector<long long> P) {
    vector<long long> R(M);
	vector < int > p(M);
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&] (int i, int j) 
			{
				return P[i] < P[j];
			});
	long long cnt = S[0], tot = 0;
	int j = 0;
	for (int i = 1; i < T; i++)
	{
		while (j < M && tot+S[i]*i > P[p[j]])
		{
			R[p[j]] = cnt + (P[p[j]] - tot)/i;
			j++;
		}
		cnt += S[i];
		tot += S[i]*i;
	}
	for (; j < M; j++)
		R[p[j]] = cnt;

    return R;
}
