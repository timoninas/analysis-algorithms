//
//  test.cpp
//  aa_lab2
//
//  Created by Антон Тимонин on 17.10.2019.
//  Copyright © 2019 Антон Тимонин. All rights reserved.
//

#include "test.h"

unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__("rdtsc" : "=A" (d));
    return d;
}

void test(std::ofstream &file, unsigned start, unsigned end, unsigned step) {
    
    unsigned long int tb, te;
    int **A, **B, **C;
    
    for (unsigned i = start; i < end; i += step) {
        
        unsigned quantity_tests = 10;
        int result[3] = {0, 0, 0};
        
        for (unsigned j = 0; j < quantity_tests; j++) {
            
            A = get_matrix(i, i, -20, 50);
            B = get_matrix(i, i, -20, 50);
            C = get_matrix(i, i, -20, 50);
            
//            tb = tick();
//            cout << dameray_levenstein_rec(s1, s2) << endl;
//            te = tick();
//            cout << te-tb << endl;
            
            zeroing(C, i, i);
            tb = tick();
            std_mult_matrix(A, B, C, i, i, i);
            te = tick();
            result[0] += (te - tb);
            
            zeroing(C, i, i);
            tb = tick();
            vingr_mult_matrix(A, B, C, i, i, i);
            te = tick();
            result[1] += (te - tb);
            
            zeroing(C, i, i);
            tb = tick();
            vingr_mult_mtr_opt(A, B, C, i, i, i);
            te = tick();
            result[2] += (te - tb);
            
            
            delete [] A;
            delete [] B;
            delete [] C;
            
        }
        
        file << "size = " << i << std::endl;
        for (unsigned k = 0; k < 3; k++) {
            result[k] /= quantity_tests;
            file << result[k] << "; ";
        }
        file << "\n";
        
        
        
    }
    
}

void main_for_test() {
    
    std::ofstream outfile ("/Users/antontimonin/Desktop/AA/aa_lab2/time_analyze_for_1001.txt");

    //outfile << "some text" << std::endl;
    
    test(outfile, 101, 1003, 100);

    outfile.close();
}

#include <stdio.h>
