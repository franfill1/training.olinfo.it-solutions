#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")

inline __attribute__((always_inline)) int fast_read_int()
{
    int c, n = 0;
    do
    {
        c = getchar_unlocked();
    } while (c < '0' || c > '9');
    do
    {
        n = (n << 3) + (n << 1) + (c - '0');
        c = getchar_unlocked();
    } while (c >= '0' && c <= '9');
    return n;
}

inline __attribute__((always_inline)) bool fast_read_bool()
{
    int c;
    do
    {
        c = getchar_unlocked();
    } while (c != '0' && c != '1');
    return c == '1';
}

int D[100001];
vector < int > r[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int N = fast_read_int();
	for (int i = 0; i < N; i++) D[i]=fast_read_int();
	
	stack<int> s;

	for (int i = N-1; i+1; i--)
	{		
		while(!s.empty() && D[s.top()] >= D[i]) s.pop();
		if (!s.empty()) 
		{
			r[s.top()].push_back(i);
		}
		s.push(i);
	}

	while(s.size()) s.pop();

	set < int > l;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int &k : r[i])
		{
			l.erase(k);
		}
		l.insert(i);

		while(!s.empty() && D[s.top()] <= D[i]) s.pop();
		int b = s.size() ? s.top() : -1;
		s.push(i);

		auto it = l.upper_bound(b);
		if (it != l.end())
		{
			int a = *it;
			ans = max(i-a+1, ans);
		}
	}
	cout << ans;
}
