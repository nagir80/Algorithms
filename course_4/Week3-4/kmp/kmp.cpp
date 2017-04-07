#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::string;
using std::vector;

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where 
// the pattern starts in the text.
vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
  // Implement this function yourself
  string work_str = pattern + "$" + text;
  int border = 0;
  vector<int> arr(work_str.length(), 0);
  for (int i = 1; i < work_str.length(); i++){
	  while ((border > 0) && (work_str[i] != work_str[border]))
		  border = arr[border - 1];
	  if (work_str[i] == work_str[border])
		  border++;
	  else
		  border = 0;
	  arr[i] = border;
  }

  for (int i = pattern.length(); i < work_str.length(); i++){
	  if (arr[i] == pattern.length())
		  result.push_back(i - 2 * pattern.length());
  }
  return result;
}

int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");

  int n;
  cin >> n;
  return 0;
}
