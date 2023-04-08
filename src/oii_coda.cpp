#include <vector>
using namespace std;

vector<int> cucina(int N, int K, int X, vector<int> H) {
    vector<int> R(X), C(X, 0);
    for (auto h : H)
            C[h]++;
    vector<int>V(X);
    if(C.back() > 0)
            R.back() = 1;
    else
            V.back() = 1;
    for (int x = X-2; x >=0; x--)
    {
            int a = min(C[x],V[x+1]+1);
            R[x]=R[x+1]+a;
            V[x]=min(K-1,V[x+1]+1-a);
    }

    return R;
}