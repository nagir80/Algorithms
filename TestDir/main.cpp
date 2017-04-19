#include <iostream>
#include <set>
#include <iterator>


extern void func1(std::string str);

int main (int argc, char** argv){
   std::set<int> cont;
   cont.insert(1);
   cont.insert(5);
   cont.insert(2);
   cont.insert(45);
   cont.insert(3);
   for(auto it = cont.begin(); it != cont.end(); it++){
      std::cout << *it << " ";
   }
   std::cout << std::endl;
   func1("AAAAAA");
   return 0;
}


