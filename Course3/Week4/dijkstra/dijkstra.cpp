#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

typedef pair<pair<int, int>, int> weighted_edge;

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
	weighted_edge w_edge;
	pair<int, int> edge;
	auto comp = [](weighted_edge a, weighted_edge b) { return a.second > b.second; };
	priority_queue <weighted_edge, vector<weighted_edge>, decltype(comp) > pr_queue_edge(comp);
	vector<int> distance1(adj.size(), -1);

	edge.first = s;
	distance1[s] = 0;
	vector<int>::iterator cost_it = cost[s].begin();
	for (int x : adj[s]){
		edge.second = x;
		w_edge.first = edge;
		w_edge.second = *cost_it;
		if (distance1[x] == -1){
			distance1[x] = distance1[s] + w_edge.second;
		}
		cost_it++;
		pr_queue_edge.push(w_edge);
	}
	while (!pr_queue_edge.empty()){
		w_edge = pr_queue_edge.top();
		pr_queue_edge.pop();
		edge.first = w_edge.first.second;
		vector<int>::iterator cost_it = cost[edge.first].begin();
		for (int x : adj[edge.first]){
			edge.second = x;
			w_edge.first = edge;
			w_edge.second = *cost_it;
			if ((distance1[edge.second] == -1) || (distance1[edge.second] > (distance1[edge.first] + w_edge.second))){
				distance1[edge.second] = distance1[edge.first] + w_edge.second;
				pr_queue_edge.push(w_edge);
			}
			cost_it++;
		}
	}

  return distance1[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
