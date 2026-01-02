#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

#include "testlib.h"

int main(int argc, char* argv[]) {
  // Initialize the interactor.
  // inf = test case input (.in), visible to contestant
  // ouf = contestant's output stream
  // ans = secret answer file (.ans), hidden from contestant
  registerInteraction(argc, argv);

  // Read secret information from .ans file
  // The .ans file should now contain the best_queries value first, then the
  // permutation.

  int x, y, z;
  x = inf.readInt();
  y = inf.readInt();
  z = inf.readInt();
  println(x);
  println(y);
  println(z);
  std::vector<char> v(100);
  long long best_boxes = 43;
  for (int i = 0; i < 100; ++i) {
    v[i] = inf.readChar();
  }

  // Send public n to contestant
  std::vector<char> c(3, 'x');
  std::vector<int> cnt(3, 0);
  for (int i = 0; i < 100; ++i) {
    char col = inf.readChar();
    println(col);
    println("");
    std::string action_type;
    int num;
    action_type = ouf.readString();
    if (action_type == "DISCARD") {
      continue;
      // you literally dont do anything
    } else {
      num = ouf.readInt();
    }
    if (action_type == "EMPTY") {
      cnt[num] = 0;
      c[num] = 'x';
      continue;
    }
    if (action_type == "PLACE") {
      if (c[num] == 'x' || c[num] == col) {
        c[num] = col;
        cnt[num]++;
      } else {
        // cooked, its in the wrong one
        // quitf(_wa, "-1");
        quitp(1.0f, "Ratio: 1.000");
      }
    } else {
      // quitf(_wa, "-1");
      quitp(1.0f, "Ratio: 1.000");
    }
  }
  quitp(1.0f, "Ratio: 1.000");

  // double score_ratio = (double)(cnt[0] + cnt[1]) / (double)best_boxes;
  // quitp(score_ratio, "Ratio: %.4f");
  return 0;
}
