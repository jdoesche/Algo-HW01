#include <iostream>
using namespace std;
#include <vector>
#include "Sorting.h"


const int MAX = 128;

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

    cout << "This is the Sorted Array via QuickSort:" << endl;
    printarray(sortarray4);
    cout << endl << endl;

    //Part 2

    //InsSort
    vector<int> sortarray5(inputarray.begin(),inputarray.end());
    InsSort(sortarray5);

    cout << "This is the Sorted Array via InsSort:" << endl;
    printarray(sortarray5);
    cout << endl << endl;   

    //BubbleSortA
    vector<int> sortarray6(inputarray.begin(),inputarray.end());
    BubbleSortA(sortarray6);

    cout << "This is the Sorted Array via BubbleSortA (With no Swap Detection):" << endl;
    printarray(sortarray6);
    cout << endl << endl;

    //BubbleSortB
    vector<int> sortarray7(inputarray.begin(),inputarray.end());
    BubbleSortB(sortarray7);

    cout << "This is the Sorted Array via BubbleSortB (Start -> End w/ Swap Detection):" << endl;
    printarray(sortarray7);
    cout << endl << endl;

    //BubbleSortC
    vector<int> sortarray8(inputarray.begin(),inputarray.end());
    BubbleSortC(sortarray8);

    cout << "This is the Sorted Array via BubbleSortC (End -> Start w/ Swap Detection):" << endl;
    printarray(sortarray8);
    cout << endl << endl;

    //CountingSort
    vector<int> sortarray9(inputarray.begin(),inputarray.end());
    CountingSort(sortarray9);

    cout << "This is the Sorted Array via CountingSort:" << endl;
    printarray(sortarray9);
    cout << endl << endl;

    //RadixSort
    vector<int> sortarray10(inputarray.begin(),inputarray.end());
    RadixSort(sortarray10);

    cout << "This is the Sorted Array via RadixSort:" << endl;
    printarray(sortarray10);
    cout << endl << endl;

    return 0;
}