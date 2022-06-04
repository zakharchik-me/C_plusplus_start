#pragma once
#include "Circle.h"
#include "EquilateralTriangle.h"
#include <vector>

using namespace std;

class Choices {
private:
    Vector2D* centerMass = new Vector2D(0, 0);
    vector<AllClasses*> vec;
public:
    void AddFigures();
    void ShowFigures();
    void SummarySquare();
    void SummaryPerimeter();
    void SummaryCenterMass();
    void AllMemory();
    void MassSort();
};

