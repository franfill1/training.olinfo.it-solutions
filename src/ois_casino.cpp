#include<bits/stdc++.h>
using namespace std;

inline string rotate(string s)
{
	s += s;
	int n = s.size(), i=0, ans;
	while(i < n/2)
	{
		ans = i;
		int k = i, j = k+1;
		while(j < n && s[j] >= s[k])
		{
			if (s[j] > s[k])
				k = i;
			else
				k++;
			j++;
		}
		while(i <= k)
			i += j-k;
	}
	return s.substr(ans, n/2);
}

int main()
{
	string s;
	getline(cin, s);
	int ans = 0;
	map < string , int > occ;
	while(getline(cin, s))
		ans += occ[rotate(s)]++;
	cout << ans << "\n";
}
