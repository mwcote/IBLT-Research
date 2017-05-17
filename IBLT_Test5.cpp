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
A preliminary test to determine the success of the IBLT when entries with the same key value are inserted.
The create Values function was adapted to no longer ensure that unique keys are made for the different entries.
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

    //performs list entries 10,000 times for each value of list entries
    //counts how many times out of 10,000 iterations the operation was completely successful
    for (int i = 0; i < 1000; i++)
    {
      //creates pointer to array of pointers to arrays with key/value pairs
      //max value of 500 for each entry
      int** myEntries = createValues5(numEntries, 1000);

      //initializes IBLT object with number of entries and size of each entry
      IBLT* iblt = new IBLT(numEntries, sizeof(1000));


      //calls function to add entries into the IBLT
      addEntries(myEntries, iblt, numEntries);
      //initializes sets of pairs to hold keys and values
      std::set<std::pair<uint64_t,std::vector<uint8_t> > > positiveValues;

      std::set<std::pair<uint64_t,std::vector<uint8_t> > > negativeValues;

      //lists entries into the sets
      bool successful = iblt->listEntries(positiveValues, negativeValues);

      if (compare2(positiveValues, myEntries, numEntries))
      {
        numSuccess++;
      }

      delete iblt;
      delete myEntries;
    }

    cout << "NumEntries = " << numEntries << ". Num Successes = " << numSuccess << endl;
  }
  return 0;

}
