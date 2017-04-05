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

int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
	visited = new vector<int>(adj.size(), 0);
	if (visited->at(x) == 0)
		explore(adj, x);

	if (visited->at(y) == 1)
		return 1;
  return 0;
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
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
