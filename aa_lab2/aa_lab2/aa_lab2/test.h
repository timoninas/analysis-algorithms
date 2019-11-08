//
//  test.h
//  aa_lab2
//
//  Created by Антон Тимонин on 17.10.2019.
//  Copyright © 2019 Антон Тимонин. All rights reserved.
//

#ifndef test_h
#define test_h

#include "matrix.h"

#include <ctime>
#include <fstream>
#include <cstdlib>

unsigned long long tick(void);
void test(std::ofstream &file, unsigned start, unsigned end, unsigned step);
void main_for_test();

#endif /* test_h */
