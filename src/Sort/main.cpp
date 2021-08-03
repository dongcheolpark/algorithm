#include <iostream>
#include "sort.hpp"

/*
	argv[0] : size
	argv[1] : sort type

	1. bubble sort
	2. insert sort
*/


void print_json(vector<int *> * json,int size) {
	ofstream fout("out.json");

	fout << "{ \"data\" : [";
	for(auto item : *json) {
		fout<< "[";
		for(int i = 0;i<size;i++) {
			fout<<item;
			if(i!= size-1) {
				fout<<",";
			}
		}
		fout<< "]";
		if(item != json->back()) {
			fout<< ",";
		}
	}
	fout<<"]}"
}

int main(int argc, char *argv[]) {
	Sort sort;

	return 0;
}