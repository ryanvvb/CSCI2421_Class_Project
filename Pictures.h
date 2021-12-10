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
    string getName();
    string getYear();
    string getNom();
    string getRating();
    string getDuration();
    string getGenre1();
    string getGenre2();
    string getRelease();
    string getMetacritic();
    string getSynopsis();
    void setName(string& n);
    void setYear(string& y);
    void setNom(string& n);
    void setRating(string& r);
    void setGenre1(string& g1);
    void setGenre2(string& g2);
    void setRelease(string& r);
    void setMetacritic(string& m);
    void setSynopsis(string& s);
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
