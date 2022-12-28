#include<iostream>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M, A, B;
    cin >> N >> M >> A >> B;
    cout << min(N*A, (N/M)*B + min(N%M*A, B)) << "\n";
}
