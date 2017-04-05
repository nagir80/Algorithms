#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
	vector<std::pair <std::pair<int, int>, int> > w_edges;
	distance[s] = 0;
	reachable[s] = 1;
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
	while (j < (3*n_edge + 1)){
		changes = 0;
		i = 0;
		while (i < (n_edge)){
			if ((distance[w_edges[i].first.first] != std::numeric_limits<long long>::max()) && (distance[w_edges[i].first.second] > distance[w_edges[i].first.first] + w_edges[i].second)){
				distance[w_edges[i].first.second] = distance[w_edges[i].first.first] + w_edges[i].second;
				reachable[w_edges[i].first.second] = 1;
				changes++;

				if (j >= n_edge){
					shortest[w_edges[i].first.second] = 0;
				}
			}
			i++;
		}
//		if (changes == 0)
//			break;
		j++;
	}
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
