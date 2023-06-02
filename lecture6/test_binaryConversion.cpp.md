
```cpp
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#define BIN_DIGITS  4

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

void _convertToBinary(unsigned int n, char * convertedBinary, int * index)
{
  if (n / 2 != 0)
      _convertToBinary(n / 2, convertedBinary, index);
  
  convertedBinary[(*index)++] = n % 2;
  cout << n % 2;
}


char* convertToBinary(unsigned int n, unsigned int digits) {
  // dynamic allocation
  char * convertedBinary = new char[digits];
  
  // index is used by recursive function
  int * index = new int;
  
  // calculate starting index for binary number array
  // index n-1 is 2^0 place, n-2 is 2^1, n-3 is 2^2, ... etc
  // we have to start from the number's highest place
  int digits_required = (int)(log2(n)+0.5);
  *index = BIN_DIGITS - digits_required;

  // fill with zeroes
  for (int i = 0; i < digits; ++i)
    convertedBinary[i] = 0;

  // result will be stored in array 'convertedBinary'
  _convertToBinary(n, convertedBinary, index);
  cout << endl;
  
  delete index;
  return convertedBinary;
}

// void printArray(char arr[], int size) {
//     for (int i = 0; i < size; ++i)
//         cout << arr[i];
//     cout << endl;
// }


void printArray(char * arr, int size) {
    for (int i = 0; i < size; i++)
        cout << (int) arr[i];
    cout << endl;
}

int main()
{
    char * convertedBinary = convertToBinary(6, BIN_DIGITS);
    printArray(convertedBinary, BIN_DIGITS);
    // char *arr = new char[4];
    // arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 4;
    // printf("arr: %d %d %d %d\n", (int)convertedBinary[0], (int)convertedBinary[1], (int)convertedBinary[2],(int)convertedBinary[3]);
    int x = 13;
    char y = x;
    cout <<"y: " << (int) y << endl;
    // printArray(convertToBinary, BIN_DIGITS);

    return 0;
}
```