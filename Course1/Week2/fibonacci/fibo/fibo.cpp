#include <iostream>




int calc_fib(int n) {
	int *nn = new int[n];
	if (n == 0)
		return 0;
	if (n < 2)
		return n;
	nn[0] = 0;
	nn[1] = 1;
	int res;

	for (int i = 2; i <= n; i++) {
		nn[i] = nn[i - 2] + nn[i - 1];

	}
	return nn[n];
}


int main() {
	int n = 0;
	std::cin >> n;

	std::cout << calc_fib(n) << '\n';
	return 0;
}