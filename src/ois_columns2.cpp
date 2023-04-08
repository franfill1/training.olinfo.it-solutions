#include <fstream>
#include <iostream>

using namespace std;

int main ()
{
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");
    
    int N, K, totCol = 0, left = 0;
    fin >> N >> K;
    
    for (int i = 0; i < N; i++)
    {
        int len;
        fin >> len;
        int col = len / K;
        if (col > 10)
        {
            col = 10;
        }
        int l = len - col * K;
        left += len - col * K;
        if (l == K)
        {
            col += 1;
            left -= K;
        }
        totCol += col;
    }
    fout  << totCol << " " << left;
}