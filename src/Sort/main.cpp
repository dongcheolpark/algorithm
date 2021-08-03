#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "sort.hpp"

using namespace std;

/*
	argv[0] : size
	argv[1] : sort type

	1. bubble sort
	2. insert sort
*/


void print_json(vector<int *> * json,int size) {
	ofstream fout;
	fout.open("out.json");

	fout << "{ \"data\" : [";
	for(auto item : *json) {
		fout<< "[";
		for(int i = 0;i<size;i++) {
			fout<<item[i];
			if(i!= size-1) {
				fout<<",";
			}
		}
		fout<< "]";
		if(item != json->back()) {
			fout<< ",";
		}
		delete item;
	}
	fout<<"]}";
	delete json;
}

int main(int argc, char *argv[]) {
	if(argc == 1) {
		cout<<"please input parameters";
		return -1;
	} 
	int size = stoi(argv[1]);
	Sort sort(size);
	sort.suffle(20);

	vector<int*> * (Sort::*func)() = NULL;

	switch (stoi(argv[2])) {
	case 1:
		func = &Sort::bubble_sort;
		break;
	case 2:
		func = &Sort::insert_sort;
		break;
	default:
		func = &Sort::bubble_sort;
		break;
	}
	print_json((sort.*func)(),size);
	return 0;
}