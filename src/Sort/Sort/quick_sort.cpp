#include <vector>
#include "sort.hpp"

vector<int *> * quick_sort::run() {
	vector<int *> * result = new vector<int *>;
	result->push_back(copy());
	divide(0,size-1,result);
	return result;
}

void quick_sort::divide(int left,int right, vector<int*>* result) {
	if(left>=right) return;
	int i = left+1,j=right;
	int key = left;

	while(i<=j) {
		while(i <= right && data[i] <= data[key]) i++;
		while(j > left && data[j] >= data[key]) j--;
		if(i > j) {
			swap(data[j],data[key]);
			result->push_back(copy());
		}
		else {
			swap(data[i],data[j]);
			result->push_back(copy());
		}
	}

	divide(left,j-1,result);
	divide(j+1,right,result);
}