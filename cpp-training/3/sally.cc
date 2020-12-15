#include "sally.h"
#include <iostream>

using namespace std;

void Sally::f1() { cout << "regular" << endl; }

void Sally::f2() const { cout << "const " << endl; }
