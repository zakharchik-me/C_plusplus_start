#ifndef __POLY_H
#define __POLY_H

//#define COMMENTS
//#define SITUATIONAL

#include "figure.h"

class Polygon : public Figure {
protected:
    float perimeter() override {
        if (this->PolyVect.empty()) {
            cout << "Sorry, it doesn't have a perimeter" << endl; return 0;
        } else return getPetimeter(this->PolyVect);
    }

    float square() override {
        if (this->PolyVect.empty()) {
            cout << "Sorry, it doesn't have a square" << endl; return 0;
        } else return getSquare(this->PolyVect);
    }
public:
    //Êîíñòðóêòîð ïî óìîë÷àíèþ
    Polygon() {
#ifdef COMMENTS
        cout << endl << "Polygon been successfully created" << endl;
#endif //COMMENTS
    }

    //Êîíñòðóêòîð ÷åðåç âåêòîð òî÷åê
    explicit Polygon(const vector<Point> &v) {
        if (isPolygonCorrect(v)) {
            this->PolyVect.resize(0);
            for (auto const &elem : v)
                this->PolyVect.emplace_back(elem);
#ifdef COMMENTS
            cout << endl << "Congrats! Polygon has been successfully created!" << endl;
#endif //COMMENTS
        } else
            cout << endl << "Sorry, it is not a polygon. Try to enter different points" << endl << endl;
    }

    //Ââîä òî÷åê â ìíîãîóãîëüíèê
    void setPolygon() override {
        this->PolyVect.clear();
        int size;
        cout << endl << "Enter amount of points in polygon: ";
        cin >> size;
        cout << endl;
        float x, y;
        cout << "There will be " << size << " points in polygon" << endl;
        cout << "Enter point's coordinates for polygon:" << endl;
        for (int i = 0; i < size; i++) {
            cin >> x >> y;
            this->PolyVect.emplace_back(Point(x, y));
        }

        if (!isPolygonCorrect(this->PolyVect)) {
            cout << endl << "Sorry, it is not a polygon. Try to enter different points" << endl;
            setPolygon();
        } else cout << endl << "Congrats! Polygon has been successfully created!" << endl;

    }

    //Îïåðàòîð ïðèñâàíèâàíèÿ
    Polygon &operator=(const Polygon &t) {
        this->PolyVect.resize(0);
        for (auto const &elem : t.PolyVect)
            this->PolyVect.emplace_back(elem);
#ifdef COMMENTS
        cout << "Operator =" << endl;
#endif //COMMENTS

        return *this;
    }

    //Âûâîä êîîðäèíàò òî÷åê ìíîãîóãîëüíèêà
    void getPolygon() override {
        cout << endl << "Our polygon's points:" << endl;

        for (int i = 0; i < this->PolyVect.size(); i++)
            cout << i + 1 << ") " << this->PolyVect[i].getX() << "\t" << this->PolyVect[i].getY() << endl;
    }

    void getAddress() const {
        cout << "Adress " << this << endl;
    }

    void getInfo() override {
        cout << "\n________________________________________________\n";
        cout << "All info about it's polygon:" << endl << endl;
        this->getAddress();
        if (!this->PolyVect.empty()) {
            cout << "Perimeter: " << this->perimeter() << endl;
            cout << "Square: " << this->square() << endl;
            cout << "It contains " << this->PolyVect.size() << " points, here they are:" << endl;
            this->getPolygon();
        } else cout << "It isn't contains any points" << endl;
        cout << "________________________________________________\n";
    }

    //Äåñòðóêòîð
    ~Polygon() {
#ifdef COMMENTS
        cout << "Polygon died" << endl;
#endif //COMMENTS
    }

};

#endif //__POLYGON_H