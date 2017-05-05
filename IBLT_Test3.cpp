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
* Test to determine the functionality of the IBLT subtraction operation
* Generates two IBLTs, subtracts one from the other, checks the list entries operation
*/

int main()
{
  int numEntries = 100;

  //creates multidimensioanl arrays of key/value pairs for each iblt
  int** myEntriesA = createValues3(numEntries, 0);

  int** myEntriesB = createValues3(numEntries, 5);

  //initializes IBLT object with number of entries and size of each entry
  IBLT* ibltA = new IBLT(size_t(numEntries), sizeof(500));

  IBLT* ibltB = new IBLT(size_t(numEntries), sizeof(500));

  //adds entries into the IBLT
  addEntries(myEntriesA, ibltA, numEntries);

  addEntries(myEntriesB, ibltB, numEntries);

  //initializes sets of pairs to hold keys and values
  std::set<std::pair<uint64_t,std::vector<uint8_t> > > positiveValuesA;

  std::set<std::pair<uint64_t,std::vector<uint8_t> > > negativeValuesA;

  std::set<std::pair<uint64_t,std::vector<uint8_t> > > positiveValuesB;

  std::set<std::pair<uint64_t,std::vector<uint8_t> > > negativeValuesB;

  std::set<std::pair<uint64_t,std::vector<uint8_t> > > positiveValuesC;

  std::set<std::pair<uint64_t,std::vector<uint8_t> > > negativeValuesC;

  //subtracts the iblts
  IBLT ibltC = *ibltA - *ibltB;

  //lists the entries from the new iblt
  bool successfulC = ibltC.listEntries(positiveValuesC, negativeValuesC);

  //checks if listing entries was successful
  if (successfulC)
  {
    cout << "Successful listing of entries out of IBLT C Made from A- B" << endl;
    cout << "Expected five extra keys in A that are not in B and 5 extra keys in B that are not in B" << endl;
  }

  //manually calculates differences in original sets
  vector<int*> differences = makeDiffVector(myEntriesA, myEntriesB, numEntries);


  std::set<std::pair<uint64_t, std::vector<uint8_t> > >::iterator it;

  cout << "Keys only in A" << endl;

  //iterates through the set of keys only in A
  for (it = positiveValuesC.begin(); it != positiveValuesC.end(); it++)
  {
    uint64_t key = std::get<0>(*it);

    cout << key << endl;
  }

  cout << "Keys Only in B" << endl;

  //iterates through the set of keys only in B
  for (it = negativeValuesC.begin(); it != negativeValuesC.end(); it++)
  {
    uint64_t key = std::get<0>(*it);

    cout << key << endl;
  }

  cout << "Official Differences" << endl;

  //lists the actual differences
  for (int i = 0; i < numEntries; i++)
  {
    cout << differences[i][0] << endl;
  }

//  return 0;
}
