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
    ActorActress(string& nme, string& flm, string& yr, string& awrd, string& win);
    string getName();
    string getFilm();
    string getYear();
    string getAward();
    string getWinner();
    void setName(string& n);
    void setFilm(string& f);
    void setYear(string& y);
    void setAward(string& a);
    void setWinner(string& w);
    friend ostream &operator << (ostream &out, const ActorActress &aa);
private:
    string name;
    string film;
    string year;
    string award;
    string winner;
};


#endif //CSCI2421_CLASS_PROJECT_ACTORACTRESS_H
