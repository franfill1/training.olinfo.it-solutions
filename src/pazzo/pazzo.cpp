#include<iostream>
#include<fstream>
using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N, M;
	fin >> N >> M;
	int ip = 0;
	for (int m = 0; m < M; m++)
	{
		int a, b;
		fin >> a >> b;
		if (ip == a) ip = b;
		else if (ip == b) ip = a;
	}
	fout << ip << "\n";
}

