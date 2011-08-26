#include <puzzle.h>

puzzle::puzzle (int csize, vector<rule> crules) {
  this->size = csize;
  this->rules = crules;
}

void puzzle::solve () {

  // Allocate 2-dimensional solution array
  this->solution = calloc(this->size+1, sizeof(int*));
  for (int i = 1; i <= this->size; ++i) {
    this->solution[i] = calloc(this->size+1, sizeof(int));
  }

  // Fill in given squares
  vector<rule>::iterator rit = this->rules.begin();
  for (; rit != this->rules.end()) {
    if (rit->squares.size() == 1) {
      int i = rit->squares[0].first;
      int j = rit->squares[0].second;
      solution[i][j] = rit->total;
    }
  }
}
