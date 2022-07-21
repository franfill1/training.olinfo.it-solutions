#include<bits/stdc++.h>
using namespace std;

const int alphabet_size = 27;

vector < int > suffix_array(string s)
{
	int n = s.size();
	vector < int > ord(n);
	vector < int > pos(n);
	int class_count = alphabet_size;
	vector < int > cnt(class_count, 0);
	for (int i = 0; i < n; i++)
	{
		cnt[s[i] - 'a'+1]++;
	}
	for (int i = 1; i < class_count; i++)
	{
		cnt[i] += cnt[i - 1];
	}
	for (int i = n-1; i >= 0; i--)
	{
		ord[--cnt[s[i] - 'a'+1]] = i;
	}
	pos[ord[0]] = 0;
	class_count = 1;
	for (int i = 1; i < n; i++)
	{
		if (s[ord[i]] != s[ord[i-1]])
		{
			class_count++;
		}
		pos[ord[i]] = class_count-1;
	}

	for (int p = 0; 1<<(p-1) < n; p++)
	{
		vector < int > nord(n);
		for (int i = 0; i < n; i++)
		{
			nord[i] = ((ord[i] - (1<<p)) % n + n) % n;
		}
		cnt.assign(class_count, 0);
		for (int i = 0; i < n; i++)
		{
			cnt[pos[i]]++;
		}
		for (int i = 1; i < class_count; i++)
		{
			cnt[i] += cnt[i-1];
		}
		for (int i = n-1; i >= 0; i--)
		{
			ord[--cnt[pos[nord[i]]]] = nord[i];
		}
		vector < int > npos(n);
		npos[ord[0]] = 0;
		class_count = 1;
		for (int i = 1; i < n; i++)
		{
			if (pos[ord[i-1]] != pos[ord[i]] || pos[(ord[i-1] + (1<<p)) % n] != pos[(ord[i] + (1<<p))% n])
			{
				class_count++;
			}
			npos[ord[i]] = class_count-1;
		}
		pos = npos;
	}

	return ord;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	s += 'a'-1;
	auto v = suffix_array(s);
	for (int i = 1; i < s.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << "\n";
}
