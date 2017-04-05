#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long min_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  vector<int> help(b);
  vector<int> help_a(a);
  std::sort(help.begin(), help.end());

  for (int i = 0; i < help.size(); i++) {
	  int max_a = 0x80000000;
	  int ind_a;
	  for (int j = 0; j < help_a.size(); j++) {
		  if (help_a[j] >= max_a) {
			  max_a = help_a[j];
			  ind_a = j;
		  }
	  }
	  b[ind_a] = help[i];
	  help_a[ind_a] = 0x80000000;
  }
  
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << min_dot_product(a, b) << std::endl;
}
