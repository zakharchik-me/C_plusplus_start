#pragma once
#include "Interface.h"
class EquilateralTriangle : public AllClasses
{
private:
	Vector2D vertix1, vertix2, vertix3;
	double side, weight;
public:
	EquilateralTriangle();
	EquilateralTriangle(double vertix1X, double vertix1Y, double vertix2X, double verti2Y, double vertix3X, double verti3Y, double s, double mass);

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
	~EquilateralTriangle();
};

