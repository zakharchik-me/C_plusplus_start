//
// Created by Anton Zakharov on 24.03.2022.
//
using namespace std;
#ifndef LAB3_OPER_H
#define LAB3_OPER_H
class Matrix {
public:
    friend Matrix operator+(Matrix obj, Matrix objj);

    friend Matrix operator*(Matrix obj, Matrix objj);

    friend Matrix operator/(Matrix obj, int D);

    friend Matrix operator<(Matrix obj, int A);

    Matrix();
    explicit Matrix(int i);
    void show();
private:
    int n = 3;
    int matr[3][3];

};


class Stack{
public:
    void showw();

    void showww();

    friend Stack& operator>>(Stack& I&, int a);

    friend Stack& operator<<(Stack& I, int a);

private:
    std::vector<int> S = {1, 2, 3};

};




#endif //LAB3_OPER_H
