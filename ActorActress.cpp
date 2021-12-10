//
// Created by Ryan Van Valkenburg on 9/15/21.
//

#include "ActorActress.h"
/**
 * Default Constructor
 */
ActorActress::ActorActress(){
    name = "";
    film = "";
    year = "";
    award = "";
    winner = "";
}
/***
 * Five parameter constructor
 * @param nme name of the actor or actress
 * @param flm name of the film
 * @param yr year the film was released
 * @param awrd award nominated for
 * @param win 1 if they won the award 0 if they did not
 */
ActorActress::ActorActress(string& nme, string& flm, string& yr, string& awrd, string& win){
    name = nme;
    film = flm;
    year = yr;
    award = awrd;
    winner = win;
}
/***
 * Overoaded out operator for ActorActress object
 * @param out
 * @param aa
 * @return
 */
ostream &operator<<(ostream &out, const ActorActress &aa) {
    out << aa.year << "," << aa.award << "," << aa.winner << "," << aa.name << "," << aa.film;
    return out;
}

string ActorActress::getName() {
    return name;
}

string ActorActress::getFilm() {
    return film;
}

string ActorActress::getYear() {
    return year;
}

string ActorActress::getAward() {
    return award;
}

string ActorActress::getWinner() {
    return winner;
}

void ActorActress::setName(string& n) {
    name = n;
}

void ActorActress::setFilm(string &f) {
    film = f;
}

void ActorActress::setYear(string &y) {
    year = y;
}

void ActorActress::setAward(string &a) {
    award = a;
}

void ActorActress::setWinner(string &w) {
    winner = w;
}
