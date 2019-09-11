//Complect MinGW 32bits

//"sorsktdfkjjk" "kosrtfdjkkj" - It is like death for recursion method

#include "alg_laewenstein_.h"

int main()
{
    string s1 = "sorskt";
    string s2 = "kosrt";

    cout << levenstein(s1, s2) << endl;
    cout << levenstein_rec(s1, s2) << endl;
    cout << dameray_levenstein(s1, s2) << endl;
    cout << dameray_levenstein_rec(s1, s2) << endl;

    cout <<"\nprogramm completed\n";
    return 0;
}
