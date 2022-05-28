#include "oper.h"

Matrix::Matrix operator+(Matrix obj, Matrix A){
    Matrix tmp(0);
    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
            tmp[i][j]=matr[i][j]+obj[i][j];return tmp;}

Matrix::Matrix operator*(Matrix obj, Matrix A){
    Matrix tmp(0);
    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
            for(int k=0; k < n; k++)
                tmp[i][j]+=matr[i][k]*obj[k][j];return tmp;}

MAtrix::Matrix operator/(Matrix obj, int D){
    Matrix tmp(0);
    for (int i =0; i<n; i++)
        for(int j=0; j<n; j++)
            tmp[i][j] = matr[i][j]*2;return tmp;}

MAtrix::Matrix operator <(Matrix obj, int A){
    Matrix tmp(0);
    int flag;
    for (int i =0; i<n; i++)
        for(int j=0; j<n; j++)
            if (tmp[i][j] < matr[i][j])
                return tmp;
            else if (tmp[i][j] > matr[i][j])
                return tmp;
            else
                return tmp;
}

Matrix::Matrix& operator=(Matrix&&);

void Matrix::show(){
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            printf("%3d",matr[i][j]);
        }
        cout << endl;
    }
}

Matrix::Matrix(int k){
    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
            matr[i][j]=k;
}

Matrix::Matrix(){
    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
            matr[i][j]=rand()%5-2;
}

Stack operator>>(Stack I, int a){
    int a = rand()%5-2;
    S.push_back(a);
    return I;
}

Stack operator<<(Stack I, int a){
    S.pop_back();
    return I;
}

void Stack::showw(){
    for (int i = 0; i < 4; i++)
        cout<<S[i]<<" ";
}

void Stack::showww(){
    for (int i = 0; i < 2; i++)
        cout<<S[i]<<" ";
    }
}


