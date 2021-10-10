//
// Created by Ryan Van Valkenburg on 9/15/21.
//
#include <iostream>
#include <string>
using namespace std;
#ifndef CSCI2421_CLASS_PROJECT_PICTURES_H
#define CSCI2421_CLASS_PROJECT_PICTURES_H


class Pictures {
public:
    Pictures();
    Pictures(string& nme, string& yr, string& noms, string& rate, string& dur, string& g1, string& g2, string& rel,
             string& meta, string& syn);
    friend ostream &operator << (ostream &out, const Pictures &p);
private:
    string name;
    string year;
    string nominations;
    string rating;
    string duration;
    string genre1;
    string genre2;
    string release;
    string metacritic;
    string synopsis;
};

#endif //CSCI2421_CLASS_PROJECT_PICTURES_H
