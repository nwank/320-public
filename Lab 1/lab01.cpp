#include <iostream>
#include "deSelsort.h"
using namespace std;



int main() {
  int data[] ={13, 5, 2, 25, 47, 17, 8, 21};
  int size = sizeof(data) / sizeof(data[0]);
  deSelectionSort(data, size);
  cout << "Sorted array:" << endl;
  printArray(data, size);
}