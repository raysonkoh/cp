#include "animal.h"
#include <iostream>

using namespace std;

Animal::Animal(string x) { name = x; }

void Animal::print() { cout << "my name is " << name << endl; }