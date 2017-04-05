#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;



int char_to_ind(char c){
	switch (c){
	case 'A':
		return 0;

		break;
	case 'C':
		return 1;

		break;
	case 'G':
		return 2;

		break;
	case 'T':
		return 3;

		break;
	case '$':
		return 4;

		break;


	}
}


string InverseBWT(const string& bwt) {
	string text = "";
	int len_str = bwt.length();
	text.resize(len_str);
	// write your code here
	string first = bwt;
	vector<int> exprt(len_str, 0);
	vector<int> bwt_count(5, 0);
	vector<int> bwt_count2(5, 0);

	for (int i = 0; i < len_str; i++){
		bwt_count[char_to_ind(bwt[i])]++;
	}
	
	for (int i = 0; i < len_str; i++){
		
		switch (bwt[i]){
		case 'A':
			exprt[1 + bwt_count2[0]] = i;
				break;
		case 'C':
			exprt[1 + bwt_count[0] + bwt_count2[1]] = i;
			break;
		case 'G':
			exprt[1 + bwt_count[0] + bwt_count[1] + bwt_count2[2]] = i;
			break;
		case 'T':
			exprt[1 + bwt_count[0] + bwt_count[1] + bwt_count[2] + bwt_count2[3]] = i;
			break;
		case '$':
			exprt[0] = i;
			break;

		}
		bwt_count2[char_to_ind(bwt[i])]++;
		
		if (i == 0)
			first[i] = '$';
		else if (i <= bwt_count[0])
			first[i] = 'A';
		else if (i <= (bwt_count[0] + bwt_count[1]))
			first[i] = 'C';
		else if (i <= (bwt_count[0] + bwt_count[1] + bwt_count[2]))
			first[i] = 'G';
		else if (i <= (bwt_count[0] + bwt_count[1] + bwt_count[2] + bwt_count[3]))
			first[i] = 'T';

	}

	char f_el = '$';
	int f_occ = 0;
	int ctr = 0;
	int n = 0;
	while (ctr < len_str){
		n = exprt[n];
		text[ctr] = first[n];
		ctr++;

	}

  return text;
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
//  int i;
//  cin >> i;
  return 0;
}
