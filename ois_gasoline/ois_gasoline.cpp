#include <fstream>

using namespace std;

int main()
{
	ifstream fin;	
	fin.open("input.txt");
	ofstream fout;
	fout.open("output.txt");

	long long int N = 0;
	fin >> N;
	long long int *P, *G;
	P = (long long int*)calloc(N, sizeof(long long int));
	G = (long long int*)calloc(N, sizeof(long long int));
	for (long long int i = 0; i < N; i++)
	{
		fin >> P[i];
	}

	long long int lowcost = P[0]; //il costo minore all'inizio del blocco
	long long int gas = 0; //il costo della stazione raggiunta
	long long int totalgas = 0; //il gas richiesto per blocco
	long long int finalcost = 0; //il costo finale (output)
	for (long long int i = 0; i < N; i++)
	{
		fin >> gas;
		if (P[i] < lowcost)
		{
			finalcost += totalgas * lowcost;
			totalgas = 0;
			lowcost = P[i];
		}
		totalgas += gas;
	}
	finalcost += totalgas * lowcost;
	fout << finalcost;
}