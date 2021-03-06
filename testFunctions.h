#ifndef TESTFUNCTIONS_H
#define TESTFUNCTIONS_H

#include <iostream>
#include <String>
#include <ctime>
#include <stdlib.h>
#include <utility>
#include <vector>
#include "iblt.h"
#include "murmurhash3.h"
#include "utilstrencodings.h"
using namespace std;

//template function to convert value into vector of bits
//necessary for insert()
//input: number = numeric value to be converted
//output: vector of bytes of the value
template<typename T>
std::vector<uint8_t> ToVec(T number)
{
    std::vector<uint8_t> v(sizeof(T));
    for (size_t i = 0; i < sizeof(T); i++) {
        v.at(i) = (number >> i*8) & 0xff;
    }
    return v;
}

//creates an array of pointers to arrays of key value pairs (keys = unique)
//input numEntries = number of key-value pairs to be created
//input maxVal = the maximum value of keys/values generated
int** createValues(int numEntries, int maxVal);


//creates a multidimensional array of key value pairs
//keys are generated in increasing order from minval to minval+numEntries
//input numEntries = number of key-value pairs to be created
//input minVal = the minimum value of keys/values generated
int** createValues3(int numEntries, int minVal);

//creates an array of pointers to arrays of key value pairs (keys not necessarily unique)
//input numEntries = number of key-value pairs to be created
//input maxVal = the maximum value of keys/values generated
int** createValues5(int numEntries, int maxVal);

//inserts the entries generated by createValues() into the IBLT
//input: entries = array of arrays of key value pairs
//input: iblt = pointer to the iblt object
//input: numEntries = the number of key-value pairs being inserted into the iblt
void addEntries(int** entries, IBLT* iblt, int numEntries);

//compares the set made by the IBLT during list values to the key-value pairs generated by createValues()
//input: positiveValues = set of key value pairs generated by IBLT during list values operation
//input: myEntries = multidimensional array of key value pairs that were inserted into the iblt
//input: numEntries = the number of entries originally inserted into the iblt
void compare(std::set<std::pair<uint64_t,std::vector<uint8_t> > > positiveValues, int** myEntries, int numEntries);


//compares the set made by the IBLT during list values to the key-value pairs generated by createValues()
//input: positiveValues = set of key value pairs generated by IBLT during list values operation
//input: myEntries = multidimensional array of key value pairs that were inserted into the iblt
//input: numEntries = the number of entries originally inserted into the iblt
//output: returns true if all of the inserted key/value pairs were successfully listed out during list entries
bool compare2(std::set<std::pair<uint64_t,std::vector<uint8_t> > > positiveValues, int** myEntries, int numEntries);


//Generates a vector of keys that are unique to one of the sets
//input: aVals, bVals = multidimensional arrays of key value pairs
//input: numEntries = number of pairs in each multidimensional array
//output: vector = keys that are only found in one of the sets
vector<int*> makeDiffVector(int** aVals, int** bVals, int numEntries);

#endif
