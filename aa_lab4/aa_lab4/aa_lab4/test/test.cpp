//
//  test.cpp
//  aa_lab4
//
//  Created by Антон Тимонин on 20.11.2019.
//  Copyright © 2019 Антон Тимонин. All rights reserved.
//

#include "test.hpp"

unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__("rdtsc" : "=A" (d));
    return d;
}

void test(int size, int value1, int value2)
{
    //unsigned long int tb, te;
    double result = 0;
    
    for (int i = 0; i < 10; i++) {
        result = 0;
        
        matrix_type a, b, c;
        a.n = size; a.m = size; a.matrix = get_matrix(a.n, a.m, value1, value2);
        b.n = size; b.m = size; b.matrix = get_matrix(b.n, b.m, value1, value2);
        c.n = size; c.m = size; c.matrix = get_matrix(c.n, c.m, 0, 0);
        
        //te = tick();
        auto start = chrono::steady_clock::now();
        //Vinograd_1_thread(a.matrix, b.matrix, c.matrix, a.n, a.m, b.m);
        Vinograd_n_thread(a, b, c, 8);
        auto end = chrono::steady_clock::now();
        //tb = tick();
        
        result += chrono::duration_cast<chrono::duration<double>>(end - start).count();;
        
        delete [] a.matrix;
        delete [] b.matrix;
        delete [] c.matrix;
    }
    
    cout << "result of analysis = " << round(result*1000) << endl;
}

void test_main()
{
    for (int i = 100; i < 1005; i += 100)
        test(i, -15, 50);
}
