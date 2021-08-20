#include<iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

int main(){
	vector < vector < int > > g;
	ifstream fin ("input.txt");
	ofstream fout ("output.txt");
	
	int N, M;
	fin >> N >> M;
	
	g.resize(N);
	
	for (int i = 0; i < M; i++)
	{
		int from, to;
		fin >> from >> to;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	
	bool visited[N] = {false};
	queue < int > q;
	q.push(0);
	bool end = false;
	int isole = 1;
	
	while (!q.empty())
	{
		 while (!q.empty())
		 {
		 	int n = q.front();
		 	
			q.pop();
			
			visited[n] = true;
		 	
		 	for (int i = 0; i < g[n].size(); i++)
		 	{
		 		if (!visited[g[n][i]])
		 		{
		 			q.push(g[n][i])	;
				}
			}
		 }
		 
		 end = true;
		 for (int i = 0; i < N; i++)
		 {
		 	if (visited[i] == false && q.empty())
		 	{
		 		q.push(i);
		 		isole++;
			}
		 }
	}
	
	fout << isole - 1;
	
	  system("pause");
}
