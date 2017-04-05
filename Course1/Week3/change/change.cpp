#include <iostream>

int get_change(int m) {
  //write your code here
	int arr[3] = { 10,5,1 };
	int n = 0;
	int i = 0;
	while (m > 0) {
		int val = arr[i];
		n += m / arr[i];
		m = m % arr[i];
		i++;
	}
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
