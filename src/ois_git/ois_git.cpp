#include <bits/stdc++.h>

#define maxn 1000000

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

unordered_map < string , int > name_to_id;
unordered_map < int , string > id_to_name;

vector < vector < int > > g(maxn);
vector < bool > ch(maxn, true);
vector < bool > vis(maxn, false);

void dfs(int n, string pre)
{
	if (ch[n] == true)
	{
		fout << (pre + id_to_name[n]) << "\n";
		return;
	}
	string nPre = pre + id_to_name[n] + "/";
	for (int ne : g[n])
	{
		if (vis[ne] == false)
		{
			vis[ne] = true;
			dfs(ne, nPre);
		}
	}
}

int main()
{
	int N;
	fin >> N;
	
	name_to_id[""] = 0;
	id_to_name[0] = "";
	
	int c = 1;
	
	for (int i = 0; i < N; i++)
	{
		bool cha;
		fin >> cha;
		if (cha == false)
		{
			ch[0] = false;
		}
		
		string file;
		fin >> file;
		
		stringstream ss(file);
		string fol;
		getline(ss, fol, '/');
		
		int last = 0;
		
		while(getline(ss, fol, '/'))
		{
			if (name_to_id.count(fol) == 0)
			{
				name_to_id[fol] = c;
				id_to_name[c] = fol;
				c++;
			}
			int id = name_to_id[fol];
			if (cha == false)
			{
				ch[id] = false;
			}
			g[last].push_back(id);
			last = id;
		}
	}
	
	if (ch[0])
	{
		fout << "/";
	}
	else
	{
		dfs(0, "");
	}
}