#include <bits/stdc++.h>

using namespace std;

ifstream fin;
ofstream fout;

int main ()
{
	fin.open("input.txt");
	fout.open("output.txt");
	
	string s1, s2, s3;
	fin >> s1 >> s2 >> s3;
	
	string s = "";
	
	bool possible = true;
	
	int N = s1.length();
	s += s1[0];
	vector < int > o1;
	int c = 1;
	for (int i = 1; i < N; i++)
	{
		if(s1[i] != s.back())
		{
			s += s1[i];
			o1.push_back(c);
			c = 0;
		}
		c++;
	}
	o1.push_back(c);
	
	N = s2.length();
	int j = 0;
	vector < int > o2;
	c = 0;
	for (int i = 0; i < N; i++)
	{
		if (s2[i] != s[j])
		{
			j++;
			if (s2[i] != s[j])
			{
				possible = false;
				break;
			}
			else
			{
				o2.push_back(c);
				c = 0;
			}
		}
		c++;
	}
	o2.push_back(c);
	
	N = s3.length();
	j = 0;
	vector < int > o3;
	c = 0;
	for (int i = 0; i < N; i++)
	{
		if (s3[i] != s[j])
		{
			j++;
			if (s3[i] != s[j])
			{
				possible = false;
				break;
			}
			else
			{
				o3.push_back(c);
				c = 0;
			}
		}
		c++;
	}
	o3.push_back(c);
	
	string ans = "";
	if (possible)
	{
		for (int i = 0; i < s.length(); i++)
		{
			int ma = max(o1[i], max(o2[i], o3[i]));
			int mi = min(o1[i], min(o2[i], o3[i]));
			int mid = o1[i] + o2[i] + o3[i] - ma - mi;
			for (int j = 0; j < mid; j++)
			{
				ans += s[i];
			}
		}
	}
	else
	{
		ans = "IMPOSSIBLE";
	}
	fout << ans;
	
	return 0;
}

