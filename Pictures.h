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
    Pictures(string& nme, int yr, string& noms, float rate, int dur, string& g1, string& g2, string& rel,
             int meta, string& syn);
private:
    string name;
    int year;
    string nominations;
    float rating;
    int duration;
    string genre1;
    string genre2;
    string release;
    int metacritic;
    string synopsis;

};


#endif //CSCI2421_CLASS_PROJECT_PICTURES_H
