#include<bits/stdc++.h>
using namespace std;

const char first = 'a'-1;
const char last = 'z'+1;
const int alphabet = last - first + 1;

template < typename T >
ostream& operator << (ostream& os, vector < T > &v)
{
	for (auto &x : v)
		os << x << " ";
	return os;
}

struct dict_of_bfact
{
	vector < vector < int > > dict;
	vector < int > suffix_array;
	dict_of_bfact(string s) : dict(0)
	{
		s += first;
		int N = s.size();
		vector < int > arr(N), cla(N, 0);
		iota(arr.begin(), arr.end(), 0);
		sort(arr.begin(), arr.end(), [&] (int i, int j) {return s[i] < s[j];});
		int classes = 1;
		for (int i = 1; i < N; i++)
		{
			if (s[arr[i-1]] != s[arr[i]])
				classes++;
			cla[arr[i]] = classes - 1;
		}
		//cerr << "arr: " << arr << "\n";
		//cerr << "cla: " << cla << "\n";
		dict.push_back(cla);
		for (int p = 1; (1<<p) < N*2; p++)
		{
			//cerr << "ITERATION: " << p << "\n";
			vector < int > cnt(classes);
			for (int c : cla)
				cnt[c]++;
			for (int c = 1; c < classes; c++)
				cnt[c] += cnt[c-1];
			//cerr << "cnt: " << cnt << "\n";
			vector < int > narr(N);
			for (int i = N-1; i >= 0; i--)
			{
				int idx = (arr[i] - (1<<(p-1)) + N*2)%N;
				narr[--cnt[cla[idx]]] = idx;
			}
			arr = narr;
			//cerr << "arr: " << arr << "\n";
			vector < int > ncla(N, 0);
			classes = 1;
			for (int i = 1; i < N; i++)
			{
				auto a = make_pair(cla[arr[i]]  , cla[(arr[i]   + (1<<(p-1))) % N]);
				auto b = make_pair(cla[arr[i-1]], cla[(arr[i-1] + (1<<(p-1))) % N]);
				if (a != b)
					classes++;
				ncla[arr[i]] = classes - 1;
			}
			cla = ncla;
			//cerr << "cla: " << cla << "\n";
			dict.push_back(cla);
		}
		suffix_array = arr;
	}
	
	int compare(int a, int b, int l)
	{
		int p = 31 - __builtin_clz(l);
		auto pa = make_pair(dict[p][a], dict[p][a + l - (1<<p)]);
		auto pb = make_pair(dict[p][b], dict[p][b + l - (1<<p)]);
		if (pa == pb)
			return 0;
		if (pa < pb)
			return -1;
		if (pa > pb)
			return 1;
	}

	long long longest_match(int a, int b)
	{
		long long ans = 0;
		for (int p = dict.size()-1; p >= 0; p--)
			if (dict[p][a] == dict[p][b])
				ans += (1<<p), a += (1<<p), b += (1<<p);
		return ans;
	}
};

int main()
{
    int N;
    cin >> N;
	string s;
	cin >> s;
	auto d = dict_of_bfact(s);
	auto v = d.suffix_array;
	int l = 0;
	for (int i = 0; i < N; i++)
	{
		int nl = d.longest_match(v[i], v[i+1]);
		l = max(l, nl);
	}
	cout << l << "\n";
}
