#include "string"
#include "iostream"
#include "fstream"
#include "cstdlib"
#include "limits"
#include "time.h"
class RandomizeFileGen{
	std::string filename;
	int size;
	int size_r;
	int* sequence;
	std::ostream &out_f;
public:
	RandomizeFileGen(std::ostream& out_f, int sz) :out_f(out_f), size(sz){
		srand(time(0));


	}
	void start_randomize(void){
		if (size == 0)
			size_r = rand() % 100000 + 1;
		else
			size_r = size;
		sequence = new int[size_r];
		for (int i = 0; i < size_r; i++){
			sequence[i] = 0;
		}
		for (int i = 0; i < size_r; i++){
			int index;

			do{
				index = rand() % size_r;
			} while (sequence[index] != 0);
			sequence[index] = i + 1;
		}

		out_f << size_r << std::endl;
		for (int i = 0; i < size_r; i++){
			out_f << sequence[i] << " ";
		}
		out_f << std::endl;
	}
	int get_size(){
		return size_r;
	}
	~RandomizeFileGen(){
		
	}


};