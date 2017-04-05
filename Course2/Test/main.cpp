#include "main.h"
#include "test_template.h"
#include <iostream>

int sqqr(int a){
	return a*a;
}

std::vector<int> in = {0,1,2,3,4};
std::vector<int> out = {0,2,4,8};


int main(int argc, int* argv){
//	in.push_back(0); out.push_back(0);
//	in.push_back(1); out.push_back(1);
//	in.push_back(2); out.push_back(3);
//	in.push_back(3); out.push_back(9);


	TEST_TEMPLATE<int,int>  *test_class = new TEST_TEMPLATE<int, int>(sqqr, &in, &out);

	test_class->start_test();
	return 0;
}