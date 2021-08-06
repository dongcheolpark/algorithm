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

int * Sort::copy(int s,int e) {
	int * res = new int[e-s+1];
	for(int i = s;i<=e;i++) {
		res[i-s] = data[i];
	}
	return res;
}




