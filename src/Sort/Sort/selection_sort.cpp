#include <vector>
#include "sort.hpp"

vec_int selection_sort::run() {
	vec_int result = new vector<int *>;
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