#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#ifdef _WIN32
inline int getchar_unlocked() { return _getchar_nolock(); }
inline putchar_unlocked(char c) { _putchar_nolock(c); }
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

#define maxv 400001

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N = fast_read_int(), B = fast_read_int();
	bitset<maxv> knap;
	
	unordered_map < int , int > cnt;
	for (int i = 0; i < N; i++) cnt[fast_read_int()]++;

	knap.set(0, 1);
	int sum = 0;
	for (pair < int , int > p : cnt)
	{
		int x = p.first, occ = p.second;
		for (int z = 0; (1<<z) < occ; z++)
		{
			knap |= knap << (x<<z);
			occ -= 1<<z;
		}
		knap |= knap << (x*occ);
	}
	fast_write_uint(knap._Find_next(B-1));
}
