#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

struct point
{
	long long x, y, i;
};

bool operator < (point a, point b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

point operator - (point a)
{
	return {-a.x, -a.y, a.i};
}

point operator - (point a, point b)
{
	return {a.x-b.x, a.y-b.y, 0};
}

long long operator ^ (point p, point q)
{
	return p.x * q.y - p.y * q.x;
}

long long sign(long long v)
{
	return (v>0)-(v<0);
}

long long side(point a, point b, point p)
{
	return sign((b-a) ^ (p-a));
}

vector < point > lower_hull(vector < point > P)
{
	sort(P.begin(), P.end());
	vector < point > res;
	res.emplace_back(P[0]);
	for (long long i = 1; i < P.size(); i++)
	{
		point p = P[i];
		while (res.size() >= 2 && side(res[res.size()-2], res.back(), p) != -1)
			res.pop_back();
		res.push_back(p);
	}
	return res;
}

vector<int> trovacerchi(int N, vector<int> X, vector<int> Y) 
{
	vector < point > P;
	for (int i = 0; i < N; i++)
		P.push_back({X[i], Y[i], i});
	P.push_back({0, 0, N});
	auto lH = lower_hull(P);
	for (auto &p : P)
		p = -p;
	auto uH = lower_hull(P);

	set < int > res;
	for (auto [x, y, i] : lH)
	{
		if (i != N)
			res.insert(i);
	}

	for (auto [x, y, i] : uH)
	{
		if (i != N)
			res.insert(i);
	}
	vector < int > vres;
	for (auto x : res)
		vres.emplace_back(x);
	return vres;
}
