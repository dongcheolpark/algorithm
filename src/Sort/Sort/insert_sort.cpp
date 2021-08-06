#include <vector>
#include "sort.hpp"

vector<int *> * insert_sort::run() {
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