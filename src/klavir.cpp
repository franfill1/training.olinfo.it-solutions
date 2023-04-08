#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#include<iostream>
#include<vector>
#include<bitset>

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

inline __attribute__((always_inline)) void fast_write_uint(uint n)
    {
        fast_write_uint((int)n);
    }

inline __attribute__((always_inline)) void fast_write_int(int n)
    {
        if (n < 0) {
            putchar_unlocked('-');
            n*=-1;
        }
        fast_write_uint(n);
    }

const long long mod = 1000000007;
using namespace std;
#define maxm 1000001
int S[maxm], Z[maxm];
bitset < 100 > P[maxm];
vector < int > us[maxm];
long long DP[maxm];

int main()
{
    int n = fast_read_int(), m = fast_read_int();
    for (int i = 0; i < m; i++) 
    {
        S[i] = fast_read_int()-1;
    }

    int l=0, r=0;
    Z[0] = m;
    for (int i = 1; i < m; i++)
    {
        if (i + Z[i-l] >= r)
        {
            r = max(r, l = i);
            while(r != m && S[r-l] == S[r]) r++;
            Z[i] = r-l;
        }
        else Z[i] = Z[i-l];

        if (i+Z[i] < m && P[i+Z[i]].test(S[Z[i]]) == 0)
        {
            P[i+Z[i]].set(S[Z[i]]);
            us[i+Z[i]].push_back(Z[i]);
        }
    }

    DP[0] = n;
    fast_write_int(n);
    putchar_unlocked('\n');
    for (int i = 1; i < m; i++)
    {
        DP[i] = n * (DP[i-1] + 1) % mod;
        for (int &j : us[i]) 
        {
            DP[i] -= DP[j];
            DP[i] %= mod;
        }
        fast_write_int((DP[i]+mod)%mod);
        putchar_unlocked('\n');
    }
}
