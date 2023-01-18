#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int hb=100000, vb=100000, ht=0, vt=0, x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		ht += x;
		hb = min(hb, x);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		vt += x;
		vb = min(vb, x);
	}
	if (ht < vt)
		cout << "Hamilton\n";
	else
		cout << "Verstappen\n";
	if (hb < vb)
		cout << "Hamilton\n";
	else
		cout << "Verstappen\n";
}
