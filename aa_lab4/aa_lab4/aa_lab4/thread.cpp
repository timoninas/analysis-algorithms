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

void calculate1(matrix_type &a, matrix_type &b, matrix_type &c, vector <int> &row, vector <int> &column, const unsigned int n_start, unsigned int n_end)
{
    int sum = 0;
    
    for (unsigned i = n_start; i < n_end; i++) {
        //cout << this_thread::get_id()<< endl;
        for (unsigned j = 0; j < b.m; j++) {
            
            sum = -row[i] - column[j];
                
            for (unsigned k = 0; k < a.m / 2; k++) {
                sum += (a.matrix[i][2*k] + b.matrix[2*k+1][j]) *
                (a.matrix[i][2*k+1] + b.matrix[2*k][j]);
            }
            
            if (a.m % 2 == 1)
                sum += a.matrix[i][a.m - 1] * b.matrix[b.n - 1][j];
            
            c.matrix[i][j] = sum;
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
    
    thread thr_calculate1(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), 0, n1);
    thread thr_calculate2(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), n1, a.n);
    
    thr_calculate1.join();
    thr_calculate2.join();
}

void Vinograd_4_thread(matrix_type &a, matrix_type &b, matrix_type &c)
{
    vector<int> row(a.n);
    vector<int> column(b.m);
    
    unsigned int n14 = a.n / 4;
    unsigned int n12 = a.n / 2;
    unsigned int n34 = (a.n * 3) / 4;
    
    zeroing(c.matrix, c.n, c.m);
    
    for (int i = 0; i < a.n; i++) {
        row.push_back(0);
    }
    for (int i = 0; i < b.m; i++) {
        column.push_back(0);
    }
    
    thread thr_mulH1(create_mulH, ref(a.matrix), ref(row), 0, (a.n)/2, ref(a.m));
    thread thr_mulH2(create_mulH, ref(a.matrix), ref(row), (a.n)/2, ref(a.n), ref(a.m));
    thread thr_mulV1(create_mulV, ref(b.matrix), ref(column), 0, (b.m)/2, ref(b.n));
    thread thr_mulV2(create_mulV, ref(b.matrix), ref(column), (b.m)/2, b.m, ref(b.n));
    
    thr_mulH1.join(); thr_mulH2.join(); thr_mulV1.join(); thr_mulV2.join();
    
    thread thr_calculate1(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), 0, n14);
    thread thr_calculate2(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), n14, n12);
    thread thr_calculate3(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), n12, n34);
    thread thr_calculate4(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), n34, a.n);

    thr_calculate1.join(); thr_calculate2.join(); thr_calculate3.join(); thr_calculate4.join();
}

void Vinograd_8_thread(matrix_type &a, matrix_type &b, matrix_type &c)
{
    vector<int> row(a.n);
    vector<int> column(b.m);
    
    zeroing(c.matrix, c.n, c.m);
    
    for (int i = 0; i < a.n; i++) {
        row.push_back(0);
    }
    for (int i = 0; i < b.m; i++) {
        column.push_back(0);
    }
    
    thread thr_mulH1(create_mulH, ref(a.matrix), ref(row), 0, (a.n)/4, ref(a.m));
    thread thr_mulH2(create_mulH, ref(a.matrix), ref(row), (a.n)/4, (a.n)/2, ref(a.m));
    thread thr_mulH3(create_mulH, ref(a.matrix), ref(row), (a.n)/2, (a.n * 3)/4, ref(a.m));
    thread thr_mulH4(create_mulH, ref(a.matrix), ref(row), (a.n * 3)/4, ref(a.n), ref(a.m));
    
    thread thr_mulV1(create_mulV, ref(b.matrix), ref(column), 0, (b.m)/4, ref(b.n));
    thread thr_mulV2(create_mulV, ref(b.matrix), ref(column), (b.m)/4, (b.m)/2, ref(b.n));
    thread thr_mulV3(create_mulV, ref(b.matrix), ref(column), (b.m)/2, (b.m * 3)/4, ref(b.n));
    thread thr_mulV4(create_mulV, ref(b.matrix), ref(column), (b.m * 3)/4, ref(b.m), ref(b.n));
    
    thr_mulH1.join(); thr_mulH2.join(); thr_mulH3.join(); thr_mulH4.join();
    thr_mulV1.join(); thr_mulV2.join(); thr_mulV3.join(); thr_mulV4.join();
    
    thread thr_calculate1(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), 0, (a.n)/8);
    thread thr_calculate2(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), (a.n)/8, (a.n)/4);
    thread thr_calculate3(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), (a.n)/4, (a.n * 3)/8);
    thread thr_calculate4(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), (a.n * 3)/8, (a.n)/2);
    thread thr_calculate5(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), (a.n)/2, (a.n * 5)/8);
    thread thr_calculate6(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), (a.n * 5)/8, (a.n * 3)/4);
    thread thr_calculate7(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), (a.n * 3)/4, (a.n * 7)/8);
    thread thr_calculate8(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), (a.n * 7)/8, a.n);

    thr_calculate1.join(); thr_calculate2.join(); thr_calculate3.join(); thr_calculate4.join();
    thr_calculate5.join(); thr_calculate6.join(); thr_calculate7.join(); thr_calculate8.join();
}

void Vinograd_n_thread(matrix_type &a, matrix_type &b, matrix_type &c, int n)
{
    vector<int> row(a.n);
    vector<int> column(b.m);
    
    vector<thread> threads;
    
    unsigned int n1 = a.n / 2;
    zeroing(c.matrix, c.n, c.m);
    
    double length_part = (double) a.n / n;
    if (length_part < 1) {
        length_part = 1;
    }
    
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
    
    for (int i = 1; i <= n; i++) {
        threads.push_back(thread(calculate1, ref(a), ref(b), ref(c), ref(row), ref(column), (a.n * (i - 1)) / n, (a.n * i) / n));
    }
    
    for (int i = 0; i < threads.size(); ++i) {
        if (threads[i].joinable()) {
            threads[i].join();
        }
    }
}

