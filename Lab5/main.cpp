#include <iostream>
#include "min.h"
using namespace std;
int main()
{
    int a, b;
    cout << "Enter values: \n";
    cin >> a >> b;
    find_min(a, b);
    cout <<"\n"<< a << " " << b << endl;
    Matrix<int> aa(a, b);
    cout << "array[a-1][b-3]: " << aa.get(a-1, b-3) << endl;
    cout << "array[a+1][b]: " << aa.get(a+1, b) << endl;
}
