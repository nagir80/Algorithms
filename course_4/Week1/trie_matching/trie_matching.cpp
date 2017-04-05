#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int const Letters =    4;
int const NA      =   -1;




typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(const vector<string> & patterns) {
	trie t;
	// write your code here
	int n = 1;
	for (string str : patterns){
		int currentNode = 0;
		for (char c : str){
			edges hlp_edge;
			if (currentNode < t.size())
				hlp_edge = t[currentNode];
			else
				hlp_edge.clear();
			if (hlp_edge[c] != NULL){
				currentNode = hlp_edge[c];
			}
			else{
				if (currentNode < t.size()){
					t.at(currentNode)[c] = n;
					currentNode = n;
					t.resize(t.size() + 1);

				}
				else{
					t.resize(t.size() + 1);
					hlp_edge[c] = n;
					currentNode = n;
					t.at(currentNode - 1) = (hlp_edge);

				}
				n++;
			}

		}
	}
	return t;
}

struct Node
{
	int next [Letters];

	Node ()
	{
		fill (next, next + Letters, NA);
	}

	bool isLeaf () const
	{
	    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
	}
};




int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

bool prefix_trie_matching(string& text, trie& t){
	bool result = false;
	auto text_it = text.begin();
	int n = 0;
	while (1){
		edges cur_map;
		if (n < t.size())
			cur_map = t[n];
		else if (n == 0)
			break;
		else if (n > 0){
			result = true;
			break;
		}
		if (cur_map.empty()){
			result = true;
			break;
		}
		int h_int = 0;
		if (text_it != text.end()){
			h_int = cur_map[*text_it];
			if (h_int > 0){
				n = h_int;
				text_it++;
			}
			else
				break;
		}
		else 
			break;
		
	}

	return result;
}

vector <int> solve (const string& text, int n, const vector <string>& patterns)
{
	vector <int> result;

	// write your code here
	string text1 = text;
	trie t = build_trie(patterns);
	int ctr = 0;
	while (!text1.empty()){
		if (prefix_trie_matching(text1, t))
			result.push_back(ctr);
		text1.erase(text1.begin());
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

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (t, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
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
