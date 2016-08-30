/**
 * Course: CS 14 Summer 2016
 *
 * First Name:      Isaac
 * Last Name:       Lino
 * Username:        ilino
 * email address:   ilino001@ucr.edu
 *
 * Assignment:      assn4
 * Filename :       Mergesort.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>

//global variable for counting
long long merge_data_calls =0;
long long merge_data_movement =0;
long long merge_data_compare=0;

using namespace std;


// ---------------------------------------------------------------------------- //
template<typename T>
void merge(std::vector<T>& v, unsigned int low, unsigned int mid, unsigned int high)
{
    
    unsigned int mergedSize = high - low + 1;       // Size of merged partition
    unsigned int mergePos = 0;                      // Position to insert merged number
    unsigned int left = 0;                          // Position of elements in left partition
    unsigned int right = 0;                         // Position of elements in right partition
    
    
    vector<T> temp;  // create a temp vector array to hold values
    
    // for merged numbers
    left = low;                               // Initialize left partition position
    right = mid + 1;                          // Initialize right partition position
    
    // Add smallest element from left or right partition to merged numbers
    while (left <= mid && right <= high)
    {
        if (v[left] < v[right])
        {
            // store v vector to temp vector starting from left position
            temp.push_back(v[left]);
            merge_data_compare++;
            
            ++left;
            
        }
        else
        {
            // store v vector to temp vector starting from right position
            temp.push_back(v[right]);
            merge_data_compare++;
            
            ++right;
        
        }
        ++mergePos;
        merge_data_movement++;
    }
    
    // If left partition is not empty, add remaining elements to merged numbers
    while (left <= mid)
    {
        temp.push_back(v[left]);
        merge_data_compare++;
        
        ++left;
        ++mergePos;
        merge_data_movement++;
    }
    
    // If right partition is not empty, add remaining elements to merged numbers
    while (right <= high)
    {
        temp.push_back(v[right]);
        merge_data_compare++;
        
        ++right;
        ++mergePos;
        merge_data_movement++;
    }
    
    // Copy merge number back to numbers
    for (mergePos = 0; mergePos < mergedSize; ++mergePos)
    {
        v[low + mergePos] = temp[mergePos];
        merge_data_compare++;
    }
    
   
    
}
// ---------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------- //
template<typename T>
void sort(std::vector<T>& v, unsigned int low, unsigned int high)
{
    
    
    if (low < high)
    {
        // Find the midpoint in the partition
        int mid = (low + high) / 2;
        
        // Recursively sort left and right partitions
        sort(v, low, mid);
        sort(v, mid + 1, high);
        
        // Merge left and right partition in sorted order
        merge(v, low, mid, high);
        
    }
    merge_data_calls++;
    
}
// ---------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------- //
template<typename T>
void mergesort(std::vector<T>& v)
{
    cout << "\nCalling MERGESORT...\n";
    
    unsigned long numberElements = v.size ();
    if (numberElements > 1)
    {
        sort(v, 0, numberElements);
    }
    
    clock_t time = clock();
    cout << "MERGESORT number of elements in vector: " << numberElements << endl;
    cout << "MERGESORT number of recursive calls: " << merge_data_calls << endl;
    cout << "MERGESORT number of data movements: " << merge_data_movement << endl;
    cout << "MERGESORT number of times data is compared: " << merge_data_compare << endl;
    cout << "Execution time: " << (double)(clock()-time)/CLOCKS_PER_SEC << " seconds" << endl;
    cout << "\nSORTED: ";
    
}
// ---------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------- //
template <class T>
void print_mergesort(vector<T> & v)
{
    unsigned long NUMBERS_SIZE = v.size ();
    
    cout << endl;
    for(unsigned long i = 0; i < NUMBERS_SIZE; ++i)
    {
        cout << v[i] << " ";
    }
    cout <<endl;
}
