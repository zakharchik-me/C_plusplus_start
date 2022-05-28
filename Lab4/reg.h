#ifndef __REG_H
#define __REG_H

//#define COMMENTS
//#define SITUATIONAL

class RegularPolygon : public Polygon {
public:
    //Êîíñòðóêòîð ïî óìîë÷àíèþ
    RegularPolygon() {
#ifdef COMMENTS
        cout << endl << "Regular polygon been successfully created" << endl;
#endif //COMMENTS
    }

    //Êîíñòðóêòîð ÷åðåç âåêòîð òî÷åê
    [[maybe_unused]] explicit RegularPolygon(const vector<Point> &v) {
        if (isRegularPolygonCorrect(v) && getSquare(v) != 0) {
            for (auto const &elem : v)
                this->PolyVect.emplace_back(elem);
#ifdef COMMENTS
            cout << endl << "Congrats! Polygon (Regular polygon) has been successfully created!" << endl;
#endif //COMMENTS
        } else cout << "Sorry, it is not a regular polygon." << endl << endl;
    }

    //Ââîä òî÷åê â ìíîãîóãîëüíèê
    void setPolygon() override {
        this->PolyVect.clear();
        int size;
        cout << endl << "Enter amount of points in polygon: ";
        cin >> size;
        cout << endl;
        float x, y;
        cout << "There will be 3 points in polygon (regular polygon)" << endl;
        cout << "Enter point's coordinates for polygon (regular polygon):" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> x >> y;
            this->PolyVect.emplace_back(Point(x, y));
        }

        if (square() == 0 || !isRegularPolygonCorrect(this->PolyVect)) {
            cout << "Sorry, it's not a regular polygon. Try to enter different points" << endl;
            setPolygon();
        } else cout << endl << "Congrats! Polygon (Regular polygon) has been successfully created!" << endl;
    }

    //Îïåðàòîð ïðèñâàíèâàíèÿ
    RegularPolygon &operator=(const RegularPolygon &t) {
        this->PolyVect.resize(0);
        for (auto const &elem : t.PolyVect)
            PolyVect.emplace_back(elem);
#ifdef COMMENTS
        cout << "Operator =" << endl;
#endif //COMMENTS

        return *this;
    }

    //Äåñòðóêòîð
    ~RegularPolygon() {
#ifdef COMMENTS
        cout << "Regular polygon died" << endl;
#endif //COMMENTS
    }

};

#endif //__REGULARPOLYGON_H