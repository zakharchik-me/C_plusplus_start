#include "calc.h"
#include "Point.h"
#include "line.h"
#include "lline.h"
#include "poly.h"
#include "trap.h"
#include "triangle.h"
#include "figure.h"
#include "reg.h"

int main() {

    ChainedBrokenLine a;

    Figure *T[4];
    T[0] = new Triangle();
    T[1] = new Trapezoid();
    T[2] = new RegularPolygon();

    T[0]->setPolygon();
    T[1]->setPolygon();
    T[2]->setPolygon();

    for (int i = 0; i< 3; ++i)
        cout << (T[i])->square() << endl;

    return 0;
}