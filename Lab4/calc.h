#ifndef __CALC_H
#define __CALC_H

#include <vector>
#include "Point.h"

float angle(float x1, float y1, float x2, float y2, float x3, float y3) {
    return abs(((x2 - x1) * (x3 - x2) + (y3 - y2) * (y2 - y1)) /
               (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) *
                sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2))));
}

float vecCorrectness(float x1, float y1, float x2, float y2, float x3, float y3) {
    float AB_x = x2 - x1;
    float AB_y = y2 - y1;
    float BC_x = x3 - x2;
    float BC_y = y3 - y2;

    return AB_x * BC_y - AB_y * BC_x;
}

float vecLen(float x1, float y1, float x2, float y2) {
    return abs((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

float getSquare(const vector<Point> &a) {
    float temp = 0;
    for (int i = 0; i < a.size(); ++i) {
        temp += a[i % a.size()].getX() * a[(i + 1) % a.size()].getY() -
                a[(i + 1) % a.size()].getX() * a[i % a.size()].getY();
    }

    return abs(0.5 * temp);
}

float getPetimeter(const vector<Point> &a) {
    float temp = 0;
    for (int i = 1; i < a.size() + 1; ++i) {
        temp += sqrt(
                pow(a[(i - 1) % a.size()].getX() - a[i % a.size()].getX(), 2) +
                pow(a[(i - 1) % a.size()].getY() - a[i % a.size()].getY(), 2));
    }

    return temp;
}

bool isPolygonCorrect(std::vector<Point> v) {
    int leftRotation = 0, rightRotation = 0, line = 0;
    if (v.size() >= 3) { //åñëè òðåóãîëüíèê ÒÎÆÅ
        for (int i = 0; i < v.size(); ++i) {
            float result = vecCorrectness(v[i % v.size()].getX(), v[i % v.size()].getY(),
                                          v[(i + 1) % v.size()].getX(),
                                          v[(i + 1) % v.size()].getY(), v[(i + 2) % v.size()].getX(),
                                          v[(i + 2) % v.size()].getY());
            if (result == 0) {
                line++;
            } else if (result < 0) {
                rightRotation++;
            } else if (result > 0) {
                leftRotation++;
            }
        }

        if (leftRotation != 0 && rightRotation != 0 || line == v.size() || getSquare(v) == 0) {
            return false;
        } else return true;

    } else return false;
}

bool isTrapezoidCorrect(const vector<Point> &v) {
    int leftRotation = 0, rightRotation = 0, line = 0;
    vector<float> angles;
    if (v.size() == 4) {
        for (int i = 0; i < 4; ++i) {
            float result = vecCorrectness(v[i % v.size()].getX(), v[i % v.size()].getY(),
                                          v[(i + 1) % v.size()].getX(),
                                          v[(i + 1) % v.size()].getY(), v[(i + 2) % v.size()].getX(),
                                          v[(i + 2) % v.size()].getY());
            if (result == 0) {
                line++;
            } else if (result < 0) {
                rightRotation++;
            } else if (result > 0) {
                leftRotation++;
            }
            angles.emplace_back(angle(v[i % v.size()].getX(), v[i % v.size()].getY(),
                                      v[(i + 1) % v.size()].getX(),
                                      v[(i + 1) % v.size()].getY(), v[(i + 2) % v.size()].getX(),
                                      v[(i + 2) % v.size()].getY()));
        }

        //ïðîâåðêà íà òî, ÷òî çíà÷åíèÿ ïîïàðíî ðàâíû
        int equal = 0;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; j++) {
                if (angles[i] == angles[j])
                    equal++;
            }

        if (leftRotation != 0 && rightRotation != 0 || line == v.size() || getSquare(v) == 0) {
            return false;
        } else if (equal == 8 || equal == 16)
            return true;

    } else return false;
}

bool isRegularPolygonCorrect(const vector<Point> &v) {
    int leftRotation = 0, rightRotation = 0, line = 0;
    vector<float> angles;
    vector<float> vecLens;
    if (v.size() >= 3) {
        for (int i = 0; i < v.size(); ++i) {
            float result = vecCorrectness(v[i % v.size()].getX(), v[i % v.size()].getY(),
                                          v[(i + 1) % v.size()].getX(),
                                          v[(i + 1) % v.size()].getY(), v[(i + 2) % v.size()].getX(),
                                          v[(i + 2) % v.size()].getY());
            if (result == 0) {
                line++;
            } else if (result < 0) {
                rightRotation++;
            } else if (result > 0) {
                leftRotation++;
            }

            angles.emplace_back(angle(v[i % v.size()].getX(), v[i % v.size()].getY(),
                                      v[(i + 1) % v.size()].getX(),
                                      v[(i + 1) % v.size()].getY(), v[(i + 2) % v.size()].getX(),
                                      v[(i + 2) % v.size()].getY()));

            vecLens.emplace_back(vecLen(v[i % v.size()].getX(), v[i % v.size()].getY(),
                                        v[(i + 1) % v.size()].getX(),
                                        v[(i + 1) % v.size()].getY()));
        }

        //ïðîâåðêà íà òî, ÷òî âñå óãëû ðàâíû
        int equalAngles = 0;
        for (int i = 0; i < v.size(); ++i)
            for (int j = 0; j < v.size(); j++)
                if (angles[i] == angles[j])
                    equalAngles++;

        //ïðîâåðêà òîãî, ÷òî âñå äëèíû âåêòîðîâ ðàâíû
        int equalVecLens = 0;
        for (int i = 0; i < v.size(); ++i)
            for (int j = 0; j < v.size(); j++)
                if (vecLens[i] == vecLens[j])
                    equalVecLens++;

        if (leftRotation != 0 && rightRotation != 0 || line == v.size() || getSquare(v) == 0) {
            return false;
        } else if (equalVecLens == pow(v.size(), 2) && equalAngles == pow(v.size(), 2)) {
            return true;
        }

    } else return false;
}

#endif //__CALCULATIONS_H