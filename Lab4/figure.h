#include <vector>

#ifndef __FIGURE_H
#define __FIGURE_H

//#define COMMENTS

class Figure {
protected:
    vector<Point> PolyVect;
public:
    Figure() {
#ifdef COMMENTS
        cout << endl << "Figure been successfully created" << endl;
#endif //COMMENTS
    };

    virtual float perimeter() = 0;

    virtual float square() = 0;

    virtual void getPolygon() = 0;

    virtual void setPolygon() = 0;

    virtual void getInfo() = 0;

    ~Figure() {
#ifdef COMMENTS
        cout << "Figure died" << endl;
#endif //COMMENTS
    }

};

#endif //__FIGURE_H