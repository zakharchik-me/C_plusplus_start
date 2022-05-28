#ifndef __TRIANGLE_H
#define __TRIANGLE_H

//#define COMMENTS
//#define SITUATIONAL

class Triangle : public Polygon {
public:
    //Êîíñòðóêòîð ïî óìîë÷àíèþ
    Triangle() {
#ifdef COMMENTS
        cout << endl << "Triangle been successfully created" << endl;
#endif //COMMENTS
    }

    //Êîíñòðóêòîð ÷åðåç âåêòîð òî÷åê
    explicit Triangle(const vector<Point> &v) {
        if (v.size() == 3 && getSquare(v) != 0) {
            for (auto const &elem : v)
                this->PolyVect.emplace_back(elem);
#ifdef COMMENTS
            cout << endl << "Congrats! Polygon (Triangle) has been successfully created!" << endl;
#endif //COMMENTS
        } else cout << "Sorry, it is not a triangle." << endl << endl;
    }

    //Ââîä òî÷åê â ìíîãîóãîëüíèê
    void setPolygon() override {
        this->PolyVect.clear();
        float x, y;
        cout << "There will be 3 points in polygon (triangle)" << endl;
        cout << "Enter point's coordinates for polygon (triangle):" << endl;
        for (int i = 0; i < 3; i++) {
            cin >> x >> y;
            this->PolyVect.emplace_back(Point(x, y));
        }

        if (square() == 0) {
            cout << "Sorry, it's not a triangle. Try to enter different points" << endl;
            setPolygon();
        } else cout << endl << "Congrats! Polygon (Triangle) has been successfully created!" << endl;
    }

    //Îïåðàòîð ïðèñâàíèâàíèÿ
    Triangle &operator=(const Triangle &t) {
        this->PolyVect.resize(0);
        for (auto const &elem : t.PolyVect)
            PolyVect.emplace_back(elem);
#ifdef COMMENTS
        cout << "Operator =" << endl;
#endif //COMMENTS

        return *this;
    }

    //Äåñòðóêòîð
    ~Triangle() {
#ifdef COMMENTS
        cout << "Triangle died" << endl;
#endif //COMMENTS
    }

};

#endif //__TRIANGLE_H
