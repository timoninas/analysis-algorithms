//
//  random.cpp
//  aa_lab3
//
//  Created by Антон Тимонин on 22.10.2019.
//  Copyright © 2019 Антон Тимонин. All rights reserved.
//

#include "random.hpp"

int get_rand_number(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int *get_random_array(unsigned n, int min, int max) {
    int *array = new int [n];
    
    for (unsigned i = 0; i < n; i++) {
            array[i] = get_rand_number(min, max);
        }
    
    return array;
}
