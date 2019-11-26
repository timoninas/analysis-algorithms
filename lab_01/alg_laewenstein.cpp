//
//  alg_laewenstein.cpp
//  aa_lab1
//
//  Created by Антон Тимонин on 14.10.2019.
//  Copyright © 2019 Антон Тимонин. All rights reserved.
//

#include "alg_laewenstein_.h"

int Mmin (int a, int b, int c)
{
  int min = a;
  int max = a;
  if (b > max)  max = b;
  if (c > max)  max = c;
  if (b < min)  min = b;
  if (c < min)  min = c;
    
    return 0;
}

int Llen(string s1)
{
    if (s1.length() == 0) {
        return 0;
    } else {
        return s1.length() - 1;
    }
}

int levenstein_rec(string s1, string s2)
{
    int var = 1;
    int dist = 0;
    int s1_l, s2_l;

    s1_l = Llen(s1);
    s2_l = Llen(s2);


    if (s1.length() == 0 || s2.length() == 0) {
        dist = fabs(s1.length() - s2.length());
        return dist;
    }

    string s1_new = s1.substr(0, s1_l);
    string s2_new = s2.substr(0, s2_l);

    if (s1[s1_l] == s2[s2_l]) {
        var = 0;
    }

    return Mmin (levenstein_rec(s1_new, s2) + 1, levenstein_rec(s1, s2_new) + 1, levenstein_rec(s1_new, s2_new) + var);
}

int levenstein(string s1, string s2)
{
    int len_s1 = s1.length() + 1;
    int len_s2 = s2.length() + 1;

    int arr[len_s1][len_s2];

    for (int i = 0; i < len_s1; i++) {
        for (int j = 0; j < len_s2; j++) {
            if (i * j == 0) {
                arr[i][j] = i + j;
            } else {
                arr[i][j] = 0;

            }
            //cout << arr[i][j] << " ";
        }
        //cout << "\n";
    }
    
    cout << s1 << endl;
    cout << s2 << endl;


    for (int i = 1; i < len_s1; i++) {
        for (int j = 1; j < len_s2; j++) {
            int key = 1;
            if (s1[i-1] == s2[j-1]) {
                key = 0;
            }
            arr[i][j] = Mmin(arr[i-1][j] + 1, arr[i][j-1] + 1,  arr[i-1][j-1] + key);
        }
    }

    for (int i = 0; i < len_s1; i++) {
        for (int j = 0; j < len_s2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    return arr[len_s1 - 1][len_s2 - 1];
}

int dameray_levenstein(string s1, string s2)
{

    int len_s1 = s1.length() + 1;
    int len_s2 = s2.length() + 1;
    int val = 1;

    int arr[len_s1][len_s2];

    for (int i = 0; i < len_s1; i++) {
        for (int j = 0; j < len_s2; j++) {
            if (i * j == 0) {
                arr[i][j] = i + j;
            } else {
                arr[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < len_s1; i++) {
        for (int j = 1; j < len_s2; j++) {
            val = 1;

            if (s1[i-1] == s2[j-1])
                val = 0;

            arr[i][j] = Mmin(arr[i-1][j] + 1, arr[i][j-1] + 1, arr[i-1][j-1] + val);

            if (i > 1 && j > 1 && s1[i-1] == s2[j-2] && s1[i-2] == s2[j-1]) {
                arr[i][j] = Mmin(arr[i][j], arr[i][j], arr[i-2][j-2] + 1);
            }

        }
    }

    /*for (int i = 0; i < len_s1; i++) {
        for (int j = 0; j < len_s2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";*/


    return arr[len_s1 - 1][len_s2 - 1];
}

int dameray_levenstein_rec(string s1, string s2)
{
    int var = 1;
    int dist = 0;
    int s1_l, s2_l;

    s1_l = Llen(s1);
    s2_l = Llen(s2);

    if (s1 == "" || s2 == "") {
        dist = max(s1.length(), s2.length());
        return dist;
    }

    string s1_new = s1.substr(0, s1.length() - 1);
    string s2_new = s2.substr(0, s2.length() - 1);

    if (s1[s1_l] == s2[s2_l]) {
        var = 0;
    }

    dist = Mmin (dameray_levenstein_rec(s1_new, s2) + 1,
                 dameray_levenstein_rec(s1, s2_new) + 1,
                 dameray_levenstein_rec(s1_new, s2_new) + var);

    if (s1.length() >= 2 && s2.length() >= 2 && s1[s1_l] == s2[s2_l - 1] &&
            s1[s1_l - 1] == s2[s2_l]) {
        string s1_damer = s1.substr(0, s1.length() - 2);
        string s2_damer = s2.substr(0, s2.length() - 2);
        dist = Mmin(dist, dist, dameray_levenstein_rec(s1_damer, s2_damer) + 1);
    }

    return dist;
}





