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
