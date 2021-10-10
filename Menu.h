//
// Created by Ryan Van Valkenburg on 9/16/21.
//
#include <iostream>
using namespace std;
#ifndef CSCI2421_CLASS_PROJECT_MENU_H
#define CSCI2421_CLASS_PROJECT_MENU_H


class Menu {
public:
    Menu();
    void displayMenu();
private:
    string a = "1. Read in actor-actress data file and add to actor-actress list";
    string b = "2. Read in pictures data file and add to pictures list";
    string c = "3. Save the actor-actress list into a csv file";
    string d = "4. Save the pictures list into a csv file";
    string e = "5. Add an actor-actress object to list";
    string f = "6. Add a picture object to list";
    string g = "7. Display the actor-actress list to the screen";
    string h = "8. Display the pictures list to the screen";
    string x = "9. Quit";
};


#endif //CSCI2421_CLASS_PROJECT_MENU_H
