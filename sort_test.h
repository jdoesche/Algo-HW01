/**
 * @file sort_test.h
 * @author Bob Lowe < rlowe8@utm.edu >
 * @brief Class definition for the SortTest lass.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef SORT_TEST_H
#define SORT_TEST_H
#include <vector>

class SortTest
{
public:
    /**
     * @brief Function signature for our pointers to sort functions
     * 
     */
    typedef void(*SortFunction)(std::vector<int>&);

    /**
     * @brief Construct a new Sort Test object
     * 
     * @param n The size of the vectors to test with.
     */
    SortTest(unsigned int n);

    /**
     * @brief Run the tests on the sortFunction.
     * 
     * This function runs the tests on the function and then prints the
     * results to cout.
     * 
     * @param sortFunction A function with signature void(std::vector<int>&)
     */
    void run(const std::string &name,  SortFunction sorter);

private:
    std::vector<int> vrand;
    std::vector<int> vsorted;
    std::vector<int> vreverse;
    std::vector<int> valmost;
};
#endif