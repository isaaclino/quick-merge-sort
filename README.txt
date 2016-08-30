/**
* Course: CS 14 Summer 2016
*
* First Name:      Isaac
* Last Name:       Lino
* Username:        ilino
* email address:   ilino001@ucr.edu
*
* Assignment:      assn4
* Filename :       README.txt
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/

This code compares all the different worst-case, average-case, best-case running times for Mergesort and Quicksort algorithms.
Quick sort has 5 diferent pivots which are first, random, median three, random qselect, or deterministic qsort.
Every pivot has its own test case from Quicksort.H
I included a sample txt files with strings, integers and words.

** Test was perform with .txt files with words from 1 to 7 characters.
** each file had 10, 100, 500, 1000, 2000 words (strings/integers)


Main reads reads an external file with arguments. To run the program after compilation:
<output.out> <file.ext>

The program has no warning/erros (not on bolt server at least) when is compiled with flags -W -Wall -Werror

compile:
g++ -W -Wall -Werror *.cc

run:
./a.out word.txt