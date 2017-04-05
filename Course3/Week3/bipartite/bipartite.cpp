#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
	//write your code here
	int res = 1;
	vector<int> distance(adj.size(), -1);
	queue<int> bfs_queue;
	bfs_queue.push(0);
	distance[0] = 0;
	while (!bfs_queue.empty()){
		int c = bfs_queue.front();
		bfs_queue.pop();
		vector<int> hlp = adj[c];
		for (int n : hlp){
			if (distance[n] == -1){
				bfs_queue.push(n);
				distance[n] = (distance[c] + 1) & 0x1;
			}
			else
			if (distance[n] == (distance[c]) & 0x1){
				res = 0;
				break;
			}

		}
	}
	return res;
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
  std::cout << bipartite(adj);
}
