cmake_minimum_required(VERSION 3.11)

project(
	Sort)

add_executable (program main.cpp ./Sort/sort.cpp ./Sort/bubble_sort.cpp ./Sort/insert_sort.cpp ./Sort/selection_sort.cpp ./Sort/merge_sort.cpp)

