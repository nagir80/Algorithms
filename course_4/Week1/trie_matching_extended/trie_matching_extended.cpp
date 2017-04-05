#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int const Letters =    4;
int const NA      =   -1;

struct Node
{
	int next [Letters];
	bool patternEnd;

	Node ()
	{
		fill (next, next + Letters, NA);
		patternEnd = false;
	}
};


char indexToLetter(int ind)
{
	switch (ind)
	{
	case 0: return 'A'; break;
	case 1: return 'C'; break;
	case 2: return 'G'; break;
	case 3: return 'T'; break;
	default: assert(false); return -1;
	}
}
int letterToIndex(char letter)
{
	switch (letter)
	{
	case 'A': return 0; break;
	case 'C': return 1; break;
	case 'G': return 2; break;
	case 'T': return 3; break;
	default: assert(false); return -1;
	}
}

string random_string(const int len) {

	string result = "";
	static const char alphanum[] =
		"ACGT";

	for (int i = 0; i < len; ++i) {
		result += alphanum[rand() % (sizeof(alphanum)-1)];
	}
	return result;
}

string random_string2(const int len) {

	string result = "";
	static const char alphanum[] =
		"A";

	for (int i = 0; i < len; ++i) {
		result += alphanum[rand() % (sizeof(alphanum)-1)];
	}
	return result;
}
vector<int> test(vector<string>& patterns, string& text){
	vector<int> pos;
	for (int i = 0; i< text.size(); i++){
		for (int j = 0; j< patterns.size(); j++){
			if ((patterns[j].size() + i - 1)< text.size()){
				string sub = text.substr(i, patterns[j].size());
				if (sub.compare(patterns[j]) == 0){
					pos.push_back(i);
					break;
				}
			}
		}
	}
	sort(pos.begin(), pos.end());
	return pos;
}

vector<Node*> build_trie(const vector<string>& patterns){
	int flag = 0;
	vector<Node*> result(0);
	Node *nod = new Node();
	result.push_back(nod);
	int lastNode=1;
	for (string pattern : patterns){
		int currentNode = 0;
		int n_pattern = 0;
		for (char c : pattern){
			int hlp_i = result[currentNode]->next[letterToIndex(c)];
			if (n_pattern == (pattern.length() - 1))
				flag = 1;
			if (hlp_i == -1){
				//hlp->next[letterToIndex(c)] = lastNode;
				result[currentNode]->next[letterToIndex(c)] = lastNode;
				result.push_back(new Node);
				currentNode=lastNode;
				lastNode++;
			}
			else{
				currentNode = hlp_i;
			}
			if (flag == 1){
				flag = 0;
				result[currentNode]->patternEnd = true;
			}
			n_pattern++;
			

		}
	}
	return result;
}

bool prefix_trie_matching(string& text,string::iterator start, string::iterator fin, vector<Node*> t){
	bool result = false;
	auto text_it = start;
	int currentNode = 0;
	while (1){
		int n = t[currentNode]->next[letterToIndex(*text_it)];
		if (n >= 0){
			if (t[currentNode]->patternEnd){
				result = true;
				break;
			}
			currentNode = n;
			text_it++;
			if (text_it == fin)
				break;
		}
		else
			break;
	}



	return result;
}

vector <int> solve (string& text, int n, vector <string>& patterns)
{	vector <int> result;
	// write your code here
	string text1 = text;
	vector<Node*> trie = build_trie(patterns);
	int ctr = 0;
	auto st_it = text1.begin();
	auto fin_it = text1.end();
	while (st_it != fin_it){

		bool res = false;
		auto text_it = st_it;
		int currentNode = 0;
		while (1){
			int n = trie[currentNode]->next[letterToIndex(*text_it)];
			if (n >= 0){
				currentNode = n;
				text_it++;
				if (trie[currentNode]->patternEnd){
					res = true;
					break;
				}
				if (text_it == fin_it)
					break;
			}
			else{

				break;
			}
				
		}

		if (res)
			result.push_back(ctr);
		st_it++;
		ctr++;
	}

	return result;
	

}

int main (void)
{
	string t;
	cin >> t;

	


	int n;
	cin >> n;

		vector <string> patterns(n);
			for (int i = 0; i < n; i++)
			{
				cin >> patterns[i];
			}

		vector <int> ans;


		ans = solve(t, n, patterns);


				for (int i = 0; i < (int)ans.size(); i++)
				{
				cout << ans[i];
				if (i + 1 < (int)ans.size())
				{
				cout << " ";
				}
				else
				{
				cout << endl;
				}
				}

	return 0;
}
