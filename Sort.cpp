#include "Sort.h"

#include <iostream>
#include "Sort.h"
using namespace std;

void Choices::AddFigures() {
    int command;
    while (true) {
        
        cout << "Введи фигуру:\n" << "1 - круг\n" << "2 - Треугольник" << "\n";
        cin >> command;
        if (command == 1) {
            Circle* newCircle = new Circle;
            newCircle->initFromDialog();
            vec.push_back(newCircle);
            return;
        }
        if (command == 2) {
            EquilateralTriangle* newEquilateralTriangle = new EquilateralTriangle;
            newEquilateralTriangle->initFromDialog();
            vec.push_back(newEquilateralTriangle);
            return;
        }
        break;
    }
}

void Choices::ShowFigures() {
    if (!vec.empty()) {
        cout << "Здесь фигуры\n";
    }
    for (auto t : vec) {
        t->draw();
        cout << endl;
    }
}

void Choices::SummarySquare() {
    float square = 0;
    for (auto t : vec) {
        square += t->square();
    }
    cout << "Площади фигур: " << square << endl;
}

void Choices::SummaryPerimeter() {
    float perimeter = 0;
    for (auto t : vec) {
        perimeter += t->perimeter();
    }
    cout << "Параметры фигур: " << perimeter << endl;
}

void Choices::SummaryCenterMass() {
    float sumMass = 0;
    float sumMassX = 0;
    float sumMassY = 0;

    for (auto t : vec) {
        sumMass += t->mass();
        sumMassX += t->mass() * t->position().x;
        sumMassY += t->mass() * t->position().y;
    }
    centerMass->x = sumMassX / sumMass;
    centerMass->y = sumMassY / sumMass;

    cout << "коорлинаты фигур: \n";
    cout << "x: " << centerMass->x << endl;
    cout << "y: " << centerMass->y << endl;
}

void Choices::AllMemory() {
    int size = 0;
    for (auto t : vec) {
        size += t->size();
    }
    cout << "Сумма: " << size << endl;
}

void Choices::MassSort() {
    int j = 0;
    for (int i = 0; i < vec.size(); i++) {
        j = i;
        for (int k = i; k < vec.size(); k++) {
            if (vec[j]->mass() > vec[k]->mass()) {
                j = k;
            }
        }
        swap(vec[i], vec[j]);
    }
    cout << "Figures has been sorted" << endl;

}
