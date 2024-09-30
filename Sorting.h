#ifndef SORTING_H
#define SORTING_H

#include <iostream>
using namespace std;
#include <vector>


void swap(int &val1, int &val2);
void MS_Divide(vector<int>& Varray, int left, int right);
void MS_Conquer(vector<int>& Varray, int left, int divisor, int right);
void QS_Pivot (vector<int>& Varray, int left, int right);
int  QS_Particion (vector<int>& Varray, int left, int right);

void SelSortA(vector<int>& Varray);
void SelSortB(vector<int>& Varray);
void MergeSort(vector<int>& Varray);
void QuickSort(vector<int>& Varray);

const int aleph = 2147483647;

#endif //SORTING_H