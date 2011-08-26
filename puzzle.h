#include <vector>
#include <utility>
#include <iostream>

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
  vector<vector<int> > solution;
 public:
  puzzle (int csize, vector<rule> crules);
  void solve ();
};
