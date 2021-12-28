/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <assert.h>
#include <stdio.h>

// input data
long long R, C, K;

int main() {
  //  uncomment the following lines if you want to read/write from files
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

  assert(3 == scanf("%lld %lld %lld", &R, &C, &K));

  // insert your code here
	long long int result = ((R-1) / K + 1) * ((C - 1) / K + 1);
	
  printf("%lld\n", result);  // print the result
  return 0;
}