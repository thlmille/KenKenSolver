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
  void do_rules_elimination();
  void add_reduce (rule crule);
  void sub_reduce (rule crule);
  void div_reduce (rule crule);
  void mul_reduce (rule crule);
 public:
  puzzle (int csize, vector<rule> crules);
  void solve ();
};
