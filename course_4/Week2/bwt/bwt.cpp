#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string BWT(const string& text) {
  string result = "";

  // write your code here
  int len_str = text.length();
  vector<string> bwt_res(len_str);
  bwt_res[0] = text[len_str - 1];
  bwt_res[0] += text.substr(0, len_str - 1);
  for (int i = 1; i < len_str; i++){
	  bwt_res[i] = bwt_res[i - 1][len_str-1];
	  bwt_res[i] += bwt_res[i - 1].substr(0, len_str - 1);
  }
  std::sort(bwt_res.begin()++, bwt_res.end());
  for (int i = 0; i < len_str; i++){
	  result += bwt_res[i][len_str - 1];

  }
  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;

  return 0;
}