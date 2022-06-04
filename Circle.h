#pragma once
#include "Interface.h"

class Circle : public AllClasses
{
private:
	double weight, radius;
	Vector2D center;
public:
	Circle();
	Circle(double centerX, double centerY, double rad, double mass);

	double square() override;
	double perimeter() override;
	double mass() override;
	Vector2D position() override;
	bool operator == (IPhysObject& object) const override;
	bool operator < (IPhysObject& object) const override;
	void draw() override;
	void initFromDialog() override;
	const char* classname() override;
	unsigned size() override;
	~Circle();
};


