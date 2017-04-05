#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif


std::ifstream file_inp;
std::ofstream file_out;


using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    //cin >> n;
	file_inp >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
//      cin >> key[i] >> left[i] >> right[i];
	  file_inp >> key[i] >> left[i] >> right[i];

    }
  }


  vector <int> in_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
	in_order(0, result);
    return result;
  }

  void in_order(int index, vector<int> &res){
	  if (left[index] != -1)
		 in_order(left[index], res);
	  res.push_back(key[index]);
	  if (right[index] != -1)
		 in_order(right[index], res);
  }

  vector <int> pre_order() {
    vector<int> result;    
    // Finish the implementation
    // You may need to add a new recursive method to do that
	pre_order(0, result);
    return result;
  }

  void pre_order(int index, vector<int> &res){
	  res.push_back(key[index]);
	  if (left[index] != -1)
		  pre_order(left[index], res);
	  if (right[index] != -1)
		  pre_order(right[index], res);
  }

  vector <int> post_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
	post_order(0, result);
    return result;
  }

  void post_order(int index, vector<int> &res){
	  if (left[index] != -1)
		  post_order(left[index], res);
	  if (right[index] != -1)
		  post_order(right[index], res);
	  res.push_back(key[index]);
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      //cout << ' ';
	  file_out << ' ';
    }
    //cout << a[i];
	file_out << a[i];
  }
  //cout << '\n';
  file_out << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  
  file_inp.open("tests\\21");
  file_out.open("tests\\21.out");
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  int u;
  cin >> u;
  file_inp.close();
  file_out.close();
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

