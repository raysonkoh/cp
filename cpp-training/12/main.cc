#include <iostream>

using namespace std;

class MyVector {
public:
  int *vPtr;
  int currSize;
  int size;
  MyVector(int s) : currSize(0), size(s), vPtr(new int[s]) {}
  ~MyVector() { delete[] vPtr; }
  void insert(int x) {
    if (currSize == size) {
      cout << "exapnd" << endl;
      // expand
      int *newPtr = new int[size * 2];
      size *= 2;
      for (int i = 0; i < currSize; i++) {
        newPtr[i] = vPtr[i];
      }
      newPtr[currSize] = x;
      delete[] vPtr;
      vPtr = newPtr;
    } else {
      vPtr[currSize] = x;
    }
    currSize++;
  }
  void print() {

    for (int i = 0; i < currSize; i++) {
      cout << vPtr[i] << endl;
    }
  }
};

int main() {
  MyVector mv(2);

  for (int i = 0; i < 1000; i++) {
    mv.insert(i);
  }

  mv.print();
}