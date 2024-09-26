#include <iostream>
using namespace std;
#include <vector>
#include "Sorting.h"


const int MAX = 128;

void printarray(vector<int>& vect) {
    //Function to print the vector, in a Nx10 grid
    int i = 0;
    int j = 0;
    int universal = 0;
    while (true) {
        j = 0;
        while (j < 10) {
            if (vect[i * 10 + j] < 100) {
                if (vect[i * 10 + j] < 10)
                    cout << " ";
                cout << " ";
            }
            cout << vect[i * 10 + j];
            
            j++;
            universal++;
            if (universal < MAX) {
                cout << ", ";
            }
            else {
                return;
            }
        }
        cout << endl;
        i++;
    }
}

int main() {
    //Produce a vector
    vector<int> inputarray;
    int i = 0;
    int maxval = 1000;
    while (i < MAX) {
        int a = rand() % maxval;
        inputarray.push_back(a);
        i++;
    }

    cout << "This is the input array:" << endl;
    printarray(inputarray);
    cout << endl << endl;

    //SelSortA
    vector<int> sortarray1(inputarray.begin(),inputarray.end());
    SelSortA(sortarray1);

    cout << "This is the Sorted Array via SelSortA (Swap during Loop):" << endl;
    printarray(sortarray1);
    cout << endl << endl;
    
    //SelSortB
    vector<int> sortarray2(inputarray.begin(),inputarray.end());
    SelSortB(sortarray2);

    cout << "This is the Sorted Array via SelSortB (Find min, then swap):" << endl;
    printarray(sortarray2);
    cout << endl << endl;

    //MergeSort
    vector<int> sortarray3(inputarray.begin(),inputarray.end());
    MergeSort(sortarray3);

    cout << "This is the Sorted Array via MergeSort:" << endl;
    printarray(sortarray3);
    cout << endl << endl;

    //Quicksort
    vector<int> sortarray4(inputarray.begin(),inputarray.end());
    QuickSort(sortarray4);

    cout << "This is the Sorted Array via Quicksort:" << endl;
    printarray(sortarray4);
    cout << endl << endl;

    return 0;
}