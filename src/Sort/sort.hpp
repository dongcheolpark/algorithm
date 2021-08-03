#ifndef __SORT_H__
#define __SORT_H__
#include <vector>

using namespace std;

class Sort {
private:

	int * data;
	int size;
	void swap(int&,int&);
	int * copy();

public:

	Sort(int n) {
		data = new int[n];
		size = n;
		for(int i = 1;i<n;i++) {
			data[i] = i;
		}
	}
	~Sort() {
		delete data;
	}
	void suffle(int); 
	vector<int *> * bubble_sort();
	vector<int *> * insert_sort();

};

#endif