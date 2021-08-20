#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef __int128_t ll;

const ll inf = 1ll<<62;
ll gcdExtended(ll a, ll b, ll &x, ll &y)
{
	//ATTENZIONE: CASI PARTICOLARI
	if (b == 0)
	{
		if (a == 0)
		{
			return -1;
		}
		else
		{
			x = 1;
			y = 0;
			return a;
		}
	}
	
	
	//ritorna il massimo comun divisore fra a e b
	//e trova x e y tali che
	//gcd(a, b) = a * x + b * y
	
	//a = d * b + r
	//r = a - d * b
	ll r = a%b;
	ll d = a/b;
	if (r == 0)
	{
		x = 0;
		y = 1;
		return b;
	}
	
	ll x1, y1;
	ll gcd = gcdExtended(b, r, x1, y1);
	//gcd = b * x1 + r * y1
	//gcd = b * x1 + (a - d * b) * y1
	//gcd = b * x1 + a * y1 - b * (d * y1)
	//gcd = a * y1 + b * (x1 - d * y1)
	x = y1;
	y = x1 - d * y1;
	return gcd;
}

int main()
{
	ll N, A, B;
	unsigned long long Nn, Aa, Bb;
	fin >> Nn >> Aa >> Bb;
	N = Nn; A = Aa; B = Bb;
	ll g1 = A, g2 = B;
	if (g2 > g1)
	{
		g1 = B;
		g2 = A;
	}
	ll x, y;
	ll gcd = gcdExtended(g1, g2, x, y);
	ll mcm = A*B/gcd;
	x *= N/gcd;
	y *= N/gcd;
	ll deltaX = 1 - x;
	if (deltaX < 0) deltaX = 0;
	ll stepX = mcm/g1;
	ll stepY = mcm/g2;
	ll step = deltaX / stepX + (deltaX % stepX != 0);
	x += stepX * step;
	y -= stepY * step;
	ll deltaY = 1 - y;
	if (deltaY < 0) deltaY = 0;
	step = deltaY / stepY + (deltaY % stepY > 0);
	y += stepY * step;
	x -= stepX * step;
	
	
	deltaY = y - 1;
	step = deltaY / stepY;
	y -= stepY * step;
	x += stepX * step;
	
	if (g1 == A)
	{
		fout << (unsigned long long)x << " " << (unsigned long long)y << "\n";
	}
	else
	{
		fout << (unsigned long long)y << " " << (unsigned long long)x << "\n";
	}
}
