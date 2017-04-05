#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};

struct Contact{
	int number;
	string name;
	Contact(int number, string name) :number(number), name(name){}
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

int count_hash(int in_num){
	return ((2 * in_num + 3) % 10000019) % 1000;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<Query> contacts;
	std::map<int, std::list<Contact*>*> new_contacts;
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            bool was_founded = false;
            // if we already have contact with such number,
            // we should rewrite contact's name
			std::list<Contact*> *hlp_list = new std::list<Contact*>();

			int hash;
			hash = count_hash(queries[i].number);
			if (new_contacts[hash] != NULL)
				hlp_list = new_contacts[hash];
			int ii = 0;
			int flag_push = 1;
			std::list<Contact*>::iterator it = hlp_list->begin();
			for (Contact* cnt : *hlp_list){
				if (cnt->number == queries[i].number){
					(*it)->name = queries[i].name;
					flag_push = 0;
					break;
				}
				it++;
			}
			if (flag_push)
				hlp_list->push_back(new Contact(queries[i].number, queries[i].name));
			new_contacts[hash] = hlp_list;
	//		delete hlp_list;

        } else if (queries[i].type == "del") {
			int hash = count_hash(queries[i].number);
			std::list<Contact*> *hlp_list = new std::list<Contact*>();
			if (new_contacts[hash] != NULL){
				hlp_list = new_contacts[hash];
				int ii = 0;
				std::list<Contact*>::iterator it = hlp_list->begin();
				for (Contact* cnt : *hlp_list){
					if (cnt->number == queries[i].number){
						ii = 1;
						break;
					}
						
					it++;
				}
				if (ii > 0){
					hlp_list->erase(it);
					if (hlp_list->empty()){
						new_contacts[hash] = NULL;
					}
				}
			}            
        } else {
            string response = "not found";
			int hash = count_hash(queries[i].number);
			std::list<Contact*> *hlp_list = new std::list<Contact*>();
			if (new_contacts[hash] != NULL){
				hlp_list = new_contacts[hash];
				int ii = 0;
				for (Contact* cnt : *hlp_list){
					if (cnt->number == queries[i].number){
						response = cnt->name;
						break;
					}
						
					ii++;
				}

			}
			result.push_back(response);
        }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
	int t;
	cin >> t;
    return 0;
}
