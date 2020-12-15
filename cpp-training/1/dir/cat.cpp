#include "cat.h"
#include <iostream>

using namespace std;

Cat::Cat(string n) { name = n; }

void Cat::meow() { cout << name << " goes meow meow" << endl; }
