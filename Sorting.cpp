#include <iostream>
using namespace std;
#include <vector>
#include "Sorting.h"

void swap(int& val1, int& val2) {
    int holdval;
    holdval = val1;
    val1 = val2;
    val2 = holdval;
    return;
}

void SelSortA(vector<int>& Varray) {
    /*The goal of this function is to see if the next element is smaller then the current smallest element*/
    int i = 0;
    int n = Varray.size();
    int j = 0;

    while (i < n) {
        min = infinity;
        j = i;
        while (j < n) {
            if (Varray[j] < Varray[i]) {
                swap(Varray[i], Varray[j]);
            }

            j++;
        }

        i++;
    }
    return;
}

void SelSortB(vector<int>& Varray) {
    /*The goal of this function is to find the smallest element in the set, and move it to the first unsorted spot*/
    int i = 0;
    int n = Varray.size();
    int j = 0;
    int min;
    int mindex = 0;

    while (i < n) {
        min = infinity;
        j = i;
        while (j < n) {
            if (Varray[j] < min) {
                min = Varray[j];
                mindex = j;
            }

            j++;
        }
        swap(Varray[i], Varray[mindex]);
        i++;
    }
    return;
}

void MergeSort(vector<int>& Varray) {
    /*This function divides the array into many smaller arrays, then re-merges them*/


    return;
}

void QuickSort(vector<int>& Varray) {
    /*This function uses a pivot, and rorganizes */


    return;
}