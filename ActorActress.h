//
// Created by Ryan Van Valkenburg on 9/15/21.
//
#include <iostream>
#include <string>
using namespace std;
#ifndef CSCI2421_CLASS_PROJECT_ACTORACTRESS_H
#define CSCI2421_CLASS_PROJECT_ACTORACTRESS_H


class ActorActress {
public:
    ActorActress();
    ActorActress(string& nme, string& flm, int yr, string& awrd, int win);
private:
    string name;
    string film;
    int year;
    string award;
    int winner;
};


#endif //CSCI2421_CLASS_PROJECT_ACTORACTRESS_H
