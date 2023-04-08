#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int taglia(int N, vector<int> B)
{
    long long sum = 0;
    for (long long x : B)
        sum += x;
	
	if (sum == 0)
	{
		long long c = 0;
        int i = 0;
        for (long long x : B)
        {
            c = (c+x);
            if (c == 0)
                c = 0, i++;
        }
        if (i == 1)
        	return -1;
        return 2;
	}
		
    long long nc = abs(sum);
    vector <long long> P;
    for (long long p = 2; p*p <= nc; p++)
        if (nc % p == 0)
        {
        	P.emplace_back(p);
	        while(nc % p == 0)
	            nc /= p;
		}
    if(nc > 1)
        P.emplace_back(nc);
    for (long long p : P)
    {
        long long v = sum / p;
        long long c = 0;
        int i = 0;
        for (long long x : B)
        {
            c += x;
            if (c == v)
                c = 0, i++;
        }
        if (c == 0 && i == p)
            return p;
    }
    return -1;
}
