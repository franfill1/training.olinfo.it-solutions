#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N, V;
	cin >> N >> V;
	vector < pair < int , int > > A(N), B(N);
	for (auto &[d, p] : A) cin >> d >> p;
	for (auto &[d, p] : B) cin >> d >> p;
	
	int mi = N, ma = -1;
	for (int i = 0; i < N; i++) if (A[i] != B[i])
	{
		mi = min(mi, i);
		ma = max(ma, i);
	}
	if (mi == N)
	{
		cout << "SAME";
		return 0;
	}
	
	ma++;

	{
		bool dur_eq = true, dur_halv = true, dur_dub = true;
		int diff;
		bool diff_found = false, can_dif = true;
		for (int i = mi; i < ma; i++)
		{
			auto &[d, p] = A[i];
			auto &[d2, p2] = B[i];
			//cerr<< d << " " << p << ":" << d2 << " " << p2 << "\n";
			if (d != d2) dur_eq = false;
			if (d*2 != d2) dur_halv = false;
			if (d != d2*2) dur_dub = false;

			if (diff_found && p-p2 != diff) can_dif = false;
			if (!diff_found)
			{
				diff = p-p2;
				diff_found = true;
			}
		}
		//cerr << dur_eq << " " << dur_halv << " " << dur_dub << "\n";
		//cerr << can_dif << "\n"v

		if (can_dif && (dur_eq || dur_halv || dur_dub))
		{
			cerr << ma-mi << "\n";
			cout << "TRANSFORMED " << ma-mi;
			return 0;
		}
	}
	{
		//cerr << mi << " " << ma << "\n";
		bool dur_eq = true, dur_halv = true, dur_dub = true;
		int diff;
		bool diff_found = false, can_dif = true;
		for (int i = mi; i < ma; i++)
		{
			auto &[d, p] = A[i];
			auto &[d2, p2] = B[ma+mi-i-1];
			//cerr<< d << " " << p << ":" << d2 << " " << p2 << "\n";
			if (d != d2) dur_eq = false;
			if (d*2 != d2) dur_halv = false;
			if (d != d2*2) dur_dub = false;

			if (diff_found && p-p2 != diff) can_dif = false;
			if (!diff_found)
			{
				diff = p-p2;
				diff_found = true;
			}
		}
		//cerr << dur_eq << " " << dur_halv << " " << dur_dub << "\n";
		//cerr << can_dif << "\n"v

		if (can_dif && (dur_eq || dur_halv || dur_dub))
		{
			cerr << ma-mi << "\n";
			cout << "TRANSFORMED " << ma-mi;
			return 0;
		}
	}
	cout << "ORIGINAL " << ma-mi;
}
