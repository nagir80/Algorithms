#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  int **mem = new int*[w.size()+1];
  for (int i = 0; i <= w.size(); i++) {
	  mem[i] = new int[W + 1];
  }
  for (int i = 0; i <= w.size(); i++) {
	  mem[i][0] = 0;
  }
  for (int i = 0; i <= W; i++) {
	  mem[0][i] = 0;
  }

  for (int j = 1; j <= W; j++) {

	  current_weight = 0;
	for (int i = 1; i <= w.size(); i++) {
		mem[i][j] = mem[i-1][j];
		if (w[i-1] <= j){
			current_weight = mem[i - 1][j - w[i-1]] + w[i-1];
			if (mem[i][j] < current_weight)
				mem[i][j] = current_weight;
		}
		  
	}

  }

  /*
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  */
  return mem[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
 vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';

  int l;
  std::cin >> l;
}
