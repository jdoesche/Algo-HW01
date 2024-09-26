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

void MS_Conquer(vector<int>& Varray, int left, int divisor, int right) {
    /*This function is the merger function of Merge Sort */

    //Create two temporary sub-arrays
    int i = 0;
    int len1 = divisor;
    int len2 = right - divisor;

    int larr[len1];
    int rarr[len2];

    while (i < len1) {
        larr[i] = Varray[left + i]
        i++;
    }
    i = 0;
    while (i < len2) {
        rarr[i] = Varray[divisor + 1 + i]
        i++;
    }

    //Re-merge the Sub-arrays back int Varray
    i = 0;
    int j = 0;
    int k = left;

    while(i < len1 && j < len2) {
        if (larr[i] <= rarr[j]) {
            Varray[k] = larr[i];
            i++;
        }
        else {
            Varray[k] = rarr[j]
            j++;
        }
        k++;
    }

    //Add the stragglers
    while (i < len1) {
        Varray[k] = larr[i];
        i++;
        k++;
    }
    while (j < len2) {
        Varray[k] = rarr[j]
        j++;
        k++;
    }

    return;
}

void MS_Divide(vector<int>& Varray, int left, int right) {
    /*This function is a recursive function that sections the array off*/
    if (left < right) {
        int divisor = left + (right - 1) / 2;

        MS_Divide(Varray, left, divisor);
        MS_Divide(Varray, divisor + 1, right);

        MS_Conquer(Varray, left, divisor, right);
    }
    return;
}

void MergeSort(vector<int>& Varray) {
    /*This is the intializer function for the Sorter*/
    int left = 0;
    int right = Varray.size() - 1;

    MS_Divide(Varray, left, right);
    return;
    /*I had some serious help from the following website for both referencing as well as
    understanding MergeSort:
    https://www.digitalocean.com/community/tutorials/merge-sort-algorithm-java-c-python
    */
}

void QuickSort(vector<int>& Varray) {
    /*This function uses a pivot, and rorganizes */


    return;
}