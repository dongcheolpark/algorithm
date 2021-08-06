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
	int * copy(int,int);

	//merge sort implements
	void merge(int,int,int,vector<int *> *);
	void divide_merge_sort(int,int,vector<int *> *);

public:

	Sort(int n) {
		data = new int[n];
		size = n;
		for(int i = 0;i<n;i++) {
			data[i] = i+1;
		}
	}
	~Sort() {
		delete data;
	}
	void suffle(); 
	//O(n^2) Sort
	vector<int *> * run(int);
	vector<int *> * bubble_sort();
	vector<int *> * insert_sort();
	vector<int *> * selection_sort();
	//O(nlogn) Sort
	vector<int *> * merge_sort();
	vector<int *> * quick_sort();
};

#endif