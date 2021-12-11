//
// Created by Ryan Van Valkenburg on 9/16/21.
//
#include "Menu.h"
#include "ActorActress.h"
#include "Pictures.h"
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#ifndef CSCI2421_CLASS_PROJECT_DATABASELOOP_H
#define CSCI2421_CLASS_PROJECT_DATABASELOOP_H


class Database {
public:
    Database();
    static bool compareAAName(ActorActress lhs, ActorActress rhs);
    static bool compareAAAward(ActorActress lhs, ActorActress rhs);
    static bool comparePicturesName(Pictures lhs, Pictures rhs);
    static bool comparePicturesGenre(Pictures lhs, Pictures rhs);
    void databaseLoop();
    void readActorFile();
    void readPicturesFile();
    void setaaHeader(string& h);
    void setPicsHeader(string& h);
    void printActorActressList();
    void printPicturesList();
    void outputAAList();
    void outputPicturesList();
    void addActorActress();
    void addPicture();
    void searchActorActress();
    void searchPictures();
    void sortActorActress();
    void sortPictures();
    void editActorActress(vector<ActorActress*> & aa);
    void editPicture(vector<Pictures*> & pics);
    string selectAwardActorActress();
    string selectCategoryPictures();
    string getAAHeader();
    vector<ActorActress> getAAVector();
    vector<Pictures> getPicVector();
    vector<ActorActress*> databaseAwardSearch(vector<ActorActress> & arr, string & key);
    vector<Pictures*> databaseGenreSearch(vector<Pictures> & arr, string & key);

    template<typename Object>
    vector<Object*> databaseNameSearch(vector<Object> & arr, string & key){
        vector<Object*> returnVector;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i].getName().find(key) != string::npos){
                Object *obj;
                obj = &arr[i];
                returnVector.push_back(obj);
            }
        }
        return returnVector;
    }

    template<typename Object>
    void printSearchResults(vector<Object*> & arr, string & header){
        int counter = 0;
        cout << header << endl;
        for(auto & i : arr){
            cout << counter << ". ";
            cout << *i << endl;
            counter++;
        }
    }
private:
    Menu databaseMenu = Menu();
    vector<ActorActress> aaVector;
    vector<Pictures> picVector;
    vector<ActorActress> aaSearchResults;
    vector<Pictures> picSearchResults;
    bool done = false;
    string aaHeader;
    string picsHeader;
};

#endif //CSCI2421_CLASS_PROJECT_DATABASELOOP_H
