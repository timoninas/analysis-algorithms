#ifndef ALG_LAEWENSTEIN__H
#define ALG_LAEWENSTEIN__H

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int levenstein(string s1, string s2);
int levenstein_rec(string s1, string s2);
int dameray_levenstein(string s1, string s2);
int dameray_levenstein_rec(string s1, string s2);

#endif // ALG_LAEWENSTEIN__H
