#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
	vector<int> distance(adj.size(), -1);
	queue<int> bfs_queue;
	bfs_queue.push(s);
	distance[s] = 0;
	while ((distance[t] == -1) && (!bfs_queue.empty())){
		int c = bfs_queue.front();

		bfs_queue.pop();
		vector<int> hlp = adj[c];

		for (int n : hlp){
			if (distance[n] == -1){
				bfs_queue.push(n);
				distance[n] = distance[c] + 1;
			}
		}

	}

  return distance[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
