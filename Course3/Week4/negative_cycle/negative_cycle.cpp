#include <iostream>
#include <vector>
#include <limits>
using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
	vector<std::pair <std::pair<int, int>, int> > w_edges;
	vector<int> distances(adj.size(), 0);
	distances[0] = 0;
	int n_edge = 0;
	for (int n = 0; n < adj.size(); n++){
		vector<int>::iterator cost_it = cost[n].begin();
		for (int i : adj[n]){
			std::pair<std::pair<int, int>, int> hlp;
			hlp.first.first = n;
			hlp.first.second = i;
			hlp.second = *cost_it;
			cost_it++;
			w_edges.push_back(hlp);
			n_edge++;
		}

	}
	int  i = 0;
	int j = 0;
	int changes;
	while (j < n_edge+1){
		changes = 0;
		i = 0;
		while (i < (n_edge)){
			if ((distances[w_edges[i].first.first] != std::numeric_limits<int>::max()) && (distances[w_edges[i].first.second] > distances[w_edges[i].first.first] + w_edges[i].second)){
				distances[w_edges[i].first.second] = distances[w_edges[i].first.first] + w_edges[i].second;
				changes++;
			}
			i++;
		}
		if (changes == 0)
			break;
		j++;
	}
	

  return changes?1:0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
