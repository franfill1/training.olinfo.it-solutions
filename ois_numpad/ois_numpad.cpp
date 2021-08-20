#include <fstream>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <string.h>
#define MAXN 1000000
using namespace std;

int N;
char S[MAXN + 1];

int perBreve(int s, int f) {
	int iS, jS, iF, jF, dI, dJ, d;
	if (s == 0) {
		iS = 1;
		jS = 3;
	}
	else {
		iS = (s - 1) % 3;
		jS = (int)(s - 1) / 3;
	}
	if (f == 0) {
		iF = 1;
		jF = 3;
	}
	else {
		iF = (f - 1) % 3;
		jF = (f - 1) / 3;
	}
	dI = abs(iS - iF);
	dJ = abs(jS - jF);
	d = dI + dJ;
	return d;
}

int main() {
	ifstream input;
	ofstream output;
	input.open("input.txt");
	output.open("output.txt");
	int posA = 0, posB, i, tot = 0;
	input >> S;
	N = strlen(S);
	for (i = 0; i < N; i++) {
		posB = S[i] - '0';
		tot += perBreve(posA, posB);
		posA = posB;
		tot++;
	}
	output << tot;
}