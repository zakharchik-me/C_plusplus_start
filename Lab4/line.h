#ifndef __LINE_H
#define __LINE_H

#include <vector>
#include "calc.h"

//#define COMMENTS
//#define SITUATIONAL

class BrokenLine {
protected:
    vector<Point> BLVect;
public:
    BrokenLine() {
#ifdef COMMENTS
        cout << "Broken line been successfully created" << endl;
#endif //COMMENTS
    }

    //Êîíñòðóêòîð êîïèðîâàíèÿ
    BrokenLine(const BrokenLine &p) {
        this->BLVect.resize(0);
        for (auto const &elem : p.BLVect)
            this->BLVect.emplace_back(elem);
#ifdef COMMENTS
        cout << endl << "Broken line has been successfully copied!" << endl;
#endif //COMMENTS
    }

    [[maybe_unused]] explicit BrokenLine(const vector<Point> &m) {
        if (m.size() >= 3 && getSquare(m) != 0) {
            this->BLVect = m;
        } else cout << "Sorry, it's not a broken line" << endl;
    }

    virtual void setBrokenLine() {
        this->BLVect.clear();
        int size;
        cout << endl << "Enter amount of points in broken line: ";
        cin >> size;
        cout << endl;
        if (size >= 3) {
            float x, y;
            cout << "There will be " << size << " points in broken line" << endl;
            cout << "Enter point's coordinates for broken line:" << endl;
            for (int i = 0; i < size; i++) {
                cin >> x >> y;
                this->BLVect.emplace_back(Point(x, y));
            }

            if (getSquare(this->BLVect) == 0) {
                cout << endl << "Sorry, it's not a broken line. Try to enter different points" << endl;
                setBrokenLine();
            } else cout << endl << "Congrats! Broken line been successfully created" << endl;
        } else {
            cout << "It could not be less than 3 points in broken line." << endl
                 << "Try to enter another amount of points" << endl;
            setBrokenLine();
        }
    }

    virtual void getBrokenLine() const {
        cout << endl << "Our broken line's points:" << endl;

        for (int i = 0; i < this->BLVect.size(); i++)
            cout << i + 1 << ") " << this->BLVect[i].getX() << "\t" << this->BLVect[i].getY() << endl;
    };

    void getAdress() const {
        cout << "Adress " << this << endl;
    }

    [[maybe_unused]] virtual void getInfo() {
        cout << "\n________________________________________________\n";
        cout << "All info about it's broken line:" << endl;
        getAdress();
        if (!this->BLVect.empty()) {
            cout << "Length: " << length() << endl;
            cout << "It contains " << BLVect.size() << " points, here they are:" << endl;
            getBrokenLine();
        } else cout << "It isn't contains any points" << endl;
        cout << "________________________________________________\n";
    }

    BrokenLine &operator=(const BrokenLine &t) {
        BLVect.clear();
        for (auto const &elem : t.BLVect)
            BLVect.emplace_back(elem);
#ifdef COMMENTS
        cout << "Operator =" << endl;
#endif //COMMENTS

        return *this;
    }

    virtual float length() {
        if (!this->BLVect.empty()) {
            float length = getPetimeter(this->BLVect);
            length -= sqrt(
                    pow(BLVect[BLVect.size() - 1].getX() - BLVect[0].getX(), 2) +
                    pow(BLVect[BLVect.size() - 1].getY() - BLVect[0].getY(), 2));

            return length;
        } else cout << "Sorry, it doesn't have a length" << endl; return 0;
    }


    ~BrokenLine() {
#ifdef COMMENTS
        cout << "Broken line died" << endl;
#endif //COMMENTS
    };

};

#endif //__BROKENLINE_H