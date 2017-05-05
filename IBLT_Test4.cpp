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
* Test to determine the functionality of the IBLT operations for insert, get, and delete
*/

int main()
{
  int numEntries = 20;

  //creates multidimensioanl array of key/value pairs
  //max value of 500 for each entry
  int** myEntries = createValues(numEntries, 500);

  //initializes IBLT object with number of entries and size of each entry
  IBLT* iblt = new IBLT(size_t(numEntries), sizeof(500));


  //testing the insertion and get functions

  //inserts the first five values in the key/value pair matrix
  for (int i = 0; i < 5; i++)
  {
    iblt->insert(myEntries[i][0], ToVec(myEntries[i][1]));
  }

  bool success = false;

  vector<uint8_t> value;

  //retrives individual key/value pairs and checks if the value returned is accurate
  for (int j = 0; j < 5; j++)
  {
    success = iblt->get(myEntries[j][0], value);

    if (!(success && (ToVec(myEntries[j][1]) == value)))
    {
      break;
    }
  }

  if (success)
  {
    cout << "Inserting and Getting Entries Successful" << endl;
  }

//testing deletion to make sure values are removed and no longer able to be retrieved
//also tests get for values that are not in iblt
  vector<uint8_t> value2;

  //erases first five key/value pairs in the generated matrix
  //attempts to retrieve the deleted entries
  for (int j = 0; j < 5; j++)
  {
    iblt->erase(myEntries[j][0], ToVec(myEntries[j][1]));

    success = iblt->get(myEntries[j][0], value2);

    if (!(success && value2.empty()))
    {
      break;
    }
  }

  //if successfully performs get and does not find any of the values
  if (success)
  {
    cout << "Erasing and Attempting To Get Successful" << endl;
  }

  //Same test of insert and get as before, but with entries 10-14
  for (int i = 10; i < 15; i++)
  {
    iblt->insert(myEntries[i][0], ToVec(myEntries[i][1]));
  }

  success = false;

  value.clear();

  for (int j = 10; j < 15; j++)
  {
    success = iblt->get(myEntries[j][0], value);

    if (!(success && (ToVec(myEntries[j][1]) == value)))
    {
      break;
    }
  }

  if (success)
  {
    cout << "Inserting and Getting Entries Successful" << endl;
  }

  //attempts to get the key/value pairs that have already been retrieved
  for (int j = 10; j < 15; j++)
  {
    success = iblt->get(myEntries[j][0], value);

    if ((success && (ToVec(myEntries[j][1]) == value)))
    {
      break;
    }
  }

  if (success)
  {
    cout << "Get for non-existent entries while IBLT still has entries = successful" << endl;
  }
  return 0;

}
