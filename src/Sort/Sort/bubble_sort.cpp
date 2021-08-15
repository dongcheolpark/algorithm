#include <vector>
#include "sort.hpp"

vec_int bubble_sort::run() {
	vec_int result = new vector<int *>;
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