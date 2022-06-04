#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle() {
    center.x = 0;
    center.y = 0;
    weight = 0;
    radius = 0;
}

Circle::Circle(double centerX, double centerY, double rad, double mass) {
    center.x = centerX;
    center.y = centerY;
    radius = rad;
    weight = mass;
}

const char* Circle::classname() {
    return "Круг";
}

unsigned int Circle::size() {
    return sizeof(Circle);
}

double Circle::square() {
    return 3,1415926 * (radius * radius);
}

double Circle::perimeter() {
    return 3,1415926 * (2 * radius);
}

Vector2D Circle::position() {
    Vector2D answer;
    answer.x = x;
    answer.y = y;
    return answer;
}

double Circle::mass() {
    return weight;
}

bool Circle::operator == (IPhysObject& object) const {
    if (weight == object.mass()) {
        return true;
    }
    return false;
}

bool Circle::operator < (IPhysObject& object) const {
    if (weight < object.mass()) {
        return true;
    }
    return false;
}

void Circle::draw() {
    cout << "Имя класса: " << classname() << "\n";
    cout << "Площадь: " << square() << "\n";
    cout << "Периметр: " << perimeter() << "\n";
    cout << "Масса: " << mass() << "\n";
    cout << "Объем памяти: " << size() << "\n";
    cout << "Центр масс: " << "x = " << position().x << ", y = " << position().y << endl;
}

void Circle::initFromDialog() {
    cout << "Введите координаты твоего центра круга:\n";
    cin >> center.x >> center.y;
    cout << "Введите радиус своего круга\n";
    cin >> radius;
    cout << "Введите массу вашего круга\n";
    cin >> weight;
}

Circle::~Circle() = default;