/**
 * @file sort_test.cpp
 * @author Bob Lowe < rlowe8@utm.edu >
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include "sort_test.h"

using namespace std;

////////////////////////////
// Static Helpers
////////////////////////////
static default_random_engine gen(0xDEADBEEF);
const int RUN_COUNT=10;

/**
 * @brief Return true if the vector is sorted.
 * 
 * @param v The vector
 */
static bool isSorted(const vector<int> &v) 
{
    for(auto itr = v.begin(); itr < v.end()-1; itr++) {
        if(*itr > *(itr+1)) {
            return false;
        }
    }

    return true;
}


/**
 * @brief insert n random numbers between 0 and 10,000 into v
 * 
 * @param v The vector
 * @param n The number to insert
 */
static void insertRandom(vector<int> &v, int n)
{
    uniform_int_distribution<> distr(0, 10000);

    for(int i=0; i<n; i++) {
        v.push_back(distr(gen));
    }
}


/**
 * @brief Run the sort test and print the results.
 * 
 * @param label The label to display.
 * @param v     The vector to test with.
 * @param sorter The sort function we are testing.
 */
static void runTest(const string &label, const vector<int> &v, SortTest::SortFunction sorter) 
{
    unsigned long long ns=0;
    typedef chrono::high_resolution_clock Clock;
    vector<int> vtest;

    // Start the test
    cout << "  " << label << ": ";
    cout.flush();

    // run the test RUN_COUNT times and compute the average
    for(int i=0; i<RUN_COUNT; i++) {
        // copy the vector
        vtest = v;

        // time the run
        auto t1 = Clock::now();
        sorter(vtest);
        auto t2 = Clock::now();

        // compute average duration
        ns += chrono::nanoseconds(t2-t1).count() / RUN_COUNT;
    }

    cout << (isSorted(vtest) ? "PASSED" : "FAILED") 
         << " Average Time: " << ns << " ns" << endl;
}


/**
 * @brief Generate an almost sorted array.
 * 
 * An almost sorted array has at most 10% of elements out of order.
 * @param v The vector to almostify
 */
static void almost(vector<int> &v) 
{
    int n = max(1, (int) v.size()/10);
    uniform_int_distribution<> distr(0, v.size()-1);

    // swap n random pairs
    for(int i=0; i<n; i++) {
        auto a = v.begin() + distr(gen);
        auto b = v.begin() + distr(gen);
        swap(*a,*b);
    }
}


////////////////////////////
// Class implementation
////////////////////////////
// construct a new SortTest object.
SortTest::SortTest(unsigned int n) 
{
    // generate the random array
    insertRandom(vrand, n);

    // generate the sorted array
    vsorted = vrand;
    sort(vsorted.begin(), vsorted.end());

    // generate the reverse array
    vreverse = vsorted;
    reverse(vreverse.begin(), vreverse.end());

    // generate the almost sorted array
    valmost = vsorted;
    almost(valmost);
}

// Run the sort test and display the results
void SortTest::run(const std::string &name, SortTest::SortFunction sorter)
{
    cout << name << endl;
    runTest("Random", vrand, sorter);
    runTest("Sorted", vsorted, sorter);
    runTest("Reversed", vreverse, sorter);
    runTest("Almost Sorted", valmost, sorter);
}