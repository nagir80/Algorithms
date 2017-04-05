#include <iostream>
#include <iterator>
#include <vector>
#include <limits>
#include <functional>
#include <algorithm>
#include <string>




using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
	long long result = 0;
	int n = numbers.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if ((long long)numbers[i] * numbers[j] > result) {
				result = (long long)numbers[i] * numbers[j];
			}
		}
	}
	return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers) {
	int n = numbers.size();
	int max_index1 = -1;
	for (int i = 0; i < n; ++i)
		if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
			max_index1 = i;
	int max_index2 = -1;
	for (int j = 0; j < n; ++j)
		if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
			max_index2 = j;
//	cout << max_index1 << ' ' << max_index2 << "\n";
	return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main() {
	vector<std::string> coll;
	std::copy(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>(), std::back_inserter(coll));
	std::vector<std::function<int(int, int)>> tasks;

	/*
	tasks.push_back([](int x, int y){
		return x + y;
	});
	tasks.push_back([](int x, int y) {
		return x - y;
	});
	tasks.push_back([](int x, int y) {
		return x * y;
	});
	tasks.push_back([](int x, int y) {
		return x / y;
	});
	tasks.push_back([](int x, int y) {
		return x % y;
	});


	for (auto f : tasks) {
		std::cout << f(5,6) << std::endl;
	}


	std::cout << std::hex << std::numeric_limits<int>::max() << std::endl;
	std::cout << std::hex << std::numeric_limits<unsigned int>::max() << std::endl;
	std::cout << std::hex << std::numeric_limits<long>::max() << std::endl;
	std::cout << std::hex << std::numeric_limits<long long>::max() << std::endl;
	std::cout << std::hex << std::numeric_limits<double>::max() << std::endl;

	std::cout << std::hex << std::numeric_limits<long double>::max() << std::endl;
	std::cout << std::endl;
	std::cout << std::is_integral<double>() << std::endl;
	std::cout << std::common_type<int, int>::type();


//	for (int i = 0; i < n; ++i) {
//		cin >> numbers[i];
//	}

//	long long result1 = MaxPairwiseProduct(numbers);
//	long long result2 = MaxPairwiseProductFast(numbers);

//	cout << result1 << "\n";
//	cout << result2 << "\n";
*/
	int i;
	cin >> i;

	return 0;
}