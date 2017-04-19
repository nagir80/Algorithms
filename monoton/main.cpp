#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>

int main(int argc, char** argv){
	long double n;
	std::string in_line;
	std::size_t sz;
	std::size_t sum_sz = 0;

	std::vector<long double> vec_res;
	char buf[100];
	std::getline(std::cin, in_line);
	try{
		std::string hlp;
		int ctr = 0;
		n = std::stold(in_line.substr(sum_sz), &sz); sum_sz += sz;
		while (sum_sz < in_line.length()){
			vec_res.push_back(std::stold(in_line.substr(sum_sz), &sz)); 
			sum_sz += sz;
			ctr++;
		}
		if ((ctr < 2) || (ctr < round(n)) || (n <= 1) || (n != round(n))){
			std::cout << "[error]" << std::endl;
			return 0;
		}

	}
	catch (...){
		std::cout << "[error]" << std::endl;
		return 0;
	}
	long long st_num = 1;
	long long max_length = 1;
	long long cur_length = 1;

	for (long long i = 1; i < round(n); i++){
		if (vec_res[i] >= vec_res[i - 1]){
			cur_length++;
			if (cur_length > max_length){
				max_length = cur_length;
				st_num = i-max_length+1;
			}
		}
		else{
			cur_length = 1;
		}
	}

	if (max_length <= 1)
		std::cout << "0" << std::endl;
	else
		std::cout << max_length << " " << (st_num+1) << std::endl;


	return 0;
}