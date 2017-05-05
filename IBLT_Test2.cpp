#include <iostream>
#include "iblt.h"
#include "murmurhash3.h"
#include "utilstrencodings.h"
#include "testFunctions.h"
#include <String>
#include <ctime>
#include <stdlib.h>
#include <utility>
#include <vector>
using namespace std;

/*
* Test to determine whether the list entries function for the iblt functions properly
* Continually changes how many entries will be inserted into the IBLT (from 1-50)
* Performs 1000 tests of listing entries for IBLTs with each specified number of entries
* States how many listing entry operations were successful out of 1000
* Used to generate the text files
*/

int main()
{
  int numEntries;

  int numSuccess;

  //checks functionality of listEntries for varying numbers of entries (1-50 entries)
  for (int j = 1; j <= 100; j++)
  {
    numEntries = j;

    numSuccess = 0;

    //performs list entries on different IBLTs 1,000 times
    //counts how many times the operation was completely successful
    for (int i = 0; i < 1000; i++)
    {
      //creates pointer to multidimensional array with key/value pairs
      //max value of 1000 for each entry
      int** myEntries = createValues(numEntries, 1000);

      //initializes IBLT object with number of entries and size of each entry
      IBLT* iblt = new IBLT(numEntries, sizeof(1000));


      //adds entries into the IBLT
      addEntries(myEntries, iblt, numEntries);

      //initializes sets of pairs to hold keys and values
      std::set<std::pair<uint64_t,std::vector<uint8_t> > > positiveValues;

      std::set<std::pair<uint64_t,std::vector<uint8_t> > > negativeValues;

      //lists entries into the sets
      bool successful = iblt->listEntries(positiveValues, negativeValues);

      //checks if listEntries was successful
      if (compare2(positiveValues, myEntries, numEntries))
      {
        numSuccess++;
      }

      //manages memory
      delete iblt;
      delete myEntries;
    }

    cout << "NumEntries = " << numEntries << ". Num Successes = " << numSuccess << endl;
  }
  return 0;

}
