#pragma GCC optimize("O3")
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
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int rnd(int a, int b) { return a + rand() % (b - a + 1); }
int32_t main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int seed = atoi(argv[1]);
  srand(seed);
  int t = rnd(1, 2);
  std::mt19937 g(seed);
  std::mt19937 u(seed + 1);
  int x, y, z;
  if (t == 1) {
    // smallest is <=19;
    z = rnd(1, 19);
    y = rnd(z, 40);
    x = 100 - z - y;

  } else {
    z = rnd(20, 32);
    y = rnd(z, (100 - z) / 2);
    x = 100 - z - y;
  }
  vector<int> v = {x, y, z};
  shuffle(v.begin(), v.end(), g);
  cout << v[0] << " " << v[1] << " " << v[2] << "\n";
  vector<int> q = v;
  shuffle(q.begin(), q.end(), u);
  vector<char> cols;
  for (int i = 0; i < q[0]; ++i) {
    cols.push_back('R');
  }
  for (int i = 0; i < q[1]; ++i) {
    cols.push_back('G');
  }
  for (int i = 0; i < q[2]; ++i) {
    cols.push_back('B');
  }
  shuffle(cols.begin(), cols.end(), g);
  for (int i = 0; i < 100; ++i) {
    cout << cols[i] << endl;
  }
}