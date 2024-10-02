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















//Part 2

int power(int base, int exponent) {
    if (exponent < 0) // Not designed for inverse functionality ):
        return 0;

    if (exponent == 0)
        return 1;

    return base * power(base, exponent - 1);
}

void MoveItMoveIt(vector<int>& Varray, int num_to, int num_from) {
    /*Move n to position x, shifting all variables between right*/
    if (num_to >= num_from)
        return;

    //cout << "Swapping " << Varray[num_from] << " (" << num_from << ") to " << num_to << endl;

    int i = num_from - 1;
    while (i >= num_to) {
        swap(Varray[i], Varray[i + 1]);
        i--;
    }
    return;
}

void InsSort(vector<int>& Varray) {
    //Individually sorting out each element into a sorted array
    
    int size = Varray.size();

    //Initial Pass
    if (size == 1)
        return;
    if (Varray[0] > Varray[1])
        swap(Varray[0], Varray[1]);

    //else
    if (size == 2)
        return;

    int pivot = 1;
    while (pivot < size) {
        //find location
        int i = 0;
        while (Varray[i] < Varray[pivot] && i < pivot) {
            i++;
        }
        MoveItMoveIt(Varray, i, pivot);
        pivot++;
    }

    return;
}

void BubbleSortA(vector<int>& Varray) {
    //Largest element "Bubbles" to the top
    int i = 0;
    int l = Varray.size();

    while (l > 1) {
        i = 0;

        while (i < l - 1) {
            if (Varray[i] > Varray[i + 1]) {
                swap(Varray[i],Varray[i + 1]);
            }
            i++;
        }
        l--;
    }
    return;
}


void BubbleSortB(vector<int>& Varray) {
    //Same as A, but will automatically return if it fails to swap
    int i = 0;
    int l = Varray.size();
    bool hasswapped;

    while (l > 1) {
        i = 0;
        hasswapped = false;

        while (i < l - 1) {
            if (Varray[i] > Varray[i + 1]) {
                swap(Varray[i],Varray[i + 1]);
                hasswapped = true;
            }
            i++;
        }
        if (hasswapped == false)
            return;
        
        l--;
    }
    return;
}


void BubbleSortC(vector<int>& Varray) {
    //Same as B, but in the reverse order
    int i = 0;
    int j = 0;
    int l = Varray.size();
    bool hasswapped;

    while (i < l) {
        j = 0;
        hasswapped = false;

        while (j < l - 1) {
            if (Varray[j] > Varray[j + 1]) {
                swap(Varray[j],Varray[j + 1]);
                hasswapped = true;
            }
            j++;
        }
        if (hasswapped == false)
            return;
        
        i++;
    }
    return;
}


void CountingSort(vector<int>& Varray) {
    //Count the number of each value in the array, then reconstruct it from those values
    int maxval = 10000;
    vector<int> Counts(maxval, 0);

    int i = 0;
    int l = Varray.size();
    while (i < l) {
        Counts[Varray[i]]++;
        i++;
    }

    i = 0;
    int j = 0;
    while (i < maxval) {
        while(Counts[i] > 0) {
            Varray[j] = i;
            Counts[i]--;
            j++;
        }
        i++;
    }

    return;
}

int ReturnNthValue(int input, int digit) {

    int holdval = (input / power(10, digit)) % 10;
    //cout << "The " << digit << "th Digit of " << input << " is " << holdval << endl;
    return holdval;
}

void RS_Helper(int innum, vector<int>& Varray, int i, int& k) {
    int j = k;
    int length = Varray.size();
    while (j < length) {
        if (ReturnNthValue(Varray[j], i) == innum) {
            MoveItMoveIt(Varray, k, j);
            k++;
        }
        j++;
    }
    return;
}

void RadixSort(vector<int>& Varray) {
    /*This function sorts it by ordering least significant to most significant*/
    int i = 0;
    int k;
    int l;
    while (i < 5) {
        l = 0;
        k = 0;
        while (l < 9) {
            RS_Helper(l, Varray, i, k);
            l++;
        }
        i++;
    }

    return;
}