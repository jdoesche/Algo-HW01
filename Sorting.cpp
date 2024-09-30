#include <iostream>
using namespace std;
#include <vector>
#include "Sorting.h"
#include <string>

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
    int min;

    while (i < n) {
        min = aleph;
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
        min = aleph;
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

    //easy-out
    if (right - left <= 2) {
        if (Varray[left] > Varray[right])
            swap(Varray[left], Varray[right]);
        return;
    }

    //Create two temporary sub-arrays
    int i = 0;
    int len1 = divisor - left + 1;
    int len2 = right - divisor;

    int larr[len1];
    int rarr[len2];

    while (i < len1) {
        larr[i] = Varray[left + i];
        i++;
    }
    i = 0;
    while (i < len2) {
        rarr[i] = Varray[divisor + i + 1];
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
            Varray[k] = rarr[j];
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
        Varray[k] = rarr[j];
        j++;
        k++;
    }

    return;
}

void MS_Divide(vector<int>& Varray, int left, int right) {
    /*This function is a recursive function that sections the array off*/
    if (left >= right)
        return;

    int divisor = left + ((right - left) / 2);

    MS_Divide(Varray, left, divisor);
    MS_Divide(Varray, divisor + 1, right);

    MS_Conquer(Varray, left, divisor, right);
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
    https://www.digitalocean.com/community/tutorials/merge-sort-algorithm-java-c-python */
}

int QS_Particion (vector<int>& Varray, int left, int right) {
    /*This function particions the Array such that all left are correct*/

    //Select a pivot. Midpoint and Right-/Left-Most are ways to do so, but Randomly is 
    //  preferable
    int pivot = Varray[right];
    int i = left;
    int j = left;

    while (j < right) {
        if (Varray[j] <= pivot) {
            swap(Varray[i], Varray[j]);
            i++;
        }
        j++;
    }

    swap(Varray[i], Varray[right]);


    return i;
}

void QS_Pivot (vector<int>& Varray, int left, int right) {
    /*The recursive pivot function*/
    if (left < right) {
        int pivot = QS_Particion(Varray, left, right);
        if (pivot > left) {
            QS_Pivot(Varray, left, pivot - 1);
        }
        if (pivot < right) {
            QS_Pivot(Varray, pivot + 1, right);
        }
    }
    return;
}

void QuickSort(vector<int>& Varray) {
    /*This function uses a pivot, and rorganizes */
    int right = Varray.size() - 1;

    QS_Pivot(Varray, 0, right);
    return;
    /*I had some nice help from another website, as follows:
    https://www.programiz.com/dsa/quick-sort */
}

int power(int base, int exponent) {
    if (exponent < 0) // Not designed for inverse functionality ):
        return 0;

    if (exponent == 0)
        return 1;

    return num * power(base, exponent - 1);
}

void swapstring(string a, string b) {
    string t = a;
    a = b;
    b = t;
    return;
}

string RS_ToBinary(int num) {
    /*Converts a given int to a Binary String*/
    int i = aleph_bit;
    string base;
    while (i > -1) {
        int compnum = power(2, i);
        compnum = num % compnum;

        if (compnum == 0)
            base += "0";
        else
            base += "1";

        i--;
    }

    return base;
}

int RS_FromBinary(string num) {
    /*Converts a given Binary String to an int*/
    int i = aleph_bit;
    int j = 0;
    int base = 0;
    while (i > -1) {
        if (num[j] == "0")
            base += power(2, i)
    
        j++;
        i--;
    }

    return base;
}

void RadixSort(vector<int>& Varray) {
    /*This function sorts it by ordering least significant to most significant*/
    vector<string> BinVarray;
    int i = 0;
    while i < len(Varray) {
        BinVarray[i] = RS_ToBinary(Varray[i])
        i++;
    }
}