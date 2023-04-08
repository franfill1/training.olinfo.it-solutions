#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

unordered_map < string , int > enc;
unordered_map < int , string > decc;

vector < int > T;
vector < int > occ;

void upd (int n)
{
	if (n < 0) return;
	int ne1 = n*2 + 1;
	int ne2 = n*2 + 2;
		
	if (ne1 < T.size() && ne2 < T.size())
	{
		int va1 = T[ne1], va2 = T[ne2];
		if (occ[va1] > occ[va2])
		{
			T[n] = va1;
		}
		else if (occ[va1] < occ[va2])
		{
			T[n] = va2;
		}
		else if (decc[va1] < decc[va2])
		{
			T[n] = va1;
		}
		else
		{
			T[n] = va2;
		}
	}
	else if (ne1 < T.size())
	{
		T[n] = T[ne1];
	}
	else if (ne2 < T.size())
	{
		T[n] = T[ne2];
	}
	
	if (n != 0) upd((n-1)/2);
	return;
}

int main()
{
	int N, Te;
	fin >> N >> Te;
	
	vector < string > tre(N);
	int ma = 0;
	for (int i = 0; i < N; i++)
	{
		fin >> tre[i];
		if (enc.count(tre[i]) == 0)
		{
			enc[tre[i]] = ma;
			ma++;
		}
		decc[enc[tre[i]]] = tre[i];
	}
	
	T.resize(ma * 2 - 1, 0);
	occ.resize(ma + 1);
	for (int i = 0; i < Te; i++)
	{
	    if (enc[tre[i]] >= occ.size()) return 1;
		occ[enc[tre[i]]]++;
	}

	for (int i = 0; i < enc.size(); i++)
	{
		T[i + enc.size() - 1] = i;
	}
	for (int i = T.size() - 1; i >= 0; i--)
	{
		upd(i);
	}
	fout << decc[T[0]] << "\n";
	for (int i = 0; i < N-Te; i++)
	{
		occ[enc[tre[i]]]--;
		occ[enc[tre[i+Te]]]++;
		upd(enc[tre[i]] + enc.size() - 1);
		upd(enc[tre[i+Te]] +enc.size() - 1);

		fout << decc[T[0]] << "\n";
	}
}
