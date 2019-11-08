//
//  sort.hpp
//  aa_lab3
//
//  Created by Антон Тимонин on 22.10.2019.
//  Copyright © 2019 Антон Тимонин. All rights reserved.
//

#ifndef sort_hpp
#define sort_hpp

#include <iostream>
#include <cstdlib>
#include <stdio.h>


void bubble_sort   (int *arr, unsigned n);
void insertion_sort(int *arr, unsigned n);
void choices_sort  (int *arr, unsigned n);

void array_print(int *arr, unsigned n);
void array_fill (int *arr, unsigned n);

void array_sort_grow(int *arr, unsigned n);
void array_sort_low(int *arr, unsigned n);

#endif /* sort_hpp */
