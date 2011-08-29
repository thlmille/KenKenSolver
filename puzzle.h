#include <vector>
#include <utility>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

struct rule {
  vector<pair<int, int> > squares;
  char op;
  int total;
};

typedef struct rule rule;

class puzzle {
 private:
  int size;
  vector<rule> rules;
  int **solution;
  map<pair<int, int>, vector<int> > possible;
  void update_possible ();
  void update_possible_row (int taken, int row);
  void update_possible_column (int taken, int column);
 public:
  puzzle (int csize, vector<rule> crules);
  void solve ();
};
