#include <algorithm>
#include <iostream>
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
  double dec_rat;
  x = inf.readInt();
  y = inf.readInt();
  z = inf.readInt();
  dec_rat = inf.readDouble();
  double curr_rate = 1.0000;
  println(x);
  println(y);
  println(z);
  println(dec_rat);

  // std::vector<char> v(100);
  double best_boxes = ans.readDouble();
  // best_boxes = 100.000;
  //  for (int i = 0; i < 100; ++i) v[i] = inf.readChar();
  /*

#if 0
  for (int i = 0; i < 100; ++i, curr_rate *= dec_rat) {
    println('G');
  }
  quitp(1.0f, "Ratio: 1.000");
  return 0;
#endif
  */

  // Send public n to contestant
  std::vector<char> c(3, 'x');
  std::vector<double> cnt(3, 0.00);
  for (int i = 0; i < 100; ++i, curr_rate *= dec_rat) {
    std::string str = inf.readString();
    char col = str[0];
    println(col);
    std::string action_type;
    int num;
    action_type = ouf.readWord();
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
      if (cnt[num] == 0 || c[num] == col) {
        c[num] = col;
        cnt[num] += curr_rate;
      } else {
        // cooked, its in the wrong one
        quitf(_wa, "-1");
        // quitp(1.0f, "Ratio: 1.000");
      }
    } else {
      quitf(_wa, "-1");
      // quitp(1.0f, "Ratio: 1.000");
    }
  }
  /*
    double truescore = cnt[1] + cnt[2];
  double s = truescore / best_boxes / 100.0;
  quitp(s, "Ratio: %.4f", s);
  */

  /*
  return 0;
    double truescore = cnt[1] + cnt[2];
    if (truescore < best_boxes * 0.5) {
      double score_ratio = 0.000;
      quitp(score_ratio, "Ratio: %.4f", score_ratio);
    } else {
      double score_ratio = (truescore - best_boxes * 0.5) / (best_boxes * 0.5);
      quitp(score_ratio, "Ratio: %.4f", score_ratio);
    }
  */
  double truescore = cnt[1] + cnt[2];
  if (truescore > best_boxes) {
    double score_ratio = 1.000;
    quitp(score_ratio, "Ratio: %.4f", score_ratio);
  } else {
    if (truescore < best_boxes * 0.5) {
      double score_ratio = 0.000;
      quitp(score_ratio, "Ratio: %.4f", score_ratio);
    } else {
      double score_ratio = (truescore - best_boxes * 0.5) / (best_boxes * 0.5);
      quitp(score_ratio, "Ratio: %.4f", score_ratio);
    }
  }

  /*
  if (truescore < best_boxes * 0.5) {
    double score_ratio = 0.000;
    quitp(score_ratio, "Ratio: %.4f", score_ratio);
  } else {
    double score_ratio = (truescore - best_boxes * 0.5) / (best_boxes * 0.5);
    quitp(score_ratio, "Ratio: %.4f", score_ratio);
  }
  */

  // double score_ratio = (double)(cnt[0] + cnt[1]) / (double)best_boxes;
  // quitp(score_ratio, "Ratio: %.4f");
  return 0;
}
