#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.

int char_to_index(char in){
	switch (in){
	case '$' :
		return 0;
		break;
	case 'A':
		return 1;
		break;
	case 'C':
		return 2;
		break;
	case 'G':
		return 3;
		break;
	case 'T':
		return 4;
		break;

	}
}

vector<int> counting_sort(const string& text){
	int len = text.length();
	vector<int> order(len, 0);
	vector<int> count(5, 0);
	for (int i = 0; i < len; i++){
		count[char_to_index(text[i])] ++;
	}
	for (int j = 1; j < 5; j++){
		count[j] = count[j] + count[j - 1];
	}
	for (int i = len-1; i >= 0; i--){
		char c = text[i];
		count[char_to_index(c)]--;
		order[count[char_to_index(c)]] = i;
	}
	return order;

}

vector<int> sort_doubled(const string& text, int L, vector<int>& order, vector<int>& clas){
	int len = text.length();
	vector<int> newOrder(len, 0);
	vector<int> count(len, 0);
	for (int i = 0; i < len; i++){
		count[clas[i]] ++;
	}
	for (int j = 1; j < len; j++){
		count[j] = count[j] + count[j - 1];
	}
	for (int i = len - 1; i >= 0; i--){
		int start = (order[i] - L + len) % len;
		int cl = clas[start];
		count[cl] = count[cl] - 1;
		newOrder[count[cl]] = start;

	}
	return newOrder;
}

vector<int> computing_char_classes(const string& text, vector<int> &order){
	int len = text.length();
	vector<int> clas(len, 0);
	clas[order[0]] = 0;
	for (int i = 1; i < len; i++){
		if (text[order[i]] != text[order[i - 1]])
			clas[order[i]] = clas[order[i - 1]] + 1;
		else
			clas[order[i]] = clas[order[i - 1]];
	}
	return clas;
}

vector<int> update_classes(vector<int> &newOrder, vector<int> clas, int L){
	int n = newOrder.size();
	vector<int> newClas(n, 0);
	newClas[newOrder[0]] = 0;
	for (int i = 1; i < n; i++){
		int cur = newOrder[i];
		int prev = newOrder[i - 1];
		int mid = (cur + L) % n;
		int midPrev = (prev + L) % n;
		if ((clas[cur] != clas[prev]) || (clas[mid] != clas[midPrev]))
			newClas[cur] = newClas[prev] + 1;
		else
			newClas[cur] = newClas[prev];

	}
	return newClas;
}

vector<int> BuildSuffixArray(const string& text) {
  vector<int> result;
  // Implement this function yourself
  vector<int> order;
  vector<int> clas;
  order =  counting_sort(text);
  clas = computing_char_classes(text, order);
  int L = 1;
  while (L < text.length()){
	  order = sort_doubled(text, L, order, clas);
	  clas = update_classes(order, clas, L);
	  L = 2 * L;
  }
  return order;
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
