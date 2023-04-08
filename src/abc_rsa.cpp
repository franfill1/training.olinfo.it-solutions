#include <bits/stdc++.h>

typedef unsigned long long int ull;

ull modPow(ull b, ull e, ull N)
{
	if(e == 0)
	{
		return 1;
	}
	ull ans = 1;
	ull newPow = modPow(b, e/2, N) % N;
	ans = newPow * newPow % N;
	if (e % 2 == 1)
	{
		ans *= b;
		ans = ans % N;
	}
	return ans;
}


// Declaring functions
void decifra(int N, int d, int L, int* messaggio, char* plaintext) {
    for (int i = 0; i < L; i++)
    {
    	plaintext[i] = modPow(messaggio[i], d, N);
	}
	plaintext[L] = '\0';
}