/**
 * Course: CS 14 Summer 2016
 *
 * First Name:      Isaac
 * Last Name:       Lino
 * Username:        ilino
 * email address:   ilino001@ucr.edu
 *
 * Assignment:      assn4
 * Filename :       Quicksort.H
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
long long first_data_calls =0;
long long first_data_movement =0;
long long first_data_compare=0;

long long random_data_calls =0;
long long random_data_movement =0;
long long random_data_compare=0;

long long median3_data_calls =0;
long long median3_data_movement =0;
long long median3_data_compare=0;

long long randomq_data_calls =0;
long long randomq_data_movement =0;
long long randomq_data_compare=0;

long long deterministic_data_calls =0;
long long deterministic_data_movement =0;
long long deterministic_data_compare=0;

using namespace std;

// ---------------------------------------------------------------------------- //
template <class T>
unsigned int pivot_first(std::vector<T> & v, unsigned int low, unsigned int high)
{
    first_data_calls++;
    
    unsigned int left = low;
    unsigned int right = high - 1;
    unsigned int size = high - low;
    
    if (size > 1)
    {
        
        // set pivot to first element this case is set low=left
        T pivot = v[low+1];
      
        while (left < right)
        {
            while (v[right] > pivot && right > left)
            {
                right--;
                first_data_movement++;
            }
            
            while (v[left] < pivot && left <= right)
            {
                left++;
                first_data_movement++;
            }
            
            if (left < right)
            {
                std::swap(v[left], v[right]);
                first_data_compare++;
                left++;
            }
        }
        pivot_first(v, low, left);
        pivot_first(v, right, high);
    }
   return right;
}
// ---------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------- //
template <class T>
unsigned int pivot_random(std::vector<T> & v, unsigned int low, unsigned int high)
{
    
     random_data_calls++;
    
    unsigned int left = low;
    unsigned int right = high - 1;
    unsigned int size = high - low;
    
    if (size > 1)
    {
        T pivot = v[rand() % size + left];
        
        while (left < right)
        {
            while (v[right] > pivot && right > left)
            {
                right--;
                random_data_movement++;
            }
            
            while (v[left] < pivot && left <= right)
            {
                left++;
                random_data_movement++;
            }
            
            if (left < right)
            {
                std::swap(v[left], v[right]);
                random_data_compare++;
                left++;
            }
        }
        
        pivot_random(v, low, left);
        pivot_random(v, right, high);
    }

    return right;

}
// ---------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------- //
template <class T>
unsigned int pivot_median_of_three(std::vector<T> & v, unsigned int low, unsigned int high)
{
    median3_data_calls++;
 
    unsigned int left = low;
    unsigned int right = high - 1;
    unsigned int size = high - low;
    unsigned int middle =((right + left)/2);
    
    
    if (size > 1)
    {
        
        if ( v[left] > v[middle] )
        {
            std::swap( v[left], v[middle] );
            median3_data_compare++;
            
        }
        if ( v[left] > v[right] )
        {
            std::swap( v[left], v[right] );
            median3_data_compare++;
        }
        if ( v[middle] > v[right] )
        {
            std::swap( v[middle], v[right] );
            median3_data_compare++;
        }
        
        std::swap(v[middle], v[right]);
        median3_data_compare++;
      
     
        T pivot = v[middle];
        
        while (left < right)
        {
            while (v[right] > pivot && right > left)
            {
                right--;
                median3_data_movement++;
            }
            
            while (v[left] < pivot && left <= right)
            {
                left++;
                median3_data_movement++;
            }
            
            if (left < right)
            {
                std::swap(v[left], v[right]);
                median3_data_compare++;
                left++;
            }
        }
        
        std::swap(v[left], v[right-1]);
        median3_data_compare++;
     
    }
    
    return right;
}
// ---------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------- //
template <class T>
unsigned int pivot_random_quick_select(std::vector<T> & v, unsigned int start, unsigned int stop, unsigned int position)
{
    
    randomq_data_calls++;
    
    // swap pivot into starting position
    std::swap (v[start], v[position]);
    randomq_data_compare++;
    
    // partition values
    unsigned int low = start + 1;
    unsigned int high = stop;
    
    
    while (low < high)
    {
        if (v[low] < v[start])
        {
            low++;
        }
        else if (v[--high] < v[start])
        {
            std::swap(v[low], v[high]);
            randomq_data_compare++;
        }
        randomq_data_movement++;
        
    }
    // then swap pivot back into place
    std::swap (v[start], v[--low]);
    randomq_data_compare++;
    
    return low;
}
// ---------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------- //
template <class T>
unsigned int pivot_deterministic_quick_select(std::vector<T> & v, unsigned int low, unsigned int high, unsigned int position)
{
    deterministic_data_calls++;
    
    unsigned int left = low;
    unsigned int right = high - 1;
    unsigned int size = high - low;

    
    if (size > 1)
    {
       // set pivot to a deterministic point
       T pivot = v[left + rand() % (right - left + 1)];
        
        while (left < right)
        {
            while (v[right] > pivot && right > left)
            {
                right--;
                deterministic_data_movement++;
            }
            
            while (v[left] < pivot && left <= right)
            {
                left++;
                deterministic_data_movement++;
            }
            
            if (left < right)
            {
                std::swap(v[left], v[right]);
                deterministic_data_compare++;
                left++;
            }

        
        }
        
        pivot_deterministic_quick_select(v, low, left, position);
        pivot_deterministic_quick_select(v, right, high, position);
    }
    
    return right;
}
// ---------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------- //
template <class T>
void quickSort(vector<T> & v, unsigned int low, unsigned int high, string pivot)
{
    // no need to sort a vector of zero or one elements
    if (low >= high)
        return;
    
    // select the pivot value
    unsigned int pivotIndex = (low + high) / 2;
    
    if (pivot == "first")
    {
        // FIRST 1.1
        pivotIndex = pivot_first(v, low, high);
        
    }
    else if( pivot == "random")
    {
        // RANDOM 1.2
        pivotIndex = pivot_random(v, low, high);
        
    }
    else if( pivot == "median_three")
    {
        // MEDIAN 1.3
        pivotIndex = pivot_median_of_three(v, low, high);
        median3_data_calls++;
    }
    else if( pivot == "random_qselect")
    {
        // SELECTION 1.4.1
        pivotIndex = pivot_random_quick_select(v, low, high, pivotIndex);
        randomq_data_calls++;
    }
    else if ( pivot == "deterministic_qsort")
    {
        // SELECTION 1.4.2
        pivotIndex = pivot_deterministic_quick_select(v, low, high, pivotIndex);
        deterministic_data_calls++;
    }
    else
    {
        return;
    }

    
    // sort the two sub vectors
    if (low < pivotIndex)
    {
        quickSort(v, low, pivotIndex, pivot);
    }
    if (pivotIndex < high)
    {
        quickSort(v, pivotIndex + 1, high, pivot);
    }

}
// ---------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------- //
template <class T>
void quicksort(vector<T> & v, T pivot)
{
     cout << "\nCalling QUICKSORT...\n";
     unsigned long numberElements = v.size ();
    
    // call quicksort and pass the proper pivot
    if (numberElements > 1)
    {
        quickSort(v, 0, numberElements, pivot);
    }

    // create a stats for evey recursive call, data movement and times data is compared
    clock_t time = clock();
    if (pivot == "first")
    {
        cout << "\n1.1 FIRST pivot has been selected\n";
        cout << "Number of elements in vector: " << numberElements << endl;
        cout << "Number of recursive calls: " << first_data_calls << endl;
        cout << "Number of data movements: " << first_data_movement << endl;
        cout << "Number of times data is compared: " << first_data_compare << endl;
        cout << "Execution time: " << (double)(clock()-time)/CLOCKS_PER_SEC << " seconds" << endl;
        cout << "\nSORTED: ";
    }
    else if (pivot == "random")
    {
        cout << "\n1.2 RANDOM pivot has been selected\n";
        cout << "Number of elements in vector: " << numberElements << endl;
        cout << "Number of recursive calls: " << random_data_calls << endl;
        cout << "Number of data movements: " << random_data_movement << endl;
        cout << "Number of times data is compared: " << random_data_compare << endl;
        cout << "Execution time: " << (double)(clock()-time)/CLOCKS_PER_SEC << " seconds" << endl;
        cout << "\nSORTED: ";
    }
    else if(pivot == "median_three")
    {
        cout << "\n1.3 MEDIAN OF THREE pivot has been selected\n";
        cout << "Number of elements in vector: " << numberElements << endl;
        cout << "Number of recursive calls: " << median3_data_calls << endl;
        cout << "Number of data movements: " << median3_data_movement << endl;
        cout << "Number of times data is compared: " << median3_data_compare << endl;
        cout << "Execution time: " << (double)(clock()-time)/CLOCKS_PER_SEC << " seconds" << endl;
        cout << "\nSORTED: ";
    }
    else if( pivot == "random_qselect")
    {
        cout << "\n1.4.1 SELECTION (random quick select) pivot has been selected\n";
        cout << "Number of elements in vector: " << numberElements << endl;
        cout << "Number of recursive calls: " << randomq_data_calls << endl;
        cout << "Number of data movements: " << randomq_data_movement << endl;
        cout << "Number of times data is compared: " << randomq_data_compare << endl;
        cout << "Execution time: " << (double)(clock()-time)/CLOCKS_PER_SEC << " seconds" << endl;
        cout << "\nSORTED: ";
    }
            
 
    else if( pivot == "deterministic_qsort")
    {
        cout << "\n1.4.2 SELECTION (deterministic quick select) pivot has been selected\n";
        cout << "Number of elements in vector: " << numberElements << endl;
        cout << "Number of recursive calls: " << deterministic_data_calls << endl;
        cout << "Number of data movements: " << deterministic_data_movement << endl;
        cout << "Number of times data is compared: " << deterministic_data_compare << endl;
        cout << "Execution time: " << (double)(clock()-time)/CLOCKS_PER_SEC << " seconds" << endl;
        cout << "\nSORTED: ";
    }
    else
    {
        cout << "\n NO proper pivot has been selected \n";
    }
}
// ---------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------- //
template <class T>
void print(vector<T> & v)
{
unsigned long NUMBERS_SIZE = v.size ();

    cout << endl;
    for(unsigned long i = 0; i < NUMBERS_SIZE; ++i)
    {
        
        cout << v[i] << " ";
    }
    cout <<endl;
}