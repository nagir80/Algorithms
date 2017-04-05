#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <atomic>

#define START_HASH(x) ((0x10+x*207)%1000007)%1000
#define START_CRC_HASH ((0x10 + 0xFF*207)%1000007)%1000
#define END_MSG_HASH ((0x10 + 0x3*207)%1000007)%1000
#define DOUBLE_TEN_HASH ((0x10 + 0x10*207)%1000007)%1000

int flags = 0; //xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxx(75)
int st_ind = -1;
int crc_ind = -1;
int fin_ind = -1;
int thr_flag = 0;
struct Buf{
	unsigned char buf[4096];
	std::atomic<int> in = 0;
	std::atomic<int> out = 0;
} data_buf, out_buf;

std::ifstream in_file;
std::ofstream out_file;
std::mutex mutex1;

long long get_hash(unsigned char *in){
	
	return ((in[0] + in[1] * 207) % 1000007) % 1000;
}


void get_data(std::ifstream& in_s, Buf* buff){
	while (!in_s.eof()){
		in_s >> std::noskipws >> buff->buf[(buff->in) & 0xFFF];
		buff->in++;
	}
	thr_flag = 1;
}

void put_data(std::ofstream& out_s, Buf* buff){
	while (1){
		char *b = new char[200];
		while (out_buf.out != out_buf.in){

			sprintf(&b[out_buf.out*2], "%2X", out_buf.buf[out_buf.out]);
			

			out_buf.out++;
		}
		out_buf.in = out_buf.out = 0;
	}
}

void work_proc(void){
	while (1){
		while (data_buf.in != data_buf.out){
			if ((data_buf.in - data_buf.out) > 2){
				long long hash = get_hash(&data_buf.buf[data_buf.out]);
				if (hash == START_HASH(0x75)){

					flags &= 0x1;
					st_ind = data_buf.out;
				}
				else
				if (hash == START_CRC_HASH){
					crc_ind = data_buf.out;
				}
				else
				if (hash == END_MSG_HASH){
					fin_ind = data_buf.out+2;
					if ((st_ind >= 0) && (crc_ind >= 0) && (fin_ind >= 0)){
						while (st_ind < fin_ind){
							out_buf.buf[out_buf.in] = data_buf.buf[st_ind];
							st_ind++;
							out_buf.in++;
						}
						st_ind = -1;
						fin_ind = -1;
						crc_ind = -1;
					}
				}
				data_buf.out++;
				
			}

		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}


int main(const int argc, const char **argv){
	argv[1] = "binr12.log";
	argv[2] = "result.out";
	in_file.open(argv[1], std::ios_base::binary);
	out_file.open(argv[2], std::ios_base::binary);
	
//	get_data(in_file, &data_buf);
//	put_data(out_file, &data_buf);

	std::thread user_inp(get_data, std::move(in_file), &data_buf);
	std::thread user_output(put_data, std::move(out_file), &data_buf);
	std::thread main_work(work_proc);

	main_work.join();
	user_inp.join();
	user_output.join();
	in_file.close();
	out_file.close();
	return 0;
}