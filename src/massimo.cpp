#include <algorithm>
#include <cassert>
#include <fcntl.h>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <vector>

static int ans;

int trova_massimo(int N, std::vector<int> V) {
  return ans = *max_element(V.begin(), V.end());
}

static int dupstdout;
static int p;

struct S {
  S() {
      dupstdout = dup(1);
      close(1);
      
      int fd[2];
      int ret = pipe(fd);
      if (ret == -1) raise(44);
      p = dup(fd[0]);
      if (p < 0) raise(46);
      ret = dup2(fd[1], 1);
      if (ret == -1) raise(45);
  }

  ~S() {
      close(1);
      
      char buf[128];
      int len = read(p, buf, sizeof(buf) - 1);
      if (len == -1) raise(47);
      buf[len] = 0;
      
      int x = atoi(buf);
      if (x != ans) raise(50);
      
      write(dupstdout, buf, len);
  }
} s;