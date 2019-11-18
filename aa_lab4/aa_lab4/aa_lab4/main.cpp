//
//  main.cpp
//  aa_lab4
//
//  Created by Антон Тимонин on 11.11.2019.
//  Copyright © 2019 Антон Тимонин. All rights reserved.
//

#include <iostream>
#include <thread>
#include "thread.hpp"
//#include "test.h"

void DoWork()
{
    for (size_t i = 0; i < 20; i++){
        std::cout << "ID thread = " << std::this_thread::get_id() << "\tDoWork\t" << i << std::endl;
    }
}


//int main(int argc, const char * argv[]) {
//
//    std::thread thr(DoWork);
//    
//
//    for (size_t i = 0; i < 30; i++) {
//        std::cout << "ID thread = " << std::this_thread::get_id() << "\tmain\t" << i << std::endl;
//    }
//
//    thr.join();
//    return 0;
//}




int main(int argc, const char * argv[]) {
    
    matrix_type a, b, c;
    a.n = 10; a.m = 2000; a.matrix = get_matrix(a.n, a.m, -1, 7);
    b.n = 2000; b.m = 10; b.matrix = get_matrix(b.n, b.m, -1, 9);
    c.n = 10; c.m = 10; c.matrix = get_matrix(c.n, c.m, 0, 0);
    
//    print_matrix(a);
//    print_matrix(b);
//    vingr_mult_matrix(a, b, c, 2, 5, 3);
//    print_matrix(c, 2,  3);
//    vingr_mult_mtr_opt(a, b, c, 2, 5, 3);
//    print_matrix(c, 2, 3);
    
    
    Vinograd_2_thread(a, b, c);
    
//    print_matrix(c);
//    3 6 4 1 3
//    7 5 7 7 0
//
//    5 5 9
//    4 7 6
//    0 4 8
//    3 5 6
//    0 0 3
//
//    42 78 110
//    76 133 191
    
    delete [] a.matrix;
    delete [] b.matrix;
    delete [] c.matrix;
    
    std::cout << "\n\nProgramm completed";
    
    return 0;
}
