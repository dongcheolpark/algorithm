
#include <vector>
#include "sort.hpp"

vector<int *> * merge_sort::run() {
	vector<int *> * result = new vector<int *>;
	result->push_back(copy());
	divide_merge_sort(0,size-1,result);
	return result;
}

void merge_sort::divide_merge_sort(int left,int right,vector<int*> * result) {
	if(left == right) return;
	int mid = (left+right)/2;

	divide_merge_sort(left,mid,result);
	divide_merge_sort(mid+1,right,result);
	merge(left,mid,right,result);
}

void merge_sort::merge(int left,int mid, int right, vector<int*> * result) {
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