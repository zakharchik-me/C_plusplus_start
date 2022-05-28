#ifndef __TRAP_H
#define __TRAP_H

//#define COMMENTS
//#define SITUATIONAL

class Trapezoid : public Polygon {
public:
    Trapezoid() {
#ifdef COMMENTS
        cout << endl << "Trapezoid been successfully created" << endl;
#endif //COMMENTS
    }

    explicit Trapezoid(const vector<Point> &v) {
        if (v.size() == 4 && getSquare(v) != 0 && isTrapezoidCorrect(v)) {
            for (auto const &elem : v)
                this->PolyVect.emplace_back(elem);
#ifdef COMMENTS
            cout << endl << "Congrats! Polygon (Trapezoid) has been successfully created!" << endl;
#endif //COMMENTS
        } else cout << "Sorry, it is not a trapezoid." << endl << endl;
    }

    void setPolygon() override {
        this->PolyVect.clear();
        float x, y;
        cout << "There will be 4 points in polygon (trapezoid)" << endl;
        cout << "Enter point's coordinates for polygon (trapezoid):" << endl;
        for (int i = 0; i < 4; i++) {
            cin >> x >> y;
            PolyVect.emplace_back(Point(x, y));
        }

        if (square() == 0 || !isTrapezoidCorrect(this->PolyVect)) {
            cout << "Sorry, it's not a trapezoid. Try to enter different points" << endl;
            setPolygon();
        } else cout << endl << "Congrats! Polygon (Trapezoid) has been successfully created!" << endl;
    }

    Trapezoid &operator=(const Trapezoid &t) {
        this->PolyVect.resize(0);
        for (auto const &elem : t.PolyVect)
            PolyVect.emplace_back(elem);
#ifdef COMMENTS
        cout << "Operator =" << endl;
#endif //COMMENTS

        return *this;
    }

    ~Trapezoid() {
#ifdef COMMENTS
        cout << "Trapezoid died" << endl;
#endif //COMMENTS
    }

};

#endif //__TRAPEZOID_H
