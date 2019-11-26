//
//  sort.cpp
//  aa_lab3
//
//  Created by Антон Тимонин on 22.10.2019.
//  Copyright © 2019 Антон Тимонин. All rights reserved.
//

#include "sort.hpp"

void bubble_sort(int *arr, unsigned n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
}

void insertion_sort(int *arr, unsigned n) {
    int temp, item;
    for (int counter = 1; counter < n; counter++)
    {
        temp = arr[counter];
        item = counter-1;
        while(item >= 0 && arr[item] > temp)
        {
            arr[item + 1] = arr[item];
            arr[item] = temp;
            item--;
        }
    }
}

void choices_sort(int *arr, unsigned n) {
    for (int repeat_counter = 0; repeat_counter < n; repeat_counter++)
    {
        int temp = arr[0];
        for (int element_counter = repeat_counter + 1; element_counter < n; element_counter++)
        {
            if (arr[repeat_counter] > arr[element_counter])
            {
                temp = arr[repeat_counter];
                arr[repeat_counter] = arr[element_counter];
                arr[element_counter] = temp;
            }
        }
    }
}


void array_print(int *arr, unsigned n) {
    
    std::cout << std::endl;
    
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    
    std::cout << std::endl;
}

void array_fill(int *arr, unsigned n) {
    
}

void array_sort_grow(int *arr, unsigned n) {
    int temp, item;
    for (int counter = 1; counter < n; counter++)
    {
        temp = arr[counter];
        item = counter-1;
        while(item >= 0 && arr[item] > temp)
        {
            arr[item + 1] = arr[item];
            arr[item] = temp;
            item--;
        }
    }
}

void array_sort_low(int *arr, unsigned n) {
    int temp, item;
    for (int counter = 1; counter < n; counter++)
    {
        temp = arr[counter];
        item = counter-1;
        while(item >= 0 && arr[item] < temp)
        {
            arr[item + 1] = arr[item];
            arr[item] = temp;
            item--;
        }
    }
}
