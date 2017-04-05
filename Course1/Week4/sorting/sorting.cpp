#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

std::pair<int, int> partition3(vector<int> &a, int l, int r) {
	int x = a[l];
	int j = l;
	int eq = l;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] == x) {
			eq++;
			swap(a[i], a[eq]);
		}
		if (a[i] < x) {
			j++;
			swap(a[i], a[j]);
		}
		if (eq > j) j++;

	}
	for (int i = 0; i < j-eq; i++) {
		swap(a[l+i], a[j-i]);
	}
	return std::pair<int, int>(l+j, l+j+eq);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
//  int m = partition2(a, l, r);
//  randomized_quick_sort(a, l, m - 1);
//  randomized_quick_sort(a, m + 1, r);

  std::pair<int, int> m = partition3(a, l, r);
  randomized_quick_sort(a, l, m.first-1);
  randomized_quick_sort(a, m.second + 1, r);

}

int main() {
	int n;
//	std::cin >> n;
//	vector<int> a(n);
//	for (size_t i = 0; i < a.size(); ++i) {
//		std::cin >> a[i];
//	}
	n = 10;
//	vector<int> a = { 3,2,3,2,2,4,4,4,4,5 };
	vector<int> a = { 10,9,8,7,6,5,4,3,2,1};

	randomized_quick_sort(a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cout << a[i] << ' ';
	}

	int i;
	std::cin >> i;
}
