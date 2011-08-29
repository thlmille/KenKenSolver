#include "puzzle.h"

puzzle::puzzle (int csize, vector<rule> crules) {
  this->size = csize;
  this->rules = crules;

  // Fill possible map
  vector<int> all;
  for (int i = 1; i <= csize; ++i) {
    all.push_back(i);
  }
  map<pair<int, int>, vector<int> > all_possible;
  for (int i = 1; i <= csize; ++i) {
    for (int j = 1; j <=csize; ++j) {
      all_possible[make_pair(i, j)] = all;
    }
  }
  this->possible = all_possible;
}

// Iterate through solution we have so far, and
//   remove possibilities from possible map
void puzzle::update_possible () {
  for (int i = 1; i <= this->size; ++i) {
    for (int j = 1; j <= this->size; ++j) {
      if (this->solution[i][j] != 0) {
	this->possible[make_pair(i, j)].clear();
	int taken = this->solution[i][j];
	update_possible_row(taken, i);
	update_possible_column(taken, j);
      }
    }
  }
}

// Remove a given number from a vector of ints,
//   used to update possible map
void delete_num (int remove, vector<int> &nums) {
  vector<int>::iterator it = nums.begin();
  for (; it != nums.end(); ++it) {
    if (*it == remove) {
      nums.erase(it);
      return;
    }
    if (*it > remove) return;
  }
}

// Remove from possible map all the instances in a row of
//   a number that has been used
void puzzle::update_possible_row (int taken, int row) {
  for (int i = 1; i < this->size; ++i) {
    delete_num (taken, this->possible[make_pair(row, i)]);
  }
}

// Remove from possible map all the instances in a column of
//   a number that has been used
void puzzle::update_possible_column (int taken, int column) {
  for (int i = 1; i < this->size; ++i) {
    delete_num (taken, this->possible[make_pair(i, column)]);
  }
}

void puzzle::solve () {

  // Allocate 2-dimensional solution array
  this->solution = (int**) calloc(this->size+1, sizeof(int*));
  for (int i = 1; i <= this->size; ++i) {
    this->solution[i] = (int*) calloc(this->size+1, sizeof(int));
  }

  // Fill in given squares
  vector<rule>::iterator rit = this->rules.begin();
  for (; rit != this->rules.end(); ++rit) {
    if (rit->squares.size() == 1) {
      int i = rit->squares[0].first;
      int j = rit->squares[0].second;
      solution[i][j] = rit->total;
    }
  }
}
