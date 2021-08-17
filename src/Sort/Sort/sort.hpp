#ifndef __SORT_H__
#define __SORT_H__

#include <vector>

using namespace std;

typedef vector<int*>* vec_int;

class Sort {
protected :
	int * data;
	int size;
	void swap(int&,int&);
	int * copy();
	int * copy(int,int);

	//merge sort implements
	void merge(int,int,int,vec_int);
	void divide_merge_sort(int,int,vec_int);

public:

	Sort(int n) {
		data = new int[n];
		size = n;
		for(int i = 0;i<n;i++) {
			data[i] = i+1;
		}
	}
	virtual ~Sort() {
		delete data;
	}
	void suffle(); 
	virtual vec_int run() {
		return new vector<int *>; 
	};
};

//O(n^2) Sort

class bubble_sort:public Sort { //bubble sort
public:
	bubble_sort(int n) : Sort(n) {}
	vec_int run();
};

class insert_sort:public Sort { //insert sort
public:
	insert_sort(int n) : Sort(n) {}
	vec_int run();
};

class selection_sort:public Sort {//selection sort
public:
	selection_sort(int n) : Sort(n) {}
	vec_int run();
};

//O(nlogn) Sort

class merge_sort:public Sort {//merge sort
private:
	void divide_merge_sort(int,int,vec_int);
	void merge(int,int,int,vec_int);
public:
	merge_sort(int n) : Sort(n) {}
	vec_int run();
};

class quick_sort:public Sort {//quick sort
private:
	void divide(int,int,vec_int);
public:
	quick_sort(int n) : Sort(n) {}
	vec_int run();
};

#endif