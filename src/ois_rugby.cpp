#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int N;
int* Bravura;
int* Capo;
vector <vector<int> > G;

int dfs(int nodo) {
	int BravC=Bravura[nodo];
	int BravD = 0;
	for (int i = 0; i < G[nodo].size(); i++) {
		BravD += dfs(G[nodo][i]);
	}
	return max(BravD, BravC);
}

int main() {
	fin >> N;
	Bravura = new int [N];
	Capo = new int [N];
	G.resize(N);
	for(int i = 0; i<N; i++){
		fin>>Bravura[i]>>Capo[i];
	}
	
	for(int i=1;i<N;i++){
		G[Capo[i]].push_back(i);
	}
	
	fout << dfs(0);
}