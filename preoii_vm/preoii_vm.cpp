#include <vector>
using namespace std;

long long aggiorna(int N, vector<int> A, vector<int> B) {
    // aggiungi codice qui / insert code here
    long long a = 0;
    for (int i = N-2; i >= 0; i--)
    {
        long long c = (A[i+1] - A[i])/B[i];
        A[i] += B[i] * c;
        a += c;
    }
    return a;
}
