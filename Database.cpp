//
// Created by Ryan Van Valkenburg on 9/16/21.
//

#include "Database.h"

Database::Database() = default;
/***
 * Display the menu and prompt the user for a response
 * The menu will continue to display after each option function has executed until the user quits the program
 * The user's response will determine which functions are executed
 */
void Database::databaseLoop() {
    int selection;
    while(!done){
        this->databaseMenu.displayMenu();
        cout << "\nPlease select a menu option: ";
        cin >> selection;

        switch(selection){
            case 1:
                readActorFile();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                cout << "Exiting program" << endl;
                this->done = true;
                break;
            default:
                cout << "Selection Error: Invalid option, enter a new selection: ";
                cin >> selection;
                continue;
        }
    }
}
/***
 * Prompt the user for a file name to open and read data from
 * The data is parsed and separated by commas in the csv file and organized in such a way that the function can
 * loop through the entire file consistently
 * The data is used to generate an ActorActress object with the matching data and stores the object in a vector
 */
void Database::readActorFile() {
    ifstream inFile;
    string filename;
    cout << "Enter the name of the csv file containing a list of actors and actresses: ";
    cin >> filename;

    string discard;
    int year, win;
    string tempYear, tempWin;
    string award, name, film;

    inFile.open(filename);
    if(!inFile){
        cout << "Invalid file name, returning to main menu" << endl;
        return;
    }
    getline(inFile, discard);
    while(!inFile.eof()){

        getline(inFile, tempYear, ',');
        year = stoi(tempYear);
        getline(inFile, award, ',');
        getline(inFile, tempWin, ',');
        win = stoi(tempWin);
        getline(inFile, name, '.');
        getline(inFile, film, ',');

        ActorActress aa = ActorActress(name, film, year, award, win);
        aaVector.push_back(aa);
    }

}
/***
 * Returns the pictures vector
 * @return
 */
vector<Pictures> Database::getPicVector() {
    return picVector;
}

/***
 * Returns the actor actress vector
 * @return
 */
vector<ActorActress> Database::getAAVector() {
    return aaVector;
}
