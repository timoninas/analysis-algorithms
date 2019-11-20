//
//  thread.cpp
//  aa_lab4
//
//  gavnocode created by Антон Тимонин on 16.11.2019.
//  Copyright © 2019 Антон Тимонин. All rights reserved.
//

#include "thread.hpp"


void create_mulH(int **&A, vector <int>& row, const unsigned int &M_start, const unsigned int &M_end, const unsigned int &N)
{
    
    for (unsigned i = M_start; i < M_end; i++) {
        //cout << this_thread::get_id()<< endl;
        for (unsigned k = 0; k < N / 2; k++) {
            row[i] += A[i][2 * k] * A[i][2 * k + 1];
        }
    }
}

void create_mulV(int **&B, vector <int>& column, const unsigned int &Q_start, const unsigned int &Q_end, const unsigned int &N)
{
    
    for (unsigned i = Q_start; i < Q_end; i++) {
        //cout << this_thread::get_id()<< endl;
        for (unsigned k = 0; k < N / 2; k++) {
            column[i] += B[2 * k][i] * B[2 * k + 1][i];
        }
    }
}

void calculate(int **&A, int **&B, int **&C, vector <int> &row, vector <int> &column, const unsigned int &M, const unsigned int &N, const unsigned int &Q)
{
    for (unsigned i = 0; i < M; i++)
        for (unsigned j = 0; j < Q; j++) {
            if (N % 2 == 0)
                C[i][j] = -row[i] - column[j];
            else
                C[i][j] = -row[i] - column[j] + A[i][N - 1] * B[N - 1][j];
            
            for (unsigned k = 0; k < N / 2; k++) {
                C[i][j] = C[i][j] + (A[i][k << 1] + B[k << 1 | 1][j]) *
                (A[i][k << 1 | 1] + B[k << 1][j]);
            }
        }

}

void calculate1(matrix_type &a, matrix_type &b, matrix_type &c, vector <int> &row, vector <int> &column, const unsigned int &n_start, unsigned int &n_end)
{
    for (unsigned i = n_start; i < n_end; i++) {
        //cout << this_thread::get_id()<< endl;
        for (unsigned j = 0; j < b.m; j++) {
            
            c.matrix[i][j] = -row[i] - column[j];
                
            for (unsigned k = 0; k < a.m / 2; k++) {
                c.matrix[i][j] = c.matrix[i][j] + (a.matrix[i][k << 1] + b.matrix[k << 1 | 1][j]) *
                (a.matrix[i][k << 1 | 1] + b.matrix[k << 1][j]);
            }
            
            if (a.m % 2 == 1)
                c.matrix[i][j] = c.matrix[i][j] + a.matrix[i][a.m - 1] * b.matrix[b.n - 1][j];
        }
    }

}

void Vinograd_1_thread(int **A, int **B, int **C,
                       unsigned M, unsigned N, unsigned Q)
{
    vector<int> row(M);
    vector<int> column(Q);
    
    for (int i = 0; i < M; i++) {
        row.push_back(0);
    }
    for (int i = 0; i < Q; i++) {
        column.push_back(0);
    }
    zeroing(C, M, Q);
    
    thread thr_mulH(create_mulH, ref(A), ref(row), 0, ref(M), ref(N));
    thr_mulH.join();
    thread thr_mulV(create_mulV, ref(B), ref(column), 0, ref(Q), ref(N));
    thr_mulV.join();
    
//    for (int i = 0; i < M; i++) {
//        cout << row[i] << " ";
//    }; cout << endl;
//
//    for (int i = 0; i < Q; i++) {
//        cout << column[i] << " ";
//    }; cout << endl;
    
    thread thr_calculate(calculate, ref(A), ref(B), ref(C), ref(row), ref(column), ref(M), ref(N), ref(Q));
    thr_calculate.join();
}

void Vinograd_2_thread(matrix_type &a, matrix_type &b, matrix_type &c)
{
    vector<int> row(a.n);
    vector<int> column(b.m);
    unsigned int n1 = a.n / 2;
    zeroing(c.matrix, c.n, c.m);
    
    for (int i = 0; i < a.n; i++) {
        row.push_back(0);
    }
    for (int i = 0; i < b.m; i++) {
        column.push_back(0);
    }
    
    thread thr_mulH(create_mulH, ref(a.matrix), ref(row), 0, ref(a.n), ref(a.m));
    thread thr_mulV(create_mulV, ref(b.matrix), ref(column), 0, ref(b.m), ref(b.n));
    
    thr_mulH.join();
    thr_mulV.join();
    
    thread thr_calculate1(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), 0, ref(n1));
    thread thr_calculate2(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), ref(n1), ref(a.n));
    
    thr_calculate1.join();
    thr_calculate2.join();
}

void Vinograd_4_thread(matrix_type &a, matrix_type &b, matrix_type &c)
{
    vector<int> row(a.n);
    vector<int> column(b.m);
    
    unsigned int n14 = a.n / 4;
    unsigned int n12 = a.n / 2;
    unsigned int n34 = a.n * 3 / 2;
    
    
    for (int i = 0; i < a.n; i++) {
        row.push_back(0);
    }
    for (int i = 0; i < b.m; i++) {
        column.push_back(0);
    }
    
    thread thr_mulH(create_mulH, ref(a.matrix), ref(row), 0, ref(a.n), ref(a.m));
    thr_mulH.join();
    
    thread thr_mulV(create_mulV, ref(b.matrix), ref(column), 0, ref(b.m), ref(b.n));
    thr_mulV.join();
    
    thread thr_calculate1(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), 0, ref(n14));
    thr_calculate1.join();
    
    thread thr_calculate2(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), ref(n14), ref(n12));
    thr_calculate2.join();
    
    thread thr_calculate3(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), ref(n12), ref(n34));
    thr_calculate3.join();
    
    thread thr_calculate4(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), ref(n34), ref(a.n));
    thr_calculate4.join();
}



