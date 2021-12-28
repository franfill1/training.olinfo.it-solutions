#include <string>
#include <vector>
using namespace std;

int chiedi(int K);
void rispondi(string S);

void indovina(int N)
{
	string S = "";
	for (int i = 0; i < N; i++)
	{
		S += ' ';
	}

	int mCur = (N * (N + 1) ) / 2;
	int cur = mCur;
	
	vector < bool > found(N, false);
	
	for (int i = N - 1; i > 0; i--)
	{
		int curAns = chiedi(cur);
		found[curAns - 1] = true;
		S[N - curAns] = i + 'a';
		cur -= curAns;
	}
	
	for (int i = 0; i < N; i++)
	{
		if (!found[i])
		{
			S[N - i - 1] = 'a';
			break;
		}
	}
	
	rispondi(S);
}
