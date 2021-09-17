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
    year = 0;
    award = "";
    winner = 0;
}
/***
 * Five parameter constructor
 * @param nme name of the actor or actress
 * @param flm name of the film
 * @param yr year the film was released
 * @param awrd award nominated for
 * @param win 1 if they won the award 0 if they did not
 */
ActorActress::ActorActress(string& nme, string& flm, int yr, string& awrd, int win){
    name = nme;
    film = flm;
    year = yr;
    award = awrd;
    winner = win;
}
