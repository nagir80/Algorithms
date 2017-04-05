#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;
  // write your code here
  int n = 1;
  for (string str : patterns){
	  int currentNode = 0;
	  for (char c: str){
		  edges hlp_edge;
		  if (currentNode < t.size())
			  hlp_edge = t[currentNode];
		  else
			  hlp_edge.clear();
		  if (hlp_edge[c] != NULL){
			  currentNode = hlp_edge[c];
		  }
		  else{
			  if (currentNode < t.size()){
				  t.at(currentNode)[c] = n;
				  currentNode = n;
				  t.resize(t.size() + 1);
				  
			  }
			  else{
				  t.resize(t.size() + 1);
				  hlp_edge[c] = n;
				  currentNode = n;
				  t.at(currentNode-1) = (hlp_edge);
				  
			  }
			  n++;
		  }
		  
	  }
  }
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}