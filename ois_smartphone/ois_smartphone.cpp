#include <fstream>

using namespace std;

typedef unsigned long long int ull;

int main ()
{
    ios_base::sync_with_stdio(false);

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    ull N;
    fin >> N;
    
    ull max = 0, ans = 0;

    for (ull i = 0; i < N; i++)
    {
        ull n;
        fin >> n;
        if (max < n)
        {
            ans += n;
            max = n;
        }
    }
    
    fout << ans;
}