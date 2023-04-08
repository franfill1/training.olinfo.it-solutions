#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <queue>
#include <bitset>
#include <unordered_set>

using namespace std;

int main()
{
	ifstream fin;
	fin.open("input.txt");
	
	ofstream fout;
	fout.open("output.txt");
	
	int N, K;
	fin >> N >> K;
	
	bitset<20> lights; 
	bitset<20> desired (1<<K-1);
	
	for (int i = 0; i < N; i++)
	{
		int light; 
		fin >> light;
		lights[i] = light; 
	}
	
	vector<bitset<20> > buttons;
	
	for (int i = 0; i < N; i++)
	{
		int t;
		fin >> t;
		
		bitset<20> button; 
		
		for (int j = 0; j < t;	j++)
		{
			int l;
			fin >> l;
			button[l-1] = 1;
		}
		
		button = ~button;
		buttons.push_back(button);
	}
	
	queue< pair<bitset <20>, int> > q; 
	unordered_set < bitset < 20 > > vis;
	q.push(make_pair(lights, 0));
	vis.insert(lights);
	
	int bestMoves = 0; 
	
	bool end = false;
	if (lights != desired) while(!end)
	{
		bitset<20> lights = q.front().first;
		int moves = q.front().second;
		q.pop();
		
		for (int i = 0; i < N; i++)
		{
			if (lights[i] == 0) 
			{
				bitset <20> newLights = lights & buttons[i]; 
				newLights[i] = 1<<i; 
				int newMoves = moves + 1;
				if (newLights == desired) 
				{
					bestMoves = newMoves;
					end = true;
					break;
				}
				else if (!vis.count(newLights))
				{
					vis.insert(newLights);
					q.push(make_pair(newLights, newMoves));
				}	
			}
		}
	}
	fout << bestMoves;
	return 0;
}