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
* Generic test to determine whether the list entries function for the iblt functions properly
* Takes in manual input for how many entries should be inserted into the iblt
* Tests success of listing entries for each loop
* Success = all entries are listed correctly
* States number of missing entries if not all entries were listed
*/

int main()
{
  int numEntries;

  bool quit = false;

  //while the user has not exited out of the program
  while (!quit)
  {
    cout << "Enter number of entries: ";

    cin >> numEntries;

    //creates a multidimensional array, with each internal array containing a key/value pair
    //maximum value of 500 for each key/value
    int** myEntries = createValues(numEntries, 500);

    //initializes IBLT object with the number of anticipated entries and the size of each entry
    IBLT* iblt = new IBLT(size_t(numEntries), sizeof(500));

    //calls function to add entries into the IBLT
    addEntries(myEntries, iblt, numEntries);

    //initializes sets of pairs to hold keys and values
    //positiveValues holds the pairs that were inserted into the IBLT
    //negativeValues holds the pairs that were removed from but not inserted into the IBLT (during IBLT subtraction)
    std::set<std::pair<uint64_t,std::vector<uint8_t> > > positiveValues;

    std::set<std::pair<uint64_t,std::vector<uint8_t> > > negativeValues;

    //lists entries into the sets and checks if successful
    bool successful = iblt->listEntries(positiveValues, negativeValues);

    //compares the created values to the values listed from the IBLT
    compare(positiveValues, myEntries, numEntries);

    //determines if the user wants to exit
    cout << "Exit? (Y/N)" << endl;

    char leave;

    cin >> leave;

    if (leave == 'Y')
    {
      quit = true;
    }

  }

  return 0;

}
