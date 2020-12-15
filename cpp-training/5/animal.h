#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

using namespace std;

class Animal {
public:
  Animal(string x);
  void print();

protected:
  string name;
};

#endif