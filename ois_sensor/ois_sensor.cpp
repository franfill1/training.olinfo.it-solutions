#include <bits/stdc++.h>
#ifdef _WIN32
inline int getchar_unlocked() { return _getchar_nolock(); }
#endif

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");


inline __attribute__((always_inline)) int fast_read_int()
{
    int c, n = 0;
    bool s = false;
    do
    {
        c = getchar_unlocked();
        if (c == '-')
        {
        	s = true;;
		}
    } while (c < '0' || c > '9');
    do
    {
        n = (n << 3) + (n << 1) + (c - '0');
        c = getchar_unlocked();
    } while (c >= '0' && c <= '9');
    if (s)
    {
    	return -1;
	}
    return n;
}

int main()
{
	int N = fast_read_int();
	
	short int last = fast_read_int();
	int ans = last;
	short int el;
	for (int i = 1; i < N; i++)
	{
		el = fast_read_int();
		el = (el == -1 ? last : el);
		ans += el;
		last = el;
	}
	printf("%d", ans);
}
