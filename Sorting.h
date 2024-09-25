#ifndef SORTING_H
#define SORTING_H

#include <iostream>
using namespace std;
#include <vector>


void swap(int &val1, int &val2);

void SelSortA(vector<int>& Varray);
void SelSortB(vector<int>& Varray);
void MergeSort(vector<int>& Varray);
void QuickSort(vector<int>& Varray);

const int infinity = 2147483647;

#endif //SORTING_H