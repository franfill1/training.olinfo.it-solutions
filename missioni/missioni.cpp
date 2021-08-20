#include <bits/stdc++.h>
using namespace std;

int n;
int durata[100], fine[100];
vector<vector < int > > missioni;

int calc(int missione, int giorni, int ris){
    if(missione==n || giorni >= 400) return 0;

    if(missioni[missione][giorni]==-1){
        if(giorni + durata[missione] <= fine[missione]){
            missioni[missione][giorni] = max(calc(missione+1, giorni+durata[missione], ris+1)+1, calc(missione+1, giorni, ris));
        }
        else{
            missioni[missione][giorni] = calc(missione+1, giorni, ris);
        }
    }
    return missioni[missione][giorni];
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> durata[i] >> fine[i];
    }
    missioni.resize(n, vector < int > (400, -1));
    cout << calc(0, 0, 0);
}