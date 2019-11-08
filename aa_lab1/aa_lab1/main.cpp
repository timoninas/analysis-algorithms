//
//  main.cpp
//  aa_lab1
//
//  Created by Антон Тимонин on 14.10.2019.
//  Copyright © 2019 Антон Тимонин. All rights reserved.
//

//Complect MinGW 32bits

//"sorsktdfkjjk" "kosrtfdjkkj" - It is like death for recursion method

#include "alg_laewenstein_.h"
#include <ctime>

unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__("rdtsc" : "=A" (d));
    return d;
}

int main()
{
    long int tb, te;
    
    
    string s1 = "abscd";
    string s2 = "abscfs";

    tb = tick();
    
    cout << levenstein(s1, s2) << endl;
    //cout << levenstein_rec(s1, s2) << endl;
    //cout << dameray_levenstein(s1, s2) << endl;
    //cout << dameray_levenstein_rec(s1, s2) << endl;
    
    te = tick();

    cout << te-tb << endl;

    cout <<"\nprogramm completed\n";
    return 0;
}

