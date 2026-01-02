// #pragma GCC optimize ("O3")
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt”)
#define ci const int
using namespace std;
char s[100];
int gt() {
  scanf("%s", s);
  for (int i = 0;; ++i)
    if (s[i] == 'R')
      return 1;
    else if (s[i] == 'G')
      return 2;
    else if (s[i] == 'B')
      return 3;
}
void Work() {
  int A, B, C;
  scanf("%d%d%d", &A, &B, &C);
  if (B > A) swap(A, B);
  if (C > A) swap(A, C);
  if (C > B) swap(B, C);

  if (B + C >= 43) {
    // cout << "ERERERRERER";
    for (int i = 1; i <= 100; ++i) {
      int c = gt();
      // cout << c << endl;
      if (c == 1) {
        puts("PLACE ");
        puts("1");
        fflush(stdout);
      }
      if (c == 2) {
        puts("PLACE ");
        puts("2");
        fflush(stdout);
      }
      if (c == 3) {
        puts("DISCARD");
        fflush(stdout);
      }

      return;
    }
  } else if (C <= 19) {
    int cnt[4] = {0, 0, 0, 0}, c1 = 0, c2 = 0;
    for (int i = 1; i <= 100; ++i) {
      int c = gt();
      ++cnt[c];
      if (cnt[c] >= C + 1) {
        if (c1 == 0 || c1 == c) {
          c1 = c;
          puts("PLACE ");
          puts("1");
        } else {
          c2 = c;
          puts("PLACE ");
          puts("2");
        }

      } else {
        puts("DISCARD");
      }

      fflush(stdout);
    }
  } else {
    int cnt[4] = {0, 0, 0, 0}, c1 = 0, c2 = 0;
    for (int i = 1; i <= 100; ++i) {
      int c = gt();
      ++cnt[c];
      if (cnt[c] >= 23 && c1 != 0 && c2 != 0 && c1 != c && c2 != c) {
        puts("EMPTY ");
        puts("1");
        c1 = c;
      }

      if (c1 == 0 || c1 == c) {
        c1 = c;
        puts("PLACE ");
        puts("1");
      }

      else {
        if (c2 == 0 || c2 == c) {
          c2 = c;
          puts("PLACE ");
          puts("2");
        } else {
          puts("DISCARD");
          fflush(stdout);
        }
      }
    }
  }
}
int main() {
  // return 0;
  Work();
}