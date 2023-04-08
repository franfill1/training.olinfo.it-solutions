#include<vector>
#include<numeric>

std::vector < std::vector < int > > cestini;

void inizia(int N, int M) {
	cestini.resize(M);
	cestini[0].resize(N);
	std::iota(cestini[0].begin(), cestini[0].end(), 0);
}

void sposta(int a, int b) {
	if (a != b && cestini[a].size())
	{
		cestini[b].push_back(cestini[a].back());
		cestini[a].pop_back();
	}
}

int controlla(int a, int i) {
	if (i >= cestini[a].size()) return -1;
    return cestini[a][i];
}
