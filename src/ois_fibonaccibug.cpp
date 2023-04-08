#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")

typedef unsigned long long ll;
inline __attribute__((always_inline)) unsigned int fast_read_int()
{
    unsigned int c, n = 0;
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

inline __attribute__((always_inline)) void fast_write_uint(ll n)
{
    ll N = n, rev; int count = 0;
    rev = N;
    if (N == 0) { putchar_unlocked('0'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { putchar_unlocked(rev % 10 + '0'); rev /= 10;}
    while (count--) putchar_unlocked('0');
}

int main()
{
	static const unsigned int fib[25] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025};
	unsigned int N, K, A, T, j, B;
	ll l[100001];
	
	T = fast_read_int();
	while(T--)
	{
		N = fast_read_int(); K = fast_read_int();
		std::fill(l, l+K+1, 0);
		while(N--)
		{
			A = fast_read_int(); B = fast_read_int();
			if (A < 25)
			{
        		for (j = A = fib[A]; l[j-A] + B >= l[j]; j++)
        		{
        			l[j] = l[j-A] + B;
        		}
			}
		}
		fast_write_uint(l[K]);
		putchar_unlocked('\n');
	}
}