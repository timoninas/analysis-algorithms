//
//  main.cpp
//  aa_lab3
//
//  Created by Антон Тимонин on 22.10.2019.
//  Copyright © 2019 Антон Тимонин. All rights reserved.
//



#include "sort.hpp"
#include "random.hpp"

int main(int argc, const char * argv[]) {
    
    int *a;
    int n = 13;
    
    srand(time(nullptr));
    
    a = get_random_array(n, -5, 20);
    array_print(a, n);
    
    std::cout << "\nProgramm completed\n";
    return 0;
}
