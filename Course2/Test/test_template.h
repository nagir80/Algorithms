#ifndef _TEST_TEMPLATE_H_
#define _TEST_TEMPLATE_H_
#include <vector>
template <typename IN, typename OUT>
//typedef int OUT;
//typedef int IN;
class TEST_TEMPLATE{
	OUT(*func)(IN a);
	IN in_vector;
	OUT out_vector;
public:
	TEST_TEMPLATE(OUT(*func_init)(IN a), IN in, OUT out) :func(func_init), in_vector(in), out_vector(out){};

	void start_test(int i) {
		
		if (func(in_vector) == out_vector)
			std::cout << i << " TEST " <<  " SUCCESS" << std::endl;
		else
			std::cout << i << " TEST " <<  " BEDA" << std::endl;
	}



};



#endif