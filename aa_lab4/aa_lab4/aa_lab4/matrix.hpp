//
//  matrix.hpp
//  aa_lab4
//
//  Created by Антон Тимонин on 13.11.2019.
//  Copyright © 2019 Антон Тимонин. All rights reserved.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <cstdlib>
#include <iostream>

using namespace std;

struct matrix_type{
    int **matrix;
    unsigned int n;
    unsigned m;
};

int get_rand_number(int a, int b);
int **get_matrix(unsigned m, unsigned n, int min, int max);
void print_matrix(matrix_type a);
void zeroing(int **C, unsigned m, unsigned n);
void std_mult_matrix(int ** A, int ** B, int ** C,
                     unsigned M, unsigned N, unsigned Q);
void vingr_mult_matrix(int ** A, int ** B, int ** C,
                     unsigned M, unsigned N, unsigned Q);
void vingr_mult_mtr_opt(int ** A, int ** B, int ** C,
                        unsigned M, unsigned N, unsigned Q);

#endif /* matrix_hpp */
