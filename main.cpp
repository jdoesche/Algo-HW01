#include <iostream>
using namespace std;
#include <vector>
#include "sorting.h"


const int MAX = 100

void printarray(vector<int> vect) {
    //Function to print the vector, in a 10x10 grid
    int i = 0;
    int j = 0;

    while (i < 10) {
        j = 0;
        while (j < 10) {
            cout << vect[i * 10 + j] << ", "
            j++;
        }
        cout << endl;
        i++;
    }
}

int main() {
    //Produce a vector
    vector<int> inputarray;
    int i = 0;
    int maxval = 32767
    while (i < MAX) {
        int a = rand() % maxval + 1;
        inputarray.push_back(a);
        i++;
    }

    vector<int> sortarray1(inputarray.begin(),inputarray.end())
    MergeSort (sortarray1)

    




    return 0;
}