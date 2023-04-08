#include <vector>
using namespace std;

void riprogramma(int N, int K, vector<int>& C)
{
	if (K == 2)
	{
		int count = 0;
		int cur = 1;
		for (int i = 0; i < N; i++)
		{
			if (C[i] != cur)
			{
				C[i] = cur;
				count++;
			}
			cur %= K;
			cur++;
		}
		
		if (count > N / 2)
		{
			for (int i = 0; i < N; i++)
			{
				C[i] %= K;
				C[i]++;
			}
		}
	}
	else
	{
		for (int i = 1; i < N; i++)
		{
			if (C[i - 1] == C[i])
			{
				if (i == N - 1 || C[i + 1] != (C[i] % K + 1))
				{
					C[i] %= K;
					C[i]++;
				}
				else
				{
					C[i] += 1;
					C[i] %= K;
					C[i]++;
				}
			}
		}
	}
}