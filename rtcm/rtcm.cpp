#include "rtcm.h"



const unsigned short RTCM::Table_CRC16[256] = { 0x0, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,
0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef, 0x1231, 0x210, 0x3273,
0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6, 0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c,
0xf3ff, 0xe3de, 0x2462, 0x3443, 0x420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485, 0xa56a,
0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d, 0x3653, 0x2672, 0x1611, 0x630,
0x76d7, 0x66f6, 0x5695, 0x46b4, 0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d,
0xc7bc, 0x48c4, 0x58e5, 0x6886, 0x78a7, 0x840, 0x1861, 0x2802, 0x3823, 0xc9cc, 0xd9ed,
0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b, 0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71,
0xa50, 0x3a33, 0x2a12, 0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0xc60, 0x1c41, 0xedae, 0xfd8f, 0xcdec,
0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49, 0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32,
0x1e51, 0xe70, 0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78, 0x9188,
0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f, 0x1080, 0xa1, 0x30c2, 0x20e3,
0x5004, 0x4025, 0x7046, 0x6067, 0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f,
0xf35e, 0x2b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256, 0xb5ea, 0xa5cb,
0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d, 0x34e2, 0x24c3, 0x14a0, 0x481, 0x7466,
0x6447, 0x5424, 0x4405, 0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c,
0x26d3, 0x36f2, 0x691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634, 0xd94c, 0xc96d, 0xf90e,
0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab, 0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x8e1,
0x3882, 0x28a3, 0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a, 0x4a75,
0x5a54, 0x6a37, 0x7a16, 0xaf1, 0x1ad0, 0x2ab3, 0x3a92, 0xfd2e, 0xed0f, 0xdd6c, 0xcd4d,
0xbdaa, 0xad8b, 0x9de8, 0x8dc9, 0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0,
0xcc1, 0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8, 0x6e17, 0x7e36,
0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0xed1, 0x1ef0 };

RTCM::RTCM(std::ostream& io) :out_stream(io){
	bit_queue = new std::queue<char>();
	prev_word = 0;
}

char RTCM::get_bit(void){
	char r_val = bit_queue->front();
	bit_queue->pop();
	return r_val;
}

char RTCM::show_bit(void){
	char r_val = bit_queue->front();
	return r_val;
}

int RTCM::add_bits(std::ifstream &ifile){
	char byte;
	int k = 0;
	while (!ifile.eof()){
		ifile >> byte;
		bit_queue->push(byte & 0x1);
		k++;
	}
	
	return k;
}
int RTCM::add_bits(std::vector<char> data){
	int k = 0;
	for (char byte : data){
		for (int i = 0; i < 6; i++){
			bit_queue->push(byte & 0x1);
			byte >>= 1;
			k++;
		}
	}
	return k;
}

void RTCM::processing(void){
	std::map<std::string, std::pair<int, int> > ;
	std::queue<char> bit_queue_hlp = *bit_queue;

}

bool RTCM::find_preamble(void){
	static int preamble = 0;
	bool find_preamble = false;
	preamble = preamble << 1;
	preamble |= get_bit();
		if (((preamble & 0x3FC00000) == 0x19800000)){

			if (!check_parity(preamble))
				find_preamble = true;
		}
		else if ((preamble & 0x3FC00000) == 0x26400000){
			if (!check_parity(0x03fffffc0L & ~preamble))
				find_preamble = true;
		}
		return find_preamble;
}

int RTCM::sum_mod_2(unsigned int in){
	//in >>= 6;
	int res = 0;
	for (int i = 0; i < 32; i++){
		res ^= (in >> i) & 0x1;
	}
	return res & 0x1;
}


void RTCM::add_CRC16(unsigned short* crc, unsigned char c)
{
	unsigned short cval = ((*crc >> 8) ^ c) & 0xFF;  // Получить обьединяющую величину
	*crc = (*crc << 8) ^ Table_CRC16[cval];
}

std::vector<char> RTCM::delete_binr(std::vector<char>& in_out){
	std::vector<char> res_file;
	int index = 0;
	static int key = 0;
	static unsigned char twoBytes[2] = { 0 };
	static char twin[2] = { 0 };
	static char package[16384] = { 0 };
	static unsigned short outCRC = 0;
	static unsigned char foundCRC;
	static unsigned char flagStart;
	unsigned short ctrCRC = 0;
//	char test[1024];
	int numB = 0;
	static int s=0;
	for (char byte : in_out){

		twoBytes[0] = twoBytes[1];
		twoBytes[1] = byte;
		if (((twoBytes[0] == 0x10) && (twoBytes[1] != 0x10) && (twoBytes[1] != 0xFF) && (twoBytes[1] != 0x3)) && (flagStart == 0))
		{
			outCRC = 0;
			flagStart = 0x1;
			foundCRC = 0;
			index = 0;
			numB++;
			char hlp[20];
			sprintf(hlp, "%x", twoBytes[1]);
			std::cout << numB << " " << hlp << "   ";
			//memset(test, 0, 1024);
			s = 0;
		}
		else{
			if (flagStart & 0x1){
				if ((twoBytes[0] == 0x10) && (twoBytes[1] == 0x10) && (flagStart == 1) && (foundCRC == 0))
					flagStart |= 0x2;
				if ((twoBytes[0] == 0x10) && (twoBytes[1] == 0xFF))
					flagStart |= (3 << 2);
				if ((twoBytes[0] == 0x10) && (twoBytes[1] == 0x3))
					foundCRC |= 2;

				if ((flagStart & 0x1C) > 0){
					flagStart -= 0x4;

					if ((flagStart & 0x1C) == 0){
						ctrCRC = (twoBytes[1] << 8) | twoBytes[0];
						if (ctrCRC == outCRC){
							foundCRC |= 1;
							std::cout << "CRC BINR OK   " << /*test <<*/ std::endl;
						}

						else{
							foundCRC = 0;
							flagStart = 0;
							std::cout << "CRC BINR BAD !!!!!!!!!!!!!" << std::noskipws << /*test <<*/  std::endl;
						}
					}

				}

				if ((flagStart & 0x2) == 0){
					package[index++] = twoBytes[0];
				}
				else
					flagStart &= 0xFD;
				if ((flagStart & 0x1C) == 0){
					add_CRC16(&outCRC, twoBytes[0]);
					//s += sprintf(test + s, "%x +", twoBytes[0]);
				}


			}

			if (foundCRC == 3)
			{
				foundCRC = 0;
				flagStart = 0;
				package[index++] = 0x3;
				if (package[0] == 0x75){
					for (int i = 1; i < 9; i++){
						res_file.push_back(package[i]);
					}
				}

			}
		}
	}

	return res_file;
}

int RTCM::check_parity(unsigned int word){
	unsigned int bit1 = 0;
	unsigned int bit2 = 0;
	unsigned int bit3 = 0;
	unsigned int bit4 = 0;
	unsigned int bit5 = 0;
	unsigned int bit6 = 0;
	unsigned int crc = word & 0x3F;

//	if (word & 0x40000000)
//		word ^= 0x3fffffc0L;
		//word = (0x3fffffc0L & ~word);

	bit1 = (/*((prev_word >> 1) & 0x1) ^*/ sum_mod_2(word & PB[0])) << 5;
	bit2 = (/*((prev_word >> 0) & 0x1) ^*/ sum_mod_2(word & PB[1])) << 4;
	bit3 = (/*((prev_word >> 1) & 0x1) ^*/ sum_mod_2(word & PB[2])) << 3;
	bit4 = (/*((prev_word >> 0) & 0x1) ^*/ sum_mod_2(word & PB[3])) << 2;
	bit5 = (/*((prev_word >> 0) & 0x1) ^*/ sum_mod_2(word & PB[4])) << 1;
	bit6 = (/*((prev_word >> 1) & 0x1) ^*/ sum_mod_2(word & PB[5])) << 0;


	prev_word = crc & 0x3;

/*	bit1 = bit1 ^ (crc & 0x20);
	bit2 = bit2 ^ (crc & 0x10);
	bit3 = bit3 ^ (crc & 0x8);
	bit4 = bit4 ^ (crc & 0x4);
	bit5 = bit5 ^ (crc & 0x2);
	bit6 = bit6 ^ (crc & 0x1);
*/

	
	return bit1 + bit2 + bit3 + bit4 + bit5 + bit6;
}