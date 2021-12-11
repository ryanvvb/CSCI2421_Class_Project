//
// Created by Ryan Van Valkenburg on 9/15/21.
//

#include "Pictures.h"
/***
 * Default constructor
 */
Pictures::Pictures() {
    name = "";
    year = "";
    nominations = "";
    rating = "";
    duration = "";
    genre1 = "";
    genre2 = "";
    release = "";
    metacritic = "";
    synopsis = "";
}
/***
 * 10 parameter constructor for Pictures object
 * @param nme name of the movie
 * @param yr year the film was released
 * @param noms award nominations
 * @param rate rating
 * @param dur duration of film
 * @param g1 genre 1
 * @param g2 genre 2
 * @param rel release month
 * @param meta metacritic score
 * @param syn synopsis
 */
Pictures::Pictures(string& nme, string& yr, string& noms, string& rate, string& dur, string& g1, string& g2, string& rel,
                   string& meta, string& syn) {
    name = nme;
    year = yr;
    nominations = noms;
    rating = rate;
    duration = dur;
    genre1 = g1;
    genre2 = g2;
    release = rel;
    metacritic = meta;
    synopsis = syn;

}/***
 * Overloaded out operator for Pictures object
 * @param out
 * @param p
 * @return
 */
ostream &operator<<(ostream &out, const Pictures &p) {
    out << p.name << "," << p.year << "," << p.nominations << "," << p.rating << "," << p.duration << "," << p.genre1 <<
    "," << p.genre2 << "," << p.release << "," << p.metacritic << "," << p.synopsis;
    return out;
}

string Pictures::getName() {
    return name;
}

string Pictures::getYear() {
    return year;
}

string Pictures::getNom() {
    return nominations;
}

string Pictures::getRating() {
    return rating;
}

string Pictures::getDuration() {
    return duration;
}

string Pictures::getGenre1() {
    return genre1;
}

string Pictures::getGenre2() {
    return genre2;
}

string Pictures::getRelease() {
    return release;
}

string Pictures::getMetacritic() {
    return metacritic;
}

string Pictures::getSynopsis() {
    return synopsis;
}

void Pictures::setName(string &n) {
    name = n;
}

void Pictures::setYear(string &y) {
    year = y;
}

void Pictures::setNom(string &n) {
    nominations = n;
}

void Pictures::setRating(string &r) {
    rating = r;
}

void Pictures::setGenre1(string &g1) {
    genre1 = g1;
}

void Pictures::setGenre2(string &g2) {
    genre2 = g2;
}

void Pictures::setRelease(string &r) {
    release = r;
}

void Pictures::setMetacritic(string &m) {
    metacritic = m;
}

void Pictures::setSynopsis(string &s) {
    synopsis = s;
}

void Pictures::setDuration(string &d) {
    duration = d;
}
