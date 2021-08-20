#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int merges(vector < int > &V, vector < int > &T, int l, int mid, int r);

int mergesort(vector < int > &V, vector < int > &T, int l, int r)
{
	int invCount = 0;
	if (r > l)
	{
		int mid = (l + r) /2;
		invCount += mergesort(V, T, l, mid);
		invCount += mergesort(V, T, mid+1, r);
		invCount += merges(V, T, l, mid, r);
	}
	return invCount;
}

int merges(vector < int > &V, vector < int > &T, int l, int mid, int r)
{
	int invCount = 0;
	int i = l, j=mid+1, k=l;
	while(i <= mid && j <= r)
	{
		if (V[i] <= V[j])
		{
			T[k++] = V[i++];
		}
		else
		{
			T[k++] = V[j++];
			invCount += (mid - i+1);
		}
	}
	
	while(i <= mid)
	{
		T[k++] = V[i++];
	}
	while(j <= r)
	{
		T[k++] = V[j++];
	}
	
	for (int i = l; i <= r; i++)
	{
		V[i] = T[i];
	}
	return invCount;
}

int main()
{
	int Te;
	fin >> Te;
	while(Te--)
	{
		int N;
		fin >> N;
		vector < int > V(N), T(N);
		vector < int > P(N);
		for (int i = 0; i <N; i++)
		{
			fin >> V[i];
			P[V[i]-1] = i;
		}
		int c = mergesort(V, T, 0, N-1);
		int ans = c;
		for (int i = 0; i < N; i++)
		{
			c += N - 2 * P[i] - 1;
			ans = min(ans, c);
		}
		fout << ans << "\n";
	}
}
