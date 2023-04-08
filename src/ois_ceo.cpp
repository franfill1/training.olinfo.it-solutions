#include <fstream>
#include <iostream>
using namespace std;

int main ()
{
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");
    
    long long int N;
    fin >> N;
    
    long long int ret = 1, e = 1, n = 0;
    for (long long int i = 0; i < N; i++)
    {
        fin >> n;
        e = e * n;
        ret += e;
    }
    fout << ret;
}