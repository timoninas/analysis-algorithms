//
//  thread.hpp
//  aa_lab4
//
//  gavnocode created by Антон Тимонин on 16.11.2019.
//  Copyright © 2019 Антон Тимонин. All rights reserved.
//

#ifndef thread_hpp
#define thread_hpp

#include <stdio.h>
#include <thread>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include <chrono>
#include "matrix.hpp"



void create_mulH(int **&A, vector <int>& row, const unsigned int &M_start, const unsigned int &M_end, const unsigned int &N);
void create_mulV(int **&B, vector <int>& column, const unsigned int &Q_start, const unsigned int &Q_end, const unsigned int &N);
void calculate(int **&A, int **&B, int **&C, vector <int> &row, vector <int> &column, const unsigned int &M, const unsigned int &N, const unsigned int &Q);
void calculate1(matrix_type &a, matrix_type &b, matrix_type &c, vector <int> &row, vector <int> &column, const unsigned int n_start, unsigned int n_end);
void Vinograd_1_thread(int **A, int **B, int **C,
                       unsigned M, unsigned N, unsigned Q);
void Vinograd_2_thread(matrix_type &a, matrix_type &b, matrix_type &c);
void Vinograd_4_thread(matrix_type &a, matrix_type &b, matrix_type &c);
void Vinograd_8_thread(matrix_type &a, matrix_type &b, matrix_type &c);
void Vinograd_n_thread(matrix_type &a, matrix_type &b, matrix_type &c, int n);

#endif /* thread_hpp */
