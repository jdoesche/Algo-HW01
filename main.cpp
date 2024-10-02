#include <iostream>
using namespace std;
#include <vector>
#include "Sorting.h"
#include <algorithm>
#include <string>
#include "sort_test.h"
#include "builtin.h"

/*
//Testing Functions

void printarray(vector<int>& vect) {
    //Function to print the vector, in a Nx10 grid

    int lineamt = 16; //Change this value to display more or less per line

    int i = 0;
    int j = 0;
    int universal = 0;
    while (true) {
        j = 0;
        while (j < lineamt) {
            if (vect[i * lineamt + j] < 100) {
                if (vect[i * lineamt + j] < 10)
                    cout << " ";
                cout << " ";
            }
            cout << vect[i * lineamt + j];

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
    while (i < MAXVect) {
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
    */


/**
 * @file main.cpp
 * @author Bob Lowe < rlowe8@utm.edu >
 * @brief Test the sort algorithms using the number of elements specified on the command line.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2024
 * 
 */

int main(int argc, char **argv)
{
    // get the number to run.
    unsigned int n = 128;
    if(argc == 2) {
        n = stoi(argv[1]);
    }
    SortTest t{n};

    // Run the tests
    cout << "Array Size: " << n << endl;
    t.run("Built-In STL Sort", builtinSort);

    t.run("Selection Sort (A)", SelSortA);

    t.run("Selection Sort (B)", SelSortB);

    t.run("Merge Sort", MergeSort);

    t.run("Quick Sort", QuickSort);

    t.run("Insertion Sort", InsSort);

    t.run("Bubble Sort (A)", BubbleSortA);

    t.run("Bubble Sort (B)", BubbleSortB);

    t.run("Bubble Sort (C)", BubbleSortC);

    t.run("Counting Sort", CountingSort);

    t.run("Radix Sort", RadixSort);


    return 0;
}
