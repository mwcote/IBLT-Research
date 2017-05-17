# IBLT-Research

Description of Files:

Original Files From Gavin Andresen's Repository: https://github.com/gavinandresen/IBLT_Cplusplus
iblt.cpp - main implementation of the IBLT
iblt.h - accompanying header file for iblt.cpp
iblt_test.cpp - Andresen's testing program for his implementation
murmurhash3.cpp - C++ program containing the hash functions used for the IBLT
murmurhash3.h - accompanying header file to hash function file
utilstrencodings.cpp - C++ program with functions to convert hex string to IBLT-insertable vector of bytes
utilstrencodings.h - accompanying header file

Added Files:
iblt2.cpp - modified implementation of the IBLT based on Andresen's program
testFunctions.cpp - C++ file containing necessary helper functions to run test programs
testFunctions.h - accompanying header file
IBLT_Test1.cpp - Test program for list entries function of IBLT. Allows for continual user input of different expected numbers of entries in the IBLT
IBLT_Test2.cpp - Test program for list entries function. Runs 10000 tests of list entries for each expected number of entries between 1 and 100
IBLT_Test3.cpp - Test program for IBLT subtraction. Attempts to subtract two IBLTs and tests list entries of resulting IBLT
IBLT_Test4.cpp - Test program for other basic IBLT functions. Tests get, insert, and delete functions
IBLT_Test5.cpp - Test program for list entries when allowing for repeated keys. 
ListEntriesTest.txt - Text file containing results of IBLT_Test2.cpp run with the iblt when the multiplicative factor used to determine the number of cells to include was modified by small increments.
Test2Results.txt -  Text file containing results of IBLT_Test2.cpp on the original IBLT implementation
modifiedTestResults.txt - Text file containing the results of IBLT_Test2, 3, and 4 on the modified IBLT implementation
originalTestResults.txt -Text file containing the results of IBLT_Test3, and 4 on the original IBLT implementation

Compilation instructions:
In order to create an executable, the files iblt.cpp/iblt2.cpp, murmurhash3.cpp, utilstrencodings.cpp, testFunctions.cpp, and one of the test programs (ex: IBLT_Test1.cpp)
must all be compiled together.

This material is based upon work supported by the National Science Foundation under Grant No. CCF-1563753. Any opinions, findings, and conclusions or recommendations expressed in this material are those of the author(s) and do not necessarily reflect the views of the National Science Foundation
