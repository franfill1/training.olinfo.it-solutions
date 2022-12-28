#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

vector < bool > used;
int cur = 0;
int ans = 0;

struct tess
{
	int a, b;
};

vector < vector < int > > aToId(7);
vector < vector < int > > bToId(7);
vector < tess > t;

void test (int e)
{
	ans = max(ans, cur);
	
	for (int i : aToId[e])
	{
		if (!used[i])
		{
			used[i] = true;
			cur++;
			test(t[i].b);
			used[i] = false;
			cur--;
		}
	}
	for (int i : bToId[e])
	{
		if (!used[i])
		{
			used[i] = true;
			cur++;
			test(t[i].a);
			used[i] = false;
			cur--;
 		}
	}
}

int main()
{
	int N;
	fin >> N;
	used.resize(N);
	t.resize(N);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		fin >> a >> b;
		t[i] = {a, b};
		aToId[a].push_back(i);
		bToId[b].push_back(i);
	}
	
	for (int i = 1; i <= 6; i++)
	{
		test(i);
	}
	fout << ans;
	
}
