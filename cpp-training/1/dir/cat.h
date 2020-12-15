// cat.h
#ifndef CAT_H // include guard
#define CAT_H
#include <string>

using namespace std;

class Cat {
public:
  string name;
  Cat(string n);
  void meow();
};

#endif /* CAT_H */