#include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<int> *visited;

void explore(vector<vector<int> > &adj, int v){
	vector<int> way_to = adj[v];
	visited->at(v) = 1;
	for (int i : way_to){
		if (visited->at(i) == 0)
			explore(adj, i);
	}

}

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  visited = new vector<int>(adj.size(), 0);
  int ctr = 0;
  for (int x : *visited){
	  if (x == 0){
		  res++;
		  explore(adj, ctr);
	  }
	  ctr++;

  }


  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
