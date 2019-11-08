//
//  matrix.cpp
//  aa_lab2
//
//  Created by Антон Тимонин on 16.10.2019.
//  Copyright © 2019 Антон Тимонин. All rights reserved.
//
#include "matrix.h"



int get_rand_number(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int **get_matrix(unsigned m, unsigned n, int min, int max) {
    int **matrix = new int * [m];
    
    for (unsigned i = 0; i < m; i++) {
        
        matrix[i] = new int [n];
        for (unsigned j = 0; j < n; j++) {
            matrix[i][j] = get_rand_number(min, max);
        }
    }
    
    return matrix;
}

void print_matrix(int **matrix, unsigned m, unsigned n) {
    std::cout << std::endl;
    for (unsigned i = 0; i < m; i++) {
        
        std::cout << std::endl;
        
        for (unsigned j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
    }
    std::cout << "\n\n";
}

void zeroing(int **C, unsigned m, unsigned n) {
    for (unsigned i = 0; i < m; i++)
        for (unsigned j = 0; j < n; j++)
            C[i][j] = 0;
}

void std_mult_matrix(int ** A, int ** B, int ** C,
                     unsigned M, unsigned N, unsigned Q) {
    
    for (unsigned i = 0; i < M; i++)
        for (unsigned j = 0; j < Q; j++) {
            
            C[i][j] = 0;
            
            for (unsigned k = 0; k < N; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            } 
        }
}



void vingr_mult_matrix(int ** A, int ** B, int ** C,
                       unsigned M, unsigned N, unsigned Q) {
    int *mulH = new int [M];
    int *mulV = new int [Q];
    
    for (unsigned i = 0; i < M; i++) {
        mulH[i] = 0;
        for (unsigned k = 0; k < N / 2; k++)
            mulH[i] = mulH[i] + A[i][2 * k] * A[i][2 * k + 1];
    }
    
    for (unsigned i = 0; i < Q; i++) {
        mulV[i] = 0;
        for (unsigned k = 0; k < N / 2; k++)
            mulV[i] += B[2 * k][i] * B[2 * k + 1][i];
    }
    
    for (unsigned i = 0; i < M; i++)
        for (unsigned j = 0; j < Q; j++) {
            C[i][j] = -mulH[i] - mulV[j];
            
            for (unsigned k = 0; k < N / 2; k++) {
                C[i][j] = C[i][j] + (A[i][2 * k] + B[2 * k + 1][j]) *
                (A[i][2 * k + 1] + B[2 * k][j]);
            }
        }
    
    if (N % 2 == 1) {
        for (unsigned i = 0; i < M; i++)
            for (unsigned j = 0; j < Q; j++)
                C[i][j] = C[i][j] + A[i][N - 1] * B[N - 1][j];
    }
    
    delete [] mulH;
    delete [] mulV;
}

void vingr_mult_mtr_opt(int ** A, int ** B, int ** C,
                       unsigned M, unsigned N, unsigned Q) {
    
    unsigned d = N / 2;
    int *mulH = new int [M];
    int *mulV = new int [Q];
    
    for (unsigned i = 0; i < M; i++) {
        mulH[i] = 0;
        for (unsigned k = 0; k < d; k++)
            mulH[i] += A[i][k << 1] * A[i][k << 1 | 1];
    }
    
    for (unsigned i = 0; i < Q; i++) {
        mulV[i] = 0;
        for (unsigned k = 0; k < d; k++)
            mulV[i] += B[k << 1][i] * B[k << 1 | 1][i];
    }
    
    if (N % 2 == 0) {
        
        for (unsigned i = 0; i < M; i++)
            for (unsigned j = 0; j < Q; j++) {
                //C[i][j] = -mulH[i] - mulV[j] + A[i][N - 1] * B[N - 1][j];
                C[i][j] = -mulH[i] - mulV[j];
            
                for (unsigned k = 0; k < N / 2; k++) {
                    C[i][j] = C[i][j] + (A[i][k << 1] + B[k << 1 | 1][j]) *
                    (A[i][k << 1 | 1] + B[k << 1][j]);
                }
            }
        
    } else {
        
        for (unsigned i = 0; i < M; i++)
            for (unsigned j = 0; j < Q; j++) {
                C[i][j] = -mulH[i] - mulV[j] + A[i][N - 1] * B[N - 1][j];
            
                for (unsigned k = 0; k < N / 2; k++) {
                    C[i][j] = C[i][j] + (A[i][k << 1] + B[k << 1 | 1][j]) *
                    (A[i][k << 1 | 1] + B[k << 1][j]);
            }
        }
        
    }
    
    delete [] mulH;
    delete [] mulV;
}


