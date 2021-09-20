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
        cout << "\nPlease select a menu option: "; // Currently does not handle invalid type input
        cin >> selection;

        switch(selection){
            case 1:
                readActorFile();
                break;
            case 2:
                readPicturesFile();
                break;
            case 3:
                outputAAList();
                break;
            case 4:
                outputPicturesList();
                break;
            case 5:
                printActorActressList();
                break;
            case 6:
                printPicturesList();
                break;
            case 7:
                cout << "Exiting program" << endl;
                this->done = true;
                break;
            default:
                cout << "Selection Error: Invalid option, enter a new selection\n";
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
    string head;
    string year, award, name, film, win;

    cout << "Enter the name of the csv file containing a list of actors and actresses: ";
    cin >> filename;

    inFile.open(filename);
    if(!inFile){
        cout << "Invalid file name, returning to main menu" << endl;
        return;
    }
    getline(inFile, head);
    this->setaaHeader(head);
    while(!inFile.eof()){
        getline(inFile, year, ',');
        getline(inFile, award, ',');
        getline(inFile, win, ',');
        getline(inFile, name, ',');
        getline(inFile, film);

        ActorActress aa = ActorActress(name, film, year, award, win);
        aaVector.push_back(aa);
    }
    cout << "Data successfully read in from " << filename << endl;
    inFile.close();
}
/***
 * Prompt the user for a file name to open and read data from
 * The data is parsed and separated by commas in the csv file and organized in such a way that the function can
 * loop through the entire file consistently
 * The data is used to generate an ActorActress object with the matching data and stores the object in a vector
 */
void Database::readPicturesFile() {
    ifstream inFile;
    string filename;
    string head, name, year, nominations, rating, duration, genre1, genre2, release, meta, synopsis;

    cout << "Please enter the name of a csv file containing the name of a list of motion pictures: ";
    cin >> filename;

    inFile.open(filename);
    if(!inFile){
        cout << "Invalid file name, returning to main menu" << endl;
        return;
    }
    getline(inFile, head);
    this->setPicsHeader(head);
    while(!inFile.eof()){
        getline(inFile, name, ',');
        getline(inFile, year, ',');
        getline(inFile, nominations, ',');
        getline(inFile, rating, ',');
        getline(inFile, duration, ',');
        getline(inFile, genre1, ',');
        getline(inFile, genre2, ',');
        getline(inFile, release, ',');
        getline(inFile, meta, ',');
        getline(inFile, synopsis);

        Pictures pic = Pictures(name, year, nominations, rating, duration,
                                genre1, genre2, release, meta, synopsis);
        picVector.push_back(pic);
    }
    cout << "Data successfully read in from "  << filename << endl;
    inFile.close();
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
/***
 * Sets the Pictures Header to the string h
 * @param h
 */
void Database::setPicsHeader(string& h) {
    picsHeader = h;
}
/***
 * Sets the Actor Actress Header to the string h
 * @param h
 */
void Database::setaaHeader(string& h) {
    aaHeader = h;
}
/***
 * Prints out the column list header followed by every element of the actor actress list on its own line
 */
void Database::printActorActressList() {
    if(this->aaVector.empty()){
        cout << "No file input has been read, please read in data before attempting to output" << endl;
        return;
    }
    cout << this->aaHeader << endl;
    for (auto &i: this->aaVector)cout << i << endl;
}
string Database::getAAHeader() {
    return aaHeader;
}
/***
 * Prints out the column list header followed by every element of the actor actress list on its own line
 */
void Database::printPicturesList() {
    if(this->picVector.empty()){
        cout << "No file input has been read, please read in data before attempting to output" << endl;
        return;
    }
    cout << this->picsHeader << endl;
    for (auto &i: this->picVector)cout << i << endl;
}

void Database::outputAAList() {
    if(this->aaVector.empty()){
        cout << "No file input has been read, please read in data before attempting to write to file" << endl;
        return;
    }

    ofstream outFile;
    string filename;

    cout << "Enter the name of a file to save the Actor-Actress list to: ";
    cin >> filename;

    outFile.open(filename);
    outFile << this->aaHeader << endl;
    for(auto & i: aaVector)outFile << i << endl;
    outFile.close();
}

void Database::outputPicturesList() {
    if(this->picVector.empty()){
        cout << "No file input has been read, please read in data before attempting to write to file" << endl;
        return;
    }

    ofstream outFile;
    string filename;

    cout << "Enter the name of a file to save the Motion Pictures list to: ";
    cin >> filename;

    outFile.open(filename);
    outFile << this->picsHeader << endl;
    for(auto & i: picVector)outFile << i << endl;
    outFile.close();
}


