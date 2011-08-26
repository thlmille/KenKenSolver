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
 public:
  puzzle (int csize, vector<rule> crules);
  void solve ();
};
