#include "EquilateralTriangle.h"
#include <cmath>
#include <iostream>

using namespace std;

EquilateralTriangle::EquilateralTriangle() {
	vertix1.x = 0;
	vertix1.y = 0;
	vertix2.x = 0;
	vertix2.y = 0;
	vertix3.x = 0;
	vertix3.y = 0;
	side = 0;
	weight = 0;
}

EquilateralTriangle::EquilateralTriangle(double vertix1X, double vertix1Y, double vertix2X, double verti2Y, double vertix3X, double verti3Y, double s, double mass) {
	vertix1.x = vertix1X;
	vertix1.y = vertix1Y;
	vertix2.x = vertix2X;
	vertix2.y = vertix2X;
	vertix3.x = vertix3X;
	vertix3.y = vertix3X;
	side = s;
	weight = mass;
}

double EquilateralTriangle::square() {
	return ((sqrt(3) / 4) * pow(side, 2));
}

double EquilateralTriangle::perimeter() {
	return 3 * side;
}

double EquilateralTriangle::mass() {
	return weight;
}

Vector2D EquilateralTriangle::position() {
	Vector2D answer;
	answer.x = (vertix1.x + vertix2.x + vertix3.x) / 3;
	answer.y = (vertix1.y + vertix2.y + vertix3.y) / 3;
	return answer;
}

bool EquilateralTriangle::operator == (IPhysObject& object) const {
	if (weight == object.mass()) {
		return true;
	}
	return false;
}

bool EquilateralTriangle::operator < (IPhysObject& object) const {
	if (weight < object.mass()) {
		return true;
	}
	return false;
}

void EquilateralTriangle::draw() {
	cout << "Имя класса: " << classname() << "\n";
	cout << "Площадь: " << square() << "\n";
	cout << "Периметр: " << perimeter() << "\n";
	cout << "Масса: " << mass() << "\n";
	cout << "Объем памяти: " << size() << "\n";
	cout << "Центр масс: " << "x = " << position().x << ", y = " << position().y << endl;
}

void EquilateralTriangle::initFromDialog() {
	cout << "Выведите координаты Вашего треульника:\n";
	cin >> vertix1.x >> vertix1.y; cout << "\n";
	cin >> vertix2.x >> vertix2.y; cout << "\n";
	cin >> vertix3.x >> vertix3.y; cout << "\n";
	cout << "Введите сторону вашего равностороннего треугольника\n";
	cin >> side;
	cout << "Введите массу вашего треугольника:\n";
	cin >> weight;
}

const char* EquilateralTriangle::classname() {
	return "Равносторонный треугольник";
}

unsigned EquilateralTriangle::size() {
	return sizeof(EquilateralTriangle);
}

EquilateralTriangle::~EquilateralTriangle() = default;
