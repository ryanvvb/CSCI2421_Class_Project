//
// Created by Ryan Van Valkenburg on 9/15/21.
//

#include "Pictures.h"

Pictures::Pictures() {

}
Pictures::Pictures(string& nme, int yr, string& noms, float rate, int dur, string& g1, string& g2, string& rel,
                   int meta, string& syn) {
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

}
