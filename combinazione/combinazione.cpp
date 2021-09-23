#pragma GCC target ("avx2")
#include<iostream>
using namespace std;
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#ifdef _WIN32
inline int getchar_unlocked() { return _getchar_nolock(); }
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

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
		ios_base::sync_with_stdio(false);
		cout.tie(NULL);
        int N = fast_read_int() - 2, mi, ma, l = 0, m;
        mi = fast_read_int(); ma = fast_read_int();
        while(N--)
        {
                m = fast_read_int();
				if (m < l) 
				{
					cout << 0 << "\n";
					return 0;
				}
                ma = min(ma, m);
                ma = 2*m - ma;
                mi = 2*m - mi;
                swap(ma, mi);
                l = m;
        }
        cout << ma-mi+1 << "\n";
}


