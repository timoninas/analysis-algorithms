//Complect MinGW 32bits

//"sorsktdfkjjk" "kosrtfdjkkj" - It is death for recursion method

#include "alg_laewenstein_.h"

int main()
{
    string s1 = "hello";
    string s2 = "halo";

    cout << levenstein(s1, s2) << endl;
    cout << levenstein_rec(s1, s2) << endl;
    cout << dameray_levenstein(s1, s2) << endl;
    cout << dameray_levenstein_rec(s1, s2) << endl;

    cout <<"\nprogramm completed\n";
    return 0;
}
