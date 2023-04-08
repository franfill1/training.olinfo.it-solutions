/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <assert.h>
#include <stdio.h>
#include <iostream>

// constraints
#define MAXN 100000

// input data
int N, K, i;
int V[MAXN];

int main() {
  //  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

  assert(2 == scanf("%d %d", &N, &K));
  for (i = 0; i < N; i++) assert(1 == scanf("%d", &V[i]));

  // insert your code here
	bool visited[N] = {false};
	int result = 0;
	int i = 0;
	K--;
	
	while(!visited[i] && i != K)
	{
		visited[i] = true;
		i = V[i] - 1;
		result++;
	}
	
	if (i != K)
	{
		result = -1;
	}
	
  printf("%d\n", result);  // print the result
  return 0;
}