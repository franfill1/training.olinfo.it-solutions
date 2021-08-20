#include <bits/stdc++.h>

#define MAXN 2000

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

struct coord
{
	int x, y;
};

coord operator + (coord c, int n)
{
	return {c.x + n, c.y + n};
}

coord min(coord a, coord b)
{
	return {min(a.x, b.x), min(a.y, b.y)};
}
coord max(coord a, coord b)
{
	return {max(a.x, b.x), max(a.y, b.y)};
}

struct carpet
{
	coord c1{MAXN, MAXN}, c2{0, 0};
	carpet(){}
	void upd(coord c)
	{
		c1 = min(c, c1);
		c2 = max(c+1, c2);
	}
};

ostream& operator << (ostream& os, coord c)
{
	os << c.y << " " << c.x;
	return os;
}

ostream& operator << (ostream& os, carpet c)
{
	os << c.c1 << " " << c.c2;
	return os;
}

int main()
{
	int R, C, K;
	fin >> R >> C >> K;
	
	vector < carpet > V(K);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			int el;
			fin >> el;
			el--;
			if (el >= 0)
			{
				V[el].upd({R-i-1, j});
			}
		}
	}

	
	for (int i = 0; i < K; i++)
	{
		fout << V[i] << "\n";
	}
}
