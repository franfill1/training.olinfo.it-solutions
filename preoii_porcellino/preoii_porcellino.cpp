#include <stdbool.h>

bool chiedi(int X);

typedef unsigned long long ull;

int indovina() {
  ull x = (1<<30);
  chiedi(x);
  ull ans = 0;
  while(x)
  {
  	x>>=1;
  	if (!chiedi(x))
  	{
  		if (x == 0)
  		{
  			ans+=1;
		}
  		ans += (x<<1);
	}
  }
  return ans;
}