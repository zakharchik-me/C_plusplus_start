#ifndef __POINT_H
#define __POINT_H

#include <iostream>
#include <math.h>


using namespace std;

class Point {
private:
    float x, y;
public:
    Point() : x(0), y(0) {
#ifdef COMMENTS
        cout << "Point constructor successfully done" << endl;
#endif //COMMENTS
    }

    Point(const float _x,const float _y) : x(_x), y(_y) {
#ifdef COMMENTS
        cout << "float point constructor successfully done" << endl;
#endif //COMMENTS
    }

    Point(const int _x,const  int _y) : x(_x), y(_y) {
#ifdef COMMENTS
        cout << "int point constructor successfully done" << endl;
#endif //COMMENTS
    }

    Point(const Point &t) {
        this->x = t.getX();
        this->y = t.getY();
#ifdef COMMENTS
        cout << endl << "Point has been successfully copied!" << endl;
#endif //COMMENTS
    }

    [[maybe_unused]] void setX(const float _x) {
        this->x = _x;
    }

    [[maybe_unused]] void setY(const float _y) {
        this->y = _y;
    }

    [[nodiscard]] float getX() const {
        return this->x;
    }

    [[nodiscard]] float getY() const {
        return this->y;
    }

    [[maybe_unused]] void getInfo() const {
        cout << "\n";
        cout << "All info about it's point:" << endl << endl;
        cout << "y = " << this->getY() << "\tx = " << this->getX() << endl;
        cout << "Dist for point to zero: " << this->ToZero() << endl;
        cout << "\n";
    }

    Point &operator=(const Point &t) {
        this->x = t.getX();
        this->y = t.getY();

#ifdef COMMENTS
        cout << "Operator =" << endl;
#endif //COMMENTS

        return *this;
    };

    //Ðàññòîÿíèå îò öåíòðà êîîðäèíàò äî òî÷êè
    [[nodiscard]] float ToZero() const {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    ~Point() {
#ifdef COMMENTS
        cout << "Point died" << endl;
#endif //COMMENTS
    }
};

#endif //__POINT_H
