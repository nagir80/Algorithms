#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>


struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
//	std::ifstream file1;
//	std::string path("c:\\Algorithms\\Course2\\Week1\\check_brackets_in_code\\tests\\");
//	std::ifstream file2;
//	std::string in_formula;
//	std::string out_res;
	/*
	for (int i = 1; i <= 54; i++){
		char path_add[8];
		sprintf(path_add, "%02i", i);
		file1.open(path + path_add);
		if (file1.is_open()){
			file1 >> in_formula;
			file1.close();
		}

		file2.open(path + path_add + ".a");
		if (file2.is_open()){
			file2 >> out_res;
			file2.close();
		}
		*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////
		std::string text;
		getline(std::cin, text);
		std::stack <Bracket> opening_brackets_stack;
		int result = 0;
		for (int position = 0; position < text.length(); ++position) {
			char next = text[position];

			if (next == '(' || next == '[' || next == '{') {
				// Process opening bracket, write your code here
				opening_brackets_stack.push(*new Bracket(next, position));
			}
			if (next == ')' || next == ']' || next == '}') {
				// Process closing bracket, write your code here
				if (!opening_brackets_stack.empty()){
					Bracket ret = opening_brackets_stack.top();
					if (ret.Matchc(next)){
						opening_brackets_stack.pop();

					}
					else{
						opening_brackets_stack.push(*new Bracket(next, position));
						break;
					}
						
				}
				else{
					opening_brackets_stack.push(*new Bracket(next, position));
					break;
				}
					

			}
		}


		// Printing answer, write your code here
/*		char res_str[50];
		int res_i;

		if (opening_brackets_stack.empty()){
			strcpy(res_str, "Success");
		}
		else{
			res_i = opening_brackets_stack.top().position+1;
			sprintf(res_str, "%i", res_i);
		}
		std::cout << i << "  -   ";
		if (out_res.compare(res_str) == 0)
			std::cout << "TRUE" << std::endl;
		else
			std::cout << "FALSE !!!!!!!!!!!!" << "   "  << in_formula  << out_res << "      " << res_str << std::endl;
*/

		if (opening_brackets_stack.empty()){
			std::cout << "Success";
		}
		else
			std::cout << opening_brackets_stack.top().position + 1;


///////////////////////////////////////////////////////////////////////////////////////////////////////////






//	}



 

    return 0;
}
//