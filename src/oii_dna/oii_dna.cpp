#include <string>
#include <iostream>
#include <cassert>

using namespace std;

bool test(string T);

string analizza(int N) 
{
	int pivot = 10000;
	int magic = 100;
	//bool strat = test(string(pivot, '0'));
    bool strat = false;
	int start;
	if (strat)
		start = pivot;
	else
	{
		int a = 0, b = pivot/2;
		while(a < b-1)
		{
			int m = (a+b)/2;
			if (test(string(m, '0')))
				a = m;
			else
				b = m;
		}
		start = a;
	}

	string s = string(start, '0');
	int streak = start;
	while(((!strat) && (streak <= start)) ||
		   (strat   && (streak == 0 || streak % magic != 0 || test(s))))
		if (test(s + "1"))
			s += "1", streak=0;
		else
			s += "0", streak++;

	if (strat)
		streak = magic;
	
	s = s.substr(0, s.size()-streak);

	int a = 0, b = 1;
	while(test(s + string(b, '0')))
		a++,b++;
	
	/*if (!strat)
	{
		a = 0, b = 1;
		while(test(s + string(b, '0')))
			a = b, b *= 2;
		b = min(b, streak);
	}
	while(a < b-1)
	{
		int m = (a+b)/2;
		if (test(s + string(m, '0')))
			a = m;
		else
			b = m;
	}*/
	s += string(a, '0');

	while(s.size() < N)
		s = (test("1" + s) ? "1" : "0") + s;
	return s;
}


