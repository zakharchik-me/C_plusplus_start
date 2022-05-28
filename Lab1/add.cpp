

int main(){
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
    std::complex<float>z;
    std::complex<float>z1;
    void Compl(float& zeloe_c, float& complex) {
        std::complex<float> co(zeloe_c, complex);
        z1 = std::conj(co);
    }
    void Compl(float* zeloe_c, float* complex) {
        std::complex<float>co(*zeloe_c, *complex);
        z1 = std::conj(co);
    }

    int a, b, c, d
    void Kvv(int& A, int& vec_x, int& vec_y){
        std::pair<int, int>a(0, 0);
        std::pair<int, int>b(A, 0);
        std::pair<int, int>c(A, A);
        std::pair<int, int>d(0, A);
        a.first += 0; a.second += 0;
        b.first += vec_x; b.second += 0;
        c.first += vec_x; c.second += vec_y;
        d.first += 0; d.second += vec_y;
    }
    int * a_a, a_aa, b_b, b__bb, c_c, c_cc, d_d, d_dd;
    int * vec_xx;
    void Kv(int A, int vec_x, int vec_y){
        std::pair<int, int>a(0, 0);
        std::pair<int, int>b(A, 0);
        std::pair<int, int>c(A, A);
        std::pair<int, int>d(0, A);
        a.first += 0; a.second += 0;
        b.first += vec_x; b.second += 0;
        c.first += vec_x; c.second += vec_y;
        d.first += 0; d.second += vec_y;
        aa = a.first; aaa = a.second; bb = b.first; bbb = b.second; cc = c.first; ccc = c.second; dd = d.first; ddd = d.second;
    }
}