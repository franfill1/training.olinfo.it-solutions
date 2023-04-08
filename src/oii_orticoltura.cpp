#include<bits/stdc++.h>
using x=int;
using v=std::vector<int>;
void posiziona(x D,x T);
void budget(x B);
void irriga(x C,x n,v&X,v&P)
{
	std::pair<x,x>S[n+1];
	x a=n;
	while(a--)S[a]={(X[a]-P[a])/2+1,(X[a]+P[a])/2+1};
	std::sort(S,S+n);
	auto[i,j]=S[0];
	for(auto[l,r]:S){
		if((l-j)>C|!l)
		{
			posiziona(j+i-2,j-i);
			a+=C+j-i;
			i=l;
		}
		j=r>j?r:j;
	}
	budget(a+1);
}
