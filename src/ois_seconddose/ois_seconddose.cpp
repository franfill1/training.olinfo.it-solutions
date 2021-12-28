#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	vector <int> V1;
	set <int> V2;
	int N, N1;
	cin >> N >> N1;
	int dato;
	for(int i=0; i<N; i++){
		cin >> dato;
		V1.push_back(dato);
	}
	int conta = 0;
	for(int i=0; i<N1; i++){
		cin >> dato;
		V2.insert(dato);
	}
	for(int i=0; i<N; i++){
		if(V2.count(V1[i]))
		{
		    conta++;
			V2.erase(V1[i]);
		}
	}
	cout << conta;
}