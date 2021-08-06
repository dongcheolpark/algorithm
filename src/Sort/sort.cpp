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
	case 4:
		func = &Sort::merge_sort;
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
	divide_merge_sort(0,size-1,result);
	return result;
}

void Sort::divide_merge_sort(int left,int right,vector<int*> * result) {
	if(left == right) return;
	int mid = (left+right)/2;

	divide_merge_sort(left,mid,result);
	divide_merge_sort(mid+1,right,result);
	merge(left,mid,right,result);
}

void Sort::merge(int left,int mid, int right, vector<int*> * result) {
	int * arr = copy(left,right);
	int n = right-left;
	int left_ptr = 0,right_ptr = mid-left+1;
	for(int i = 0;i<=n;i++) {
		if(left_ptr > mid-left) {
			data[left+i] = arr[right_ptr];
			right_ptr++;
			result->push_back(copy());
			continue;
		}
		else if(right_ptr > right-left) {
			data[left+i] = arr[left_ptr];
			left_ptr++;
			result->push_back(copy());
			continue;
		}
		if(arr[left_ptr] > arr[right_ptr]) {
			data[left+i] = arr[right_ptr];
			result->push_back(copy());
			right_ptr++;
		}
		else if(arr[left_ptr] <= arr[right_ptr]) {
			data[left+i] = arr[left_ptr];
			result->push_back(copy());
			left_ptr++;
		}
	}
	delete arr;
}
