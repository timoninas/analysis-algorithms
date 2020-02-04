//
//  matrixObject.cpp
//  aa_lab5
//
//  Created by Антон Тимонин on 31.01.2020.
//  Copyright © 2020 Антон Тимонин. All rights reserved.
//

#include "matrixObject.hpp"


matrixObject::matrixObject(unsigned size, int min, int max, int indexObj) {
    number = indexObj;
    sizeMatrix = size;
    firstMatrix = get_matrix(sizeMatrix, -15, 100);
    secondMatrix = get_matrix(sizeMatrix, -15, 10);
    resultMatrix = get_matrix(sizeMatrix, 0, 0);
}

int matrixObject::get_rand_number(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int** matrixObject::get_matrix(unsigned size, int min, int max) {
    int **matrix = new int * [size];
    
    for (unsigned i = 0; i < size; i++) {
        
        matrix[i] = new int [size];
        for (unsigned j = 0; j < size; j++) {
            matrix[i][j] = get_rand_number(min, max);
        }
    }
    
    return matrix;
}

void matrixObject::addUpMatrix(int start, int end) {
    for (int i = start; i < end; i++)
        for (int j = 0; j < sizeMatrix; j++) {
            resultMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
        }
}

void matrixObject::print_matrix(int **a) {
    std::cout << std::endl;
    for (unsigned i = 0; i < sizeMatrix; i++) {
        
        std::cout << std::endl;
        
        for (unsigned j = 0; j < sizeMatrix; j++) {
            std::cout << a[i][j] << " ";
        }
    }
    std::cout << "\n\n";
}

