#ifndef SORTING_H
#define SORTING_H

#include <iostream>
using namespace std;
#include <vector>


//Part 1

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
const int MAXVect = 128;

//Part 2

int power(int base, int exponent);
void MoveItMoveIt(vector<int>& Varray, int num_to, int num_from);
int ReturnNthValue(int input, int digit);
void RS_Helper(int innum, vector<int>& Varray, int i, int& k);

void InsSort(vector<int>& Varray);
void BubbleSortA(vector<int>& Varray);
void BubbleSortB(vector<int>& Varray);
void BubbleSortC(vector<int>& Varray);
void CountingSort(vector<int>& Varray);
void RadixSort(vector<int>& Varray);

const int aleph_bit = 31;

#endif //SORTING_H