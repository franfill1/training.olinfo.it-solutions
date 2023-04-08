#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#ifdef _WIN32
inline int getchar_unlocked() { return _getchar_nolock(); }
inline int putchar_unlocked(char c) { _putchar_nolock(c); }
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

#define MAXH 2000

using namespace std;

int main()
{
	int N = fast_read_int();
	int V[N];
	for (int i = 0; i < N; i++) V[i] = fast_read_int();
	
	int lastUp[MAXH+1];
	int lastDown[MAXH+1];
	
	lastUp[0] = V[N-1] * V[N-1];
	for (int i = 1; i <= MAXH; i++)
	{
		lastUp[i] = min(lastUp[i-1], (i - V[N-1]) * (i - V[N-1]));
	}
	
	lastDown[MAXH] = (MAXH - V[N-1]) * (MAXH - V[N-1]);
	for (int i = MAXH-1; i > 0; i--)
	{
		lastDown[i] = min(lastDown[i+1], (i - V[N-1]) * (i - V[N-1]));
	}

	for (int n = N-2; n >= 0; n--)
	{
		int buffUp[MAXH+1];
		buffUp[MAXH] = 1<<30;
		for (int i = 0; i < MAXH; i++)
		{
			buffUp[i] = (i - V[n]) * (i - V[n]) + lastDown[i+1];
		}
		int buffDown[MAXH+1];
		buffDown[0] = 1<<30;
		for (int i = MAXH; i > 0; i--)
		{
			buffDown[i] = (i - V[n]) * (i - V[n]) + lastUp[i-1];
		}
		
		lastUp[0] = buffUp[0];
		for (int i = 1; i <= MAXH; i++)
		{
			lastUp[i] = min(lastUp[i-1], buffUp[i]);
		}
		
		lastDown[MAXH] = buffDown[MAXH];
		for (int i = MAXH-1; i >= 0; i--)
		{
			lastDown[i] = min(lastDown[i+1], buffDown[i]);
		}
	}
	
	fast_write_uint(min(lastDown[0], lastUp[MAXH]));
}
