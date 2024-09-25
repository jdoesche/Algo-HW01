#ifndef SORTING_H
#define SORTING_H

#include <iostream>
using namespace std;
#include <vector>


class Sorters {
    private:
        const int infinity = 2147483647
        void swap(int &val1, int &val2)
    public:
        void SelSortA(vector<int>& Varray);
        void SelSortB(vector<int>& Varray);
        void MergeSort(vector<int>& Varray);
        void QuickSort(vector<int>& Varray);
}
#endif //SORTING_H