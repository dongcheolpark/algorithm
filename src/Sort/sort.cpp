#include <iostream>
#include <random>
#include <vector>
#include "sort.hpp"

using namespace std;

void Sort::swap(int& a,int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void Sort::suffle(int t) {
	random_device rd;

	mt19937 gen(rd());

	uniform_int_distribution<int> dis(0, size-1);

	for(int i = 0;i<t;i++) {
		int randNum1 = dis(gen);
		int randNum2 = dis(gen);

		swap(data[randNum1],data[randNum2]);
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
	result->push_back(copy());

	for(int i = 0;i<size;i++) {
		for(int j = i;j<size;j++) {
			if(data[i]>data[j]) {
				swap(data[i],data[j]);
				result->push_back(copy());
			}
		}
	}
	return result;
}

vector<int *> * Sort::insert_sort() {
	vector<int *> * result = new vector<int *>;
	result->push_back(copy());
	int j = 0;

	for(int i = 1;i<size;i++) {
		int key = data[i];
		for(j = i-1;j>=0 && data[j]>key;j--) {
			data[j+1] = data[j];
			result->push_back(copy());
		}
		data[j+1] = key;
		result->push_back(copy());
	}
	return result;
}
