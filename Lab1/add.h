//
// Created by Anton Zakharov on 20.02.2022.
//

#ifndef LAB1_ADD_H
#define LAB1_ADD_H


void Inc(int& num1, int& num2){
    num1 = num1+num2;
}
void INc(int* num1, int* num2){
    *num1 = *num1 + *num2;
}
void Zeloe(int& zeloe, float& vesh){
    zeloe = static_cast<int>(vesh);
    vesh = vesh - zeloe;
}
void Zeloe(int* zeloe, float* vesh){
    *zeloe = static_cast<int>(*vesh);
    *vesh = *vesh - *zeloe;
}

void Compl(float& complex) {
    complex = -complex;
}
void Compl(float *complex) {
    *complex = -*complex;
}
void ZZZ(std::complex<double>&zzz){
    zzz = conj(zzz);
}
void Zz(std::complex<double>* zzz){
    *zzz = conj(*zzz);
}

void KVV(int A[], int& vec_x, int& vec_y) {
    for (int i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            A[i] = A[i] + vec_x;
        } else {
            A[i] = A[i] + vec_y;
        }
    }
}
void Shift(int(*vertix)[4][2], int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int x, y;
        int newVertixX = (*vertix)[i][0] + x;
        int newVertixY = (*vertix)[i][1] + y;
        printf("(%+d, %+d)", newVertixX, newVertixY);
    }
}
#endif //LAB1_ADD_H
