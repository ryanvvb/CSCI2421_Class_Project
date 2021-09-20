//
// Created by Ryan Van Valkenburg on 9/16/21.
//
#include "Menu.h"
#include <fstream>
#include "ActorActress.h"
#include <vector>
#include "Pictures.h"
#include <iostream>
#include <string>
#include <sstream>
#ifndef CSCI2421_CLASS_PROJECT_DATABASELOOP_H
#define CSCI2421_CLASS_PROJECT_DATABASELOOP_H


class Database {
public:
    Database();
    void databaseLoop();
    void readActorFile();
    void readPicturesFile();
    void setaaHeader(string& h);
    void setPicsHeader(string& h);
    void printActorActressList();
    void printPicturesList();
    void outputAAList();
    void outputPicturesList();
    string getAAHeader();
    vector<ActorActress> getAAVector();
    vector<Pictures> getPicVector();

private:
    Menu databaseMenu = Menu();
    vector<ActorActress> aaVector;
    vector<Pictures> picVector;
    bool keepAsking = true;
    bool done = false;
    string aaHeader;
    string picsHeader;
    
};


#endif //CSCI2421_CLASS_PROJECT_DATABASELOOP_H
