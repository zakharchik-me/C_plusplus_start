//
// Created by Anton Zakharov on 09.04.2022.
//

#ifndef LAB5_SWAP_H
#define LAB5_SWAP_H
#include <iostream>
#include <vector>

using namespace std;

template <class T>
int find_min(T a, T b)
{
    if(a<b)
        cout<<"Min:"<< a;
    else
        cout<<"Min:"<< b;
    return 0;
}

template <typename T>
class Matrix {
public:
    int N, M;
    vector< vector<double> > matri;
    Matrix()
    {
        N = 2;
        M = 2;

        for (int i = 0; i < N; i++)
        {
            vector<double> rw;
            for (int j = 0; j < M; j++)
                rw.push_back(i + j);
            matri.push_back(rw);
        }
    };
    Matrix(int r, int c)
    {
        N = r;
        M = c;
        for (int i = 0; i < N; i++)
        {
            vector<double> rw;
            for (int j = 0; j < M; j++)
                rw.push_back(i + j);
            matri.push_back(rw);
        }
    };
    int get(int i, int j) {
        if(i >= 0 && i<N && j >= 0 && j<M) {
            return matri[i][j];
        } else {
            cout << "WRONG INDEX!\n";
            return -1;
        }
    };
};
#endif //LAB5_SWAP_H
