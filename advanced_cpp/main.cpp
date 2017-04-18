#include <iostream>
#include <math.h>
int main(){
	long double i,j;
	long answer;
	std::cin >> i;
	if ((i <= 0) || (i > 9223372036854775807) || (llround(i)!=i))
		std::cout << 0 <<std::endl;
	else{
		j = (sqrt(1 + 8 * i) - 1) / 2;
		if (j == llround(j)){
			answer = j;
			std::cout << answer << std::endl;

		}
		else
			std::cout << 0 << std::endl;
	}
	return 0;

}