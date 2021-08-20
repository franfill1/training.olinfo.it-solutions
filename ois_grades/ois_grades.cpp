#include <fstream>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int N;
    fin >> N;
    
    int first = -1;
    int last = -1;
    
    bool ok = false;
    for (int i = 0; i < N; i++)
    {
        int n;
        fin >> n;
        
        if (!ok)
        {
            if (n <= 5)
            {
                first = i;
                ok = true;
            }
        }
        else
        {
            if(n >= 6)
            {
                last = i;
            }
        }
    }
    
    int ans = last - first + 1;
    if (last == -1 || first == -1)
    {
        ans = -1;
    }
    
    fout << ans;
}