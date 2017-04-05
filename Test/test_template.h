#ifndef _TEST_TEMPLATE_H_
#define _TEST_TEMPLATE_H_
#include <vector>
template <typename OUT, typename IN>
//typedef int OUT;
//typedef int IN;
class TEST_TEMPLATE{
	OUT(*func)(IN a);
	std::vector<IN> *in_vector;
	std::vector<OUT> *out_vector;
public:
	TEST_TEMPLATE(OUT(*func_init)(IN a), std::vector<IN> *in, std::vector <OUT> *out) :func(func_init), in_vector(in), out_vector(out){};

	void start_test(void) {
		int j = 0;
		for (IN in : *in_vector){
			if ((*out_vector)[j] == func(in))
				std::cout << "SUCCESS" << std::endl;
			else
				std::cout << "BEDA" << std::endl;
			j++;
		}
	}



};



#endif