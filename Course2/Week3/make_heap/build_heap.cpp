#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
//#include <Randomize.h>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

//#define _FILE_TEST_

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
#ifdef _FILE_TEST_
	  std::ofstream *file_out = new std::ofstream("tests//04.out");
	  *file_out << swaps_.size() << "\n";
#else
	  cout << swaps_.size() << "\n";
#endif
	
    for (int i = 0; i < swaps_.size(); ++i) {
	
#ifdef _FILE_TEST_
		*file_out << swaps_[i].first << " " << swaps_[i].second << "\n";
	
#else
		cout << swaps_[i].first << " " << swaps_[i].second << "\n";
#endif
    }
#ifdef _FILE_TEST_
	file_out->close();
#endif
	
  }

  void ReadData() {
    int n;
#ifdef _FILE_TEST_
	std::ifstream *file_in = new std::ifstream("tests//06",std::ios_base::in);
	*file_in >> n;
#else
    cin >> n;
#endif
    data_.resize(n);
    for(int i = 0; i < n; ++i)
#ifdef _FILE_TEST_
		*file_in >> data_[i];
#else
		cin >> data_[i];
#endif
		
	

  }

 

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
	/*
    for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }
	  */
	if (data_.size() > 1)
	for (int i = floor((data_.size() - 2) / 2); i >= 0; --i){
		siftDown(i);
	
	}

	
  }
  /*
  void testFunction(){
	  int counter = 0;
	  if (data_.size() > 1){
		  for (int i = 0; i <= floor((data_.size() - 2) / 2); i++){

			  if (i < floor((data_.size() - 2) / 2)){
				if ((data_[i] < data_[left_child(i)]) && ((data_[i] < data_[right_child(i)])))
					 counter++;
			  }
			  else
				if ((data_[i] < data_[left_child(i)]))
					counter++;


		  }
		  if (counter == ceil((float)(data_.size()-1) / 2))
			  cout << "OK" << std::endl;
		  else{
			  cout << "WRONG ANSWER" << std::endl;
			  while (1);
		  }
	  }

  }
  */
  


  int left_child(int i){
	return i * 2 + 1;
  }
  int right_child(int i){
	return i * 2 + 2;
  }

  void siftDown(int i){
	  int i1 = left_child(i);
	  int i2 = right_child(i);
	  int i3 = data_.size();

	  while ((left_child(i) < data_.size()) || (right_child(i) < data_.size())){
		  if (right_child(i) >= data_.size()){
			  if (data_[left_child(i)] < data_[i]){
				  swap(data_[i], data_[left_child(i)]);
				  swaps_.push_back(make_pair(i, left_child(i)));
				  i = left_child(i);
			  }
			  else break;
		  }
		  else{
			  if (data_[left_child(i)] < data_[right_child(i)]){
				  if (data_[i] > data_[left_child(i)]){
					  swap(data_[i], data_[left_child(i)]);
					  swaps_.push_back(make_pair(i, left_child(i)));
					  i = left_child(i);
				  }
				  else break;
			  }
			  else if(data_[left_child(i)] > data_[right_child(i)]){
				  if (data_[i] > data_[right_child(i)]){
					  swap(data_[i], data_[right_child(i)]);
					  swaps_.push_back(make_pair(i, right_child(i)));
					  i = right_child(i);
				  }
				  else break;
			  }
			  

		  }
		 


	  }
  }



 public:

  void Solve() {
    ReadData();
    GenerateSwaps();
//testFunction();
    WriteResponse();
	
  }
};

int main() {
	
	std::ios_base::sync_with_stdio(false);
//	std::ofstream* file = new std::ofstream();
//	RandomizeFileGen *rnd = new RandomizeFileGen(*file, 10);

//	for (int j = 0; j < 100000; j++){
//		file->open("tests//04");
		HeapBuilder heap_builder;
//		rnd->start_randomize();
//		std::cout << "TEST " << "(" << rnd->get_size() <<") " << j << " ";
		heap_builder.Solve();
//		file->close();
		

//	}
//	delete file;
//	delete rnd;

//  int i;
//  cin >> i;
  return 0;
}
