#include <iostream>
#include <time.h>
#include <vector>
#include "sort.hpp"

using namespace std;

void Sort::swap(int& a,int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void Sort::suffle(int t) {
	srand(time(NULL));	

	for(int i = 0;i<t;i++) {
		int randNum1 = rand() % size;
		int randNum2 = rand() % size;

		swap(data[randNum1],data[randNum1]);
	}
}

int * Sort::copy() {
	int * res = new int[size];
	for(int i = 0;i<size;i++) {
		res[i] = data[i];
	}
	return res;
}

vector<int *> * Sort::bubble_sort() {
	vector<int *> * result = new vector<int *>;

	for(int i = 0;i<size;i++) {
		for(int j = 0;j<size;j++) {
			if(data[i]<data[j]) {
				swap(data[i],data[j]);
				result->push_back(copy());
			}
		}
	}
	return result;
}
