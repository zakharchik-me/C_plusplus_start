#ifndef __LLINE_H
#define __LLINE_H


class ChainedBrokenLine : public BrokenLine {
public:
    ChainedBrokenLine() {
#ifdef COMMENTS
        cout << "Chained broken line been successfully created" << endl;
#endif //COMMENTS
    }

    [[maybe_unused]] explicit ChainedBrokenLine(const vector<Point> &m) {
        if (m.size() >= 3 && getSquare(m) != 0) {
            this->BLVect = m;
#ifdef COMMENTS
            cout << endl << "Congrats! Broken line (Chained broken line) has been successfully created!" << endl;
#endif //COMMENTS
        } else cout << "Sorry, it's not a chained broken line" << endl;
    }

    ChainedBrokenLine &operator=(const ChainedBrokenLine &t) {
        this->BLVect.resize(0);
        for (auto const &elem : t.BLVect)
            this->BLVect.emplace_back(elem);
#ifdef COMMENTS
        cout << "Operator =" << endl;
#endif //COMMENTS

        return *this;
    }

    float length() override {
        return getPetimeter(this->BLVect);
    }

    ~ChainedBrokenLine() {
#ifdef COMMENTS
        cout << "Chained broken line died" << endl;
#endif
    }

};

#endif //__CHAINEDBROKENLINE_H