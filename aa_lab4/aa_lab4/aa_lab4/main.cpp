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
    a.n = 3; a.m = 5; a.matrix = get_matrix(a.n, a.m, -1, 7);
    b.n = 5; b.m = 3; b.matrix = get_matrix(b.n, b.m, -1, 9);
    c.n = 3; c.m = 3; c.matrix = get_matrix(c.n, c.m, 0, 0);
    
//    print_matrix(a);
//    print_matrix(b);
//    vingr_mult_matrix(a, b, c, 2, 5, 3);
//    print_matrix(c, 2,  3);
//    vingr_mult_mtr_opt(a, b, c, 2, 5, 3);
//    print_matrix(c, 2, 3);
    
    
    Vinograd_1_thread(a.matrix, b.matrix, c.matrix, a.n, a.m, b.m);
    print_matrix(c);
    
    Vinograd_2_thread(a, b, c);
    print_matrix(c);

//    21    27    54
//    7    1    37
//    24    32    59
    
    delete [] a.matrix;
    delete [] b.matrix;
    delete [] c.matrix;
    
    std::cout << "\n\nProgramm completed";
    
    return 0;
}
