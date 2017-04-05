#ifndef _RTCM_H_
#define _RTCM_H_
#include <queue>
#include <map>

#include <iostream>
#include <fstream>

static const int PB[6] = { 0xbb1f34A0, 0x5d8f9a50, 0xAec7cd08, 0x5763e684, 0x6bb1f342, 0x8b7a89c1};

class RTCM{
	std::ostream& out_stream;
	std::queue<char> *bit_queue; // вектор битов входящих
	std::map<std::string, std::pair<int, int> > result;
	unsigned int prev_word;
public:
	static const unsigned short Table_CRC16[256];
	RTCM(std::ostream& io);
	char get_bit(void);
	char show_bit(void);

	int add_bits(std::vector<char> data);
	int add_bits(std::ifstream &ifile);
	std::vector<char> delete_binr(std::vector<char>& in_out);
	bool is_empty(void){ return bit_queue->empty(); }
	int size(void){ return bit_queue->size(); }
	void processing(void);
	int sum_mod_2(unsigned int in);
	int check_parity(unsigned int word);
	bool find_preamble(void);
	void set_prev_word(unsigned int prev){
		prev_word = prev;
	}
	void add_CRC16(unsigned short* crc, unsigned char c);
	std::ostream& get_stream(void) { return out_stream; }
	
};


#endif;