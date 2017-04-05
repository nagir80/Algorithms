#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> dp_optimal_sequence(int n) {
   vector<int> sequence;
   int pred = 0;
   unsigned int *arr = new unsigned int[n];


   arr[0] = 1;

   for (unsigned int i = 2; i <= n; i++) {
	   unsigned int res[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
	   if (i % 3 == 0)
		   res[0] = arr[i / 3 - 1];
	   if (i % 2 == 0)
		   res[1] = arr[i / 2 - 1];
	   res[2] = arr[i - 1 - 1];

	   if (res[0] <= res[1] && res[0] <= res[2]) {
		   arr[i - 1] = res[0] + 1;

	   }
	   else if (res[1] <= res[0] && res[1] <= res[2]) {
		   arr[i - 1] = res[1] + 1;

	   }
	   else if (res[2] <= res[0] && res[2] <= res[1]) {
		   arr[i - 1] = res[2] + 1;
	   }

	   //   std::sort(arr[0], arr[2]);

   }

   	   while (n >= 1) {
		   sequence.push_back(n);
		   if ((n % 3 == 0) && (arr[n - 1] == (arr[(n / 3) - 1] + 1))) {
					n /= 3;
		   }
		   else if ((n % 2 == 0) && (arr[n - 1] == (arr[(n / 2) - 1] + 1))) {
			   n /= 2;
		   }
		   else {
			   n = n - 1;
		   }
	   }
   reverse(sequence.begin(), sequence.end());
   return sequence;

}

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  //vector<int> sequence = optimal_sequence(n);
  vector<int> sequence = dp_optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }

  int k;
  std::cin >> k;
}
