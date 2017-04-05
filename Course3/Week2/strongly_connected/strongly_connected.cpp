#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

/*
bool cmp(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
	return lhs.second < rhs.second;
}
*/
int explore(vector<vector<int> > &adj, vector<pair<int, int> > &used, int v){
	used.at(v).second = 0;
	vector<int> way_to = adj.at(v);
	for (int i : way_to){

		if (used.at(i).second == 0)
			continue;
		explore(adj, used, i);


	}
	return 0;
}

void dfs(vector<vector<int> > &adj, vector<pair<int, int> > &used, int x) {
	//write your code here
	static int ctr = 0;


	vector<int> way_to = adj.at(x);
	ctr++;
	used.at(x).first = x + 1;
	for (int i : way_to){

		if (used.at(i).first != 0)
			continue;
		dfs(adj, used, i);
		
		
	}
	ctr++;
	
	used.at(x).second = ctr;

}


vector<vector<int> >& r_matrix(vector<vector<int> > adj){
	vector<vector<int> > *adj_r = new vector<vector<int> >(adj.size(), vector <int>());
	for (int i = 0; i < adj.size(); i++){
		vector<int> hlp = adj[i];
		for (int n : hlp){
			adj_r->at(n).push_back(i);
		}
	}
	return *adj_r;
}


int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  vector<vector<int> > adj_r;
  vector<pair<int, int> > *used = new vector<pair<int, int> >(adj.size(), { 0, 0 });
  adj_r = r_matrix(adj);
  for (int k = 0; k < adj_r.size(); k++){
	  if (used->at(k).first != 0)
		  continue;
	  dfs(adj_r, *used, k);
  }
  vector<pair<int, int> >::iterator max_it;
  int max_val;
  while(1)
  {
	  max_it = std::max_element(used->begin(), used->end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs){
		  return lhs.second < rhs.second;
	  });
	  max_val = max_it->second;
	  if (max_val == 0)
		  break;
	  if (used->at(max_it->first - 1).second == 0)
		  continue;
	  explore(adj, *used, max_it->first - 1);
	  result++;
  }
  
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
