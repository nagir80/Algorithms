#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include "test_template.h"
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif
#define _CRT_SECURE_NO_WARNINGS_


std::vector<int> in;
std::vector<int> out;


class Node;
void form_node(std::istream &in, Node* nodes);
int max_height(Node*  tree);
class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};


int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
//  std::vector<Node*> vec_root;
//  std::vector<int> answer;
  
  int count_test;
  std::cin >> count_test;

  for (int i = 1; i <= count_test; i++){
	  int read_n;
	  char* filename = new char[20];
	  sprintf(filename, "..\\tests\\%.2i", i);
	  std::fstream test_in(filename, std::ios_base::in);
	  sprintf(filename, "..\\tests\\%.2i.a", i);
	  std::fstream test_out(filename, std::ios_base::in);
	  Node* nodes = new Node[count_test];
	  form_node(test_in, nodes);
	  test_out >> read_n;
	  TEST_TEMPLATE<Node*, int>* test_class = new TEST_TEMPLATE<Node*, int>(max_height, nodes, read_n);
	  test_class->start_test(i);

  }

  


  int k;
  std::cin >> k;


  return 0;
}

void form_node(std::istream &in, Node *nodes){
	int n;
	in >> n;
	//std::vector<Node> *nodes = new std::vector<Node>();

	for (int child_index = 0; child_index < n; child_index++) {
		int parent_index;
		in >> parent_index;
		if (parent_index >= 0)
			nodes[child_index].setParent(&(nodes[parent_index]));
		nodes[child_index].key = child_index;
	}


}


int max_height(Node*  tree){
	int root = 0;
	while (tree[root].parent != 0)
		root++;
	if (tree[root].children.empty())
		return 1;
	std::vector<int> heights;
	int imax = 0;
	for (Node* child : tree->children){
		heights.push_back(max_height(child));
	}
	for (int i : heights){
		if (i >= imax)
			imax = i;
	}
	heights.clear();
	return 1+imax;
}

int main (int argc, char **argv)
{
  
  return main_with_large_stack_space();
}
