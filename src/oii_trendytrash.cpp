#include<bits/stdc++.h>
using namespace std;

int pulisci(int N, int M, vector<string> S) 
{
    vector < int > colC(M, 0), colP(M, 0);
    vector < int > rigC(N, 0), rigP(N, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (S[i][j] == '0')
            {
                colC[j]++;
                rigC[i]++;
            }
            else
            {
                colP[j]++;
                rigP[i]++;
            }
        }
    }
    //cout << rigP[0] << "!!\n";

    int ans = N*M;
    while(true)
    {
        int k;
        for (k = 0; k < N; k++) if ((rigC[k] == 0) ^ (rigP[k] == 0)) break;

        if (k != N)
        {
            //cout << "rig " << k << " " << rigC[k] << " " << rigP[k] << "\n";
            for (int i = 0; i < M; i++)
            {
                if (S[k][i] == '1')
                {
                    colP[i]--;
                    ans--;
                }
                else if (S[k][i] == '0')
                {
                    colC[i]--;
                    ans--;
                }
                S[k][i] = ' ';
            }
            rigC[k] = rigP[k] = 0;
        }
        else
        {
            for (k = 0; k < M; k++) if ((colC[k] == 0) ^ (colP[k] == 0)) break;
            if (k == M) break;
            //cout << "col " << k << " " << colC[k] <<  " " << colP[k] << "\n";
            for (int i = 0; i < N; i++)
            {
                if (S[i][k] == '1')
                {
                    rigP[i]--;
                    ans--;
                }
                else if (S[i][k] == '0')
                {
                    rigC[i]--;
                    ans--;
                }
                S[i][k] = ' ';
            }
            colC[k] = colP[k] = 0;
        }
    }
    return ans;
}
