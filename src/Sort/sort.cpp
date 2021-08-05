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

void Sort::suffle() {
	random_device rd;

	mt19937 gen(rd());

	uniform_int_distribution<int> dis(0, size-1);

	for(int i = 0;i<size;i++) {
		int randNum = dis(gen);

		swap(data[i],data[randNum]);
	}
}

int * Sort::copy() {
	int * res = new int[size];
	for(int i = 0;i<size;i++) {
		res[i] = data[i];
	}
	return res;
}

vector<int *> * Sort::run(int x) {
	vector<int*> * (Sort::*func)() = NULL;

	switch (x) {
	case 1:
		func = &Sort::bubble_sort;
		break;
	case 2:
		func = &Sort::insert_sort;
		break;
	case 3:
		func = &Sort::selection_sort;
		break;
	default:
		func = &Sort::bubble_sort;
		break;
	}

	return (this->*func)();
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

vector<int *> * Sort::selection_sort() {
	vector<int *> * result = new vector<int *>;
	result->push_back(copy());

	for(int i = 0;i<size-1;i++) {
		int least = i;
		for(int j = i+1; j<size;j++) {
			if(data[j]<data[least]) {
				least = j;
			}
		}
		if(least != i) {
			swap(data[i],data[least]);
			result->push_back(copy());
		}
	}
	return result;
}

vector<int *> * Sort::merge_sort() {
	vector<int *> * result = new vector<int *>;
	result->push_back(copy());


	return result;
}

vector<int *> * Sort::quick_sort() {

}