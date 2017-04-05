#include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<int> *visited;

int explore(vector<vector<int> > &adj, int v){
	static int cycle = 0;
	static int end = -1;
	vector<int> way_to = adj[v];
	visited->at(v) = 1;
	for (int i : way_to){
		if (visited->at(i) == 0)
			explore(adj, i);
		else
			end = i;
		if (v == end)
			cycle = 1;
	}
	return cycle;
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
	int res = 0;
	int cyc = 0;
	visited = new vector<int>(adj.size(), 0);
	int ctr = 0;
	for (int x : *visited){
		if (x == 0){
			res++;
			cyc = explore(adj, ctr);
		}
		ctr++;

	}
	return cyc;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
