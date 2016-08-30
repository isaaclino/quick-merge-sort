/**
 * First Name:      Isaac
 * Last Name:       Lino
 *
 * Filename :       main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there
 * code from any outside resources such as another individual,
 * a website, or publishings. 
 *
 * All rights reserved by Isaac Lino
 * If you want to use this file, you have to give me credit for it!
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "Quicksort.H"
#include "Mergesort.H"

using namespace std;

int main(int argc, const char * argv[]) {
   
    // definition of pivots
    string first = "first";
    string random = "random";
    string median_three = "median_three";
    string random_qselect = "random_qselect";
    string deterministic_qsort = "deterministic_qsort";
    
    // create vector arrays to test different sorts
    vector<string> v;
    vector<string> v_first;
    vector<string> v_random;
    vector<string> v_median_three;
    vector<string> v_random_qselect;
    vector<string> v_deterministic_qsort;
    string words;
    
    if (argc != 2){
        std::cout<<"\n\n To open a file use: "<< argv[0] <<" <filename.ext>\n\n";
        return 0;
    }
    else{
        //filename to open
        ifstream file (argv[1]);
        
        if (!file.is_open() ){
            // check if file is open
            cout<<"\nCould not open file\n";
            cout<<"\n\nuse: "<< argv[0] <<" <dictionary.ext>\n";
            return 0;
        }
        else{
            // it reads the file and store it in a vectory array
            while(file >> words){
                
                v.push_back(words);
                v_first.push_back(words);
                v_random.push_back(words);
                v_median_three.push_back(words);
                v_random_qselect.push_back(words);
                v_deterministic_qsort.push_back(words);
            }
        }
        file.close();                   //close file
    }
    
    cout << "\n\n\t********** QUICKSORT TEST **********\n";
    cout << "\nUNSORTED:";
    print(v);
    
    quicksort(v_first, first);          // sends vector to quicksort algorithm w/first pivot
    //print(v_first);                     // prints out the sorted verctor
    
    quicksort(v_random, random);        // sends vector to quicksort algorithm w/random pivot
    //print(v_random);                    // prints out the sorted verctor
    
    quicksort(v_median_three, median_three);    // sends vector to quicksort algorithm w/median 3 pivot
    //print(v_median_three);                      // prints out the sorted verctor
    
    quicksort(v_random_qselect, random_qselect);    // sends vector to quicksort algorithm w/random quick select
    //print(v_random_qselect);                        // prints out the sorted verctor
    
    quicksort(v_deterministic_qsort, deterministic_qsort);      // sends vector to quicksort algorithm w/deterministic pivot
    print(v_deterministic_qsort);                               // prints out the sorted verctor
    
    
    cout << "\n\n\t********** MERGESORT TEST **********\n";
    cout << "\nUNSORTED:";
    print(v);           // prints unsorted vector
    mergesort(v);       // sends vector to mergesort algorithm
    print(v);           // prints out the sorted verctor
    
    //vector<string> result = mergesort(v);
    
     return 0;
}


