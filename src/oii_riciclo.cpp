#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void reuse(int n, vector < ll > &boxes)
{
    for (int i = boxes.size() - 1; i >= 0; i--)
    {
        int pow = 1 << i;
        if (n >= pow)
        {
            n -= pow;
            boxes[i]++;
        }
    }
}

long long riciclo(int N, int M, vector<int> T, vector<int> P)
{
    //boxes continene nella posizione i-esima la quantità di 'sottocamion' di dimensione 1 << i
    vector < ll > boxes(31, 0);
    for (auto t : T) reuse(t, boxes);

    //count è il numero di rifiuti gettati 
    //per ogni rifiuto di dimesione 1 << i si prova a gettarlo sempre nel box più piccolo disponibile
    ll count = 0;
    for (int i = 0; i < P.size(); i++)
    {
        int j;
        int molt;
        for (j = i, molt = 1; P[i] > 0 && j < boxes.size(); j++)
        {
            int v = min((ll)P[i], boxes[j]*molt);
            count += v;
            boxes[j] -= (v / molt) + 1;
            //reuse è lo spazio che può essere riutilizzato 
            //ex) se metto un rifiuto di dimensione 1 dentro un box da 8, avrò 7 da riutilizzare e di conseguenza avro 1 nuovo box da 1, 1 nuovo da 2 e 1 nuovo box da 4
            int to_reuse = (molt - (v % molt))<<i;
            if (molt == 1) to_reuse = 0;
            reuse(to_reuse , boxes);
            P[i] -= v;
            molt *= 2;
        }
    }

    return count;
}