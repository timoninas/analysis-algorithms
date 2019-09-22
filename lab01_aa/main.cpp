//Complect MinGW 32bits

//"sorsktdfkjjk" "kosrtfdjkkj" - It is like death for recursion method

#include "alg_laewenstein_.h"
#include <ctime>

int main()
{
    string s1 = "sorsktdfkjjk";
    string s2 = "kosrtfdjkkj";

    unsigned int start_time = clock();

    //cout << levenstein(s1, s2) << endl;
    cout << levenstein_rec(s1, s2) << endl;
    //cout << dameray_levenstein(s1, s2) << endl;
    //cout << dameray_levenstein_rec(s1, s2) << endl;

    unsigned int end_time = clock();

    unsigned int search_time = end_time - start_time;
    cout << search_time / 1000.0 << endl;

    cout <<"\nprogramm completed\n";
    return 0;
}
