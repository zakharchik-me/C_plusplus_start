#include <iostream>
#include <iomanip>
#include <complex>
#include "add.h"


int main() {
    int num1, num2, zeloe, A, vec_x, vec_y;int num11; int * num22; float vesh, vesh2, zeloe_c, comp;
//№ 2
    std::cout<<"Enter num 1 and num2: ";
    std::cin>>num1>>num2;
    num11 = num1; num22 = &num2;
    std::cout<<num1<<" "<<num2<<std::endl;
    Inc(num1, num2);
    std::cout<<num1<<std::endl;
    INc(&num11, &num2);
    std::cout<<num11<<std::endl;
//№ 5
    std::cout<<"Enter float numbers: ";
    std::cin>>vesh; vesh2 = vesh;
    std::cout<<std::fixed<<std::setprecision(2)<<vesh<<std::endl;
    Zeloe(&zeloe, &vesh);
    std::cout<<vesh<<std::endl;
    Zeloe(zeloe, vesh2);
    std::cout<<vesh2<<std::endl;
//№ 10
    float* zeloe_cc; float * compp;
    std::cout<<"Enter float int and invisib part of number: ";
    std::cin>>zeloe_c>>comp; zeloe_cc = &zeloe_c; compp = &comp;
    std::complex<double> zzz(zeloe, comp);
    Compl(comp);
    std::cout<<"\n"<<zeloe_c<<" "<<comp;
    Compl(compp);
    std::cout<<"\n"<<zeloe_cc<<" "<<compp<<"\n";
    ZZZ(zzz);
    std::cout<<" "<<zzz<<"\n";
    Zz(&zzz);
    std::cout<<" "<<zzz;
//№ 15
    std::cout<<"\n Enter side of sq(start ll be in 0;0) and coord x y of vector: ";
    std::cin>>A>>vec_x>>vec_y;
    int AA[8] = {0, 0, A, 0, A, A, 0, A};
    int vertex[4][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    KVV(AA, vec_x, vec_y);
    std::cout<<"\n\n"<<AA[0]<<" "<<AA[1]<<"\n "<<AA[2]<<" "<<AA[3]<<"\n "<<AA[4]<<" "<<AA[5]<<"\n "<<AA[6]<<" "<<AA[7]<<"\n";
    Shift(&vertex, vec_x, vec_y);
}
