#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#ifdef _WIN32
inline int getchar_unlocked() { return _getchar_nolock(); }
inline void putchar_unlocked(char c) {_putchar_nolock(c); }
#endif
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

inline __attribute__((always_inline)) void fast_write_uint(int n)
{
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { putchar_unlocked('0'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { putchar_unlocked(rev % 10 + '0'); rev /= 10;}
    while (count--) putchar_unlocked('0');
}

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int N = fast_read_int();
    
    int i1 = 0, i2 = 0, i3 = 0;
    int j1 = 0, j2 = 0, j3 = 0;
    for (int i = 0; i < N; i++)
    {
    	int t = fast_read_int();
    	int t2 = max(i2, i3) + t;
    	i3 = i2;
    	i2 = i1;
    	i1 = t2;
    	if (i != 0)
    	{
    		t2 = max(j2, j3) + t;
    		j3 = j2;
    		j2 = j1;
    		j1 = t2;
		}
	}
	fast_write_uint(max(j1, max(i2, i3)));
}
