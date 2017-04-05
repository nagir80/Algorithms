#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right-1) return a[left];
  if (left + 1 == right - 1) {
	  if (a[left] == a[right - 1])
		  return a[left];
	  else return -1;
  }
  //write your code here

  int maj_l;
  int maj_r;
  maj_l = get_majority_element(a, left, left+1+(right - left) / 2);
  maj_r = get_majority_element(a, left+1+(right - left) / 2, right);
  if (maj_l == maj_r)
	  return maj_l;
  else {
	  int l_ct = 0;
	  int r_ct = 0;
	  for (int j = left; j < right; j++) {
		  if (a[j] == maj_l)
			  l_ct++;
		  else if (a[j] == maj_r)
			  r_ct++;
	  }
	  if ((l_ct >= r_ct) && (l_ct > ((right - left) / 2)))
		  return maj_l;
	  if (r_ct >= l_ct && (r_ct > ((right - left) / 2)))
		  return maj_r;
	  else return -1;

  }

}


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
