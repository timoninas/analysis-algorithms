//
//  main.cpp
//  aa_lab2
//
//  Created by Антон Тимонин on 16.10.2019.
//  Copyright © 2019 Антон Тимонин. All rights reserved.
//
#include "matrix.h"
#include "test.h"


int main(int argc, const char * argv[]) {
    
    int **a = get_matrix(2, 5, -1, 7);
    int **b = get_matrix(5, 3, -1, 9);
    int **c = get_matrix(2, 3, 0, 0);
    
//    print_matrix(a, 2,  5);
//    print_matrix(b, 5, 3);
//    vingr_mult_matrix(a, b, c, 2, 5, 3);
//    print_matrix(c, 2,  3);
//    vingr_mult_mtr_opt(a, b, c, 2, 5, 3);
//    print_matrix(c, 2, 3);
    
    
    main_for_test();
    
    std::cout << "\n\nProgramm completed";
    
    return 0;
}
