#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;
	// write your code here
	int n = values.size();
	vector<int> res_sort(n, 0);
	for (int i = 0; i < n; i++) {
		double max_price = 0;
		int index_max;
		if (capacity == 0) return value;
		for (int j = 0; j < n; j++) {
			double d_hlp = (double)values[j] / weights[j];
			if (d_hlp > max_price) {
				max_price = d_hlp;
				index_max = j;
			}
		}
		values[index_max] = 0;
		int a = capacity > weights[index_max] ? weights[index_max] : capacity;
		value += a*max_price;
		capacity -= a;

	}

  return value;
}

int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}