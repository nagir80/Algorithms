#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "rtcm.h"
#include "memory"


typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef signed short int16_t;
typedef unsigned int uint32_t;
typedef signed int int32_t;

unsigned int word[2];


std::vector<char> read_data(const char* name){
	std::vector<char> data;
	char elm;
	std::ifstream f_in;
	f_in.open(name, std::ios_base::binary);
	while (!f_in.eof()){
		f_in >> std::noskipws >>elm;
		data.push_back(elm);
	}
	f_in.close();
	return data;
}


int main(int argc, char* argv[]){
	unsigned int n_err = 0;
	std::vector<char> file_data;
	file_data = read_data("binr0.log");
	std::ifstream file_in_bits;
	file_in_bits.open("0_1_log2.txt", std::ios_base::binary);
	std::ofstream fout;
	std::ofstream rtcm_out("pki_out.txt", std::ios_base::binary);
	fout.open("mod.out", std::ios_base::binary);
	std::shared_ptr<RTCM> rtcm_pr(new RTCM(std::cout));
	/*
	file_data = rtcm_pr->delete_binr(file_data);
	rtcm_pr->add_bits(file_data);
//	rtcm_pr->add_bits(file_in_bits);
	int state = 0;
	int flSinkAll = 0;
	unsigned char in_word[5];
	int cur_bit;
	unsigned char send_byte;
	*/
	int i1 = rtcm_pr->check_parity(0x59954D71);
//	int i2 = rtcm_pr->check_parity(0x10c4e221);
	/*
	while (!rtcm_pr->is_empty()){


		switch (state){
		case 0:
			if (rtcm_pr->find_preamble()){
				state = 1;
				flSinkAll = 1;
			}
			break;

		case 1:

	//		word[0] = 0;
			for (int t = 0; t < 30; t++){
				word[0] = word[0] << 1;
				if (rtcm_pr->is_empty())
					break;
				word[0] |= rtcm_pr->get_bit();
				if (!rtcm_pr->is_empty()){
					char bit = rtcm_pr->show_bit();
					send_byte |= (bit << (t % 6));
					if ((t % 6) == 5){
						send_byte |= 0x40;
						rtcm_out << send_byte;
						//in_word[(int)cur_bit / 6] = send_byte;
						send_byte = 0;
					}
				}
			}
			int result;
			result = rtcm_pr->check_parity(word[0]);
			if (result){
				n_err++;
				state = 0;
				std::cout << " RTCM ERROR" << std::endl;
				fout << "ERROR" << std::endl;
			}
			else{
				std::cout << " RTCM OK" << std::endl;
				fout << "Word: " << std::hex << word[0] << "   Parity: " << std::hex << result << std::endl;
			}

			break;
		}

	}
	rtcm_out.close();
	std::cout << "nErr = " << std::dec << n_err << std::endl;

*/


	int i;

	std::cin >> i;
	return 0;

}