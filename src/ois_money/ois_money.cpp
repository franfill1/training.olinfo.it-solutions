#include <fstream>
#include <vector>

using namespace std;

int main ()
{
	ifstream fin ("input.txt");
	ofstream fout ("output.txt");
	
	int N, M;
	fin >> N >> M;
	
	int m[N];
	
	for (int i = 0; i < N; i++) m[i] = 0;
	
	for (int i = 0; i < M; i++)
	{
		int a, b, w;
		fin >> a >> b >> w;
		
		m[a] -= w;
		m[b] += w;
	}
	
	int K = 0;
	vector < vector < int > > ans;
	ans.resize(0);
	
	for (int i = 0; i < N - 1; i++)
	{
		vector < int > v;
		v.resize(3);
		if (m[i] == 0) continue;
		if (m[i] > 0)
		{
			v[0] = i;
			v[1] = i + 1;
			v[2] = m[i];
		}
		else
		{
			v[0] = i + 1;
			v[1] = i;
			v[2] = -m[i];
		}
		m[i + 1] += m[i];
		++K;
		ans.push_back(v);
	}
	
	fout << K << "\n";
	
	for (int i = 0; i < K; i++)
	{
		fout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
	}
	return 0;
}
