#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "./Sort/sort.hpp"

using namespace std;

/*
	argv[1] : size
	argv[2] : sort type

	1. bubble sort
	2. insert sort
	3. selection sort
	4. merge sort
	5. quick sort

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
	Sort * sort = NULL;

	switch (stoi(argv[2]))
	{
	case 1:
		sort = new bubble_sort(size);
		break;
	case 2:
		sort = new insert_sort(size);
		break;
	case 3:
		sort = new selection_sort(size);
		break;
	case 4:
		sort = new merge_sort(size);
		break;
	case 5:
		sort = new quick_sort(size);
		break;
	default:
		sort = new bubble_sort(size);
		break;
	}

	sort->suffle();

	print_json(sort->run(),size);

	delete sort;

	return 0;
}