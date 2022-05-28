#include <iostream>
#include <vector>
#include "oper.h"
using namespace std;
const int n=3;
int main(){
    Matrix A, B,C(0),D(0), E(0), F(0);
    Stack G, H;
    cout << "Matrix A:\n";
    A.show();
    cout << "Matrix B:\n";
    B.show();

    cout << "Matrix C=A+B:\n";
    C=A+B;
    C.show();

    cout << "Matrix D=A*B:\n";
    D=A*B;
    D.show();

    cout<<"Matrix E=A*2\n";
    E=A/2;
    E.show();

    cout<<"If Matrix F>A F, else A\n";
    F =A<2;
    F.show();

    cout<<"Stack\n";
    G = G>>G;
    G.showw();

    cout<<"\nStack2\n";
    H=H<<H;
    H.showww();
    return 0;}


