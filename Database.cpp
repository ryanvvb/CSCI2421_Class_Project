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
                readPicturesFile();
                break;
            case 3:
                outputAAList();
                break;
            case 4:
                outputPicturesList();
                break;
            case 5:
                addActorActress();
                break;
            case 6:
                addPicture();
                break;
            case 7:
                printActorActressList();
                cout << endl;
                break;
            case 8:
                printPicturesList();
                cout << endl;
                break;
            case 9:
                searchActorActress();
                break;
            case 10:
                searchPictures();
                break;
            case 11:
                sortActorActress();
                break;
            case 12:
                sortPictures();
                break;
            case 13:
                cout << "Exiting program" << endl;
                this->done = true;
                break;
            default:
                cout << "Selection Error: Invalid option, enter a new selection\n";
                cin.clear();
                string throwaway;
                getline(cin, throwaway);
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

    // Read the file line by line and save each value to its corresponding variable
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

        // Create a new ActorActress object with the data read from current line of input file
        // and push to the back of the vector
        ActorActress aa = ActorActress(name, film, year, award, win);
        aaVector.push_back(aa);
    }
    cout << "Data successfully read in from " << filename << endl;
    cout << endl;
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

    // Read the file line by line and save each value to its corresponding variable
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

        // Create a new Pictures object with data from current line of the input file and push to the back of the vector
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
/***
 * return the aaHeader
 * @return aaHeader line from input file
 */
string Database::getAAHeader() {
    return aaHeader;
}
/***
 * Prints out the column list header followed by every element of the pictures list on its own line
 */
void Database::printPicturesList() {
    if(this->picVector.empty()){
        cout << "No file input has been read, please read in data before attempting to output" << endl;
        return;
    }
    cout << this->picsHeader << endl;
    for (auto &i: this->picVector)cout << i << endl;
}
/***
 * Prints out the column list header followed by every element of the actor actress list on its own line
 * In a file the user enters as an input
 */
void Database::outputAAList() {
    if(this->aaVector.empty()){
        cout << "No file input has been read, please read in data before attempting to write to file" << endl;
        return;
    }

    ofstream outFile;
    string filename;

    cout << "Enter the name of a file to save the Actor-Actress list to: ";
    cin >> filename;

    // Open the output file if it exists, if it does not, create the file for output
    outFile.open(filename);
    outFile << this->aaHeader << endl;
    // Output each object from the aaVector as one line of output in the file
    for(auto & i: aaVector)outFile << i << endl;
    outFile.close();
}

/***
 * Prints out the column list header followed by every element of the pictures list on its own line
 * In a file the user enters as an input
 */
void Database::outputPicturesList() {
    if(this->picVector.empty()){
        cout << "No file input has been read, please read in data before attempting to write to file" << endl;
        return;
    }

    ofstream outFile;
    string filename;

    cout << "Enter the name of a file to save the Motion Pictures list to: ";
    cin >> filename;

    // Open the output file if it exists, if it does not, create the file for output
    outFile.open(filename);
    outFile << this->picsHeader << endl;
    // Output each object from the picsVector as one line of output in the file
    for(auto & i: picVector)outFile << i << endl;
    outFile.close();
}

/***
 * Prompts the user for all the necessary parameters to create a new ActorActress object and adds it to the list
 */
void Database::addActorActress() {
    string nme, yr, awrd, wn, flm;
    try {
        cout << "Enter the name of an actor or actress: ";
        cin.ignore();
        getline(cin, nme);

        cout << "Enter the name of the film the actor or actress was in: ";
        getline(cin, flm);

        cout << "Enter the year the film was released: ";
        getline(cin, yr);
        int y = stoi(yr);
        if (y < 0) {
            throw (y);
        }

        cout << "Enter the award the actor or actress was nominated for: ";
        getline(cin, awrd);

        cout << "Enter a 1 if the actor or actress won the award they were nominated for or a 0 if they did not: ";
        getline(cin, wn);
        int w = stoi(wn);
        if (w > 1 or w < 0) {
            throw (w);
        }
    }
    // If the user enters an improper type as input invalid_argument exception will be thrown and caught here
    // Invalid input will result in the function terminating and returning to the menu
    catch(invalid_argument&){
        cout << "Invalid argument, a numerical value must be entered" << endl;
        return;
    }
    // If the user enters a negative value, the input will be thrown and caught here
    // Negative input values will result in the function terminating and returning to the menu
    catch(int e){
        cout << e << " not within valid input range" << endl;
        return;
    }
    ActorActress aa(nme, flm, yr, awrd, wn);
    this->aaVector.push_back(aa);
}

/***
 * Prompts the user for all the necessary parameters to create a new Pictures object and adds it to the list
 */
void Database::addPicture() {
    string nme, yr, noms, rate, dur, g1, g2, rel, meta, syn;
    try {
        cout << "Enter the name of a film you would like to enter: ";
        cin.ignore();
        getline(cin, nme);

        cout << "Enter the year the film was released: ";
        getline(cin, yr);
        int y = stoi(yr);
        if (y < 0){
            throw(y);
        }

        cout << "Enter the number of nominations the film received: ";
        getline(cin, noms);
        int n = stoi(noms);
        if (n < 0){
            throw(n);
        }

        cout << "Enter the numerical rating of the film: ";
        getline(cin, rate);
        float r = stof(rate);
        if (r < 0){
            throw(r);
        }

        cout << "Enter the duration of the film in minutes: ";
        getline(cin, dur);
        int d = stoi(dur);
        if (d < 0){
            throw(d);
        }

        cout << "Enter the primary genre of the film: ";
        getline(cin, g1);

        cout << "Enter the secondary genre of the film: ";
        getline(cin, g2);

        cout << "Enter the name of the month of the film's release: ";
        getline(cin, rel);

        cout << "Enter the metacritic score for the film: ";
        getline(cin, meta);
        int m = stoi(meta);
        if (m < 0){
            throw(m);
        }

        cout << "Enter the synopsis of the film: ";
        getline(cin, syn);
    }
    // If the user enters an improper type as input invalid_argument exception will be thrown and caught here
    // Invalid input will result in the function terminating and returning to the menu
    catch(invalid_argument&){
        cout << "Invalid argument, a numerical value must be entered" << endl;
        return;
    }
    // If the user enters a negative value, the input will be thrown and caught here
    // Negative input values will result in the function terminating and returning to the menu
    catch(int e){
        cout << e << " not a valid input.  Input must be a non-negative numerical value" << endl;
        return;
    }
    // If the user enters a negative value, the input will be thrown and caught here
    // Negative input values will result in the function terminating and returning to the menu
    catch(float e){
        cout << e << " not a valid input.  Input must be a non-negative numerical value" << endl;
        return;
    }
    Pictures pic(nme, yr, noms, rate, dur, g1, g2, rel, meta, syn);
    picVector.push_back(pic);
}
/**
 * Search the actor actress vector based on name or award nomination
 * The user selects the search type from a menu and enters the value to search for
 * A vector of pointers pointing to the original objects is created and used to make edits to those objects
 */
void Database::searchActorActress() {
    int selection;
    bool menu_loop = true;
    string search_key;
    string narrow_results;
    vector<ActorActress*> searchResults;

    while(menu_loop) {
        // User selects a search criteria
        cout << "Search categories" << endl;
        cout << "1. Name" << endl;
        cout << "2. Award" << endl;
        cout << "3. Return to main menu" << endl;
        cout << "Please enter a number to select a search criteria: ";
        cin >> selection;
        // As long as the user has not selected menu option 3, the loop will continue

        switch(selection){
            // The list is sorted by name alphabetically and the user enters a name to search for
            // A vector of pointers that point to the original objects in the database is created and used to edit
            case 1:
                sort(aaVector.begin(), aaVector.end(), compareAAName);
                cout << "Enter the name of an actor or actress to look up: ";
                cin.ignore();
                getline(cin, search_key);
                searchResults = databaseNameSearch(aaVector, search_key);
                editActorActress(searchResults);
                break;
            case 2:
                sort(aaVector.begin(), aaVector.end(), compareAAAward);
                search_key = selectAwardActorActress();
                searchResults = databaseAwardSearch(aaVector, search_key);
                editActorActress(searchResults);
                break;
            case 3:
                menu_loop = false;
                break;
            default:
                cout << "Selection error; please enter a valid menu selection" << endl;
                cin.clear();
                string throwaway;
                getline(cin, throwaway);
        }
    }

}
/**
 * Search the actor actress vector based on name or primary genre
 * The user selects the search type from a menu and enters the value to search for
 * A vector of pointers pointing to the original objects is created and used to make edits to those objects
 */
void Database::searchPictures() {
    int selection;
    string search_key;
    bool menu_loop = true;
    vector<Pictures*> searchResults;


    while(menu_loop){
        cout << "Search categories" << endl;
        cout << "1. Film Name" << endl;
        cout << "2. Genre" << endl;
        cout << "3. Return to main menu" << endl;
        cout << "Please enter a number to select a search criteria: ";
        cin >> selection;

        switch(selection){
            case 1:
                sort(picVector.begin(), picVector.end(), comparePicturesName);
                cin.ignore();
                cout << "Enter the name of a film to look up: ";
                getline(cin, search_key);
                searchResults = databaseNameSearch(picVector, search_key);
                printSearchResults(searchResults, picsHeader);
                break;
            case 2:
                sort(picVector.begin(), picVector.end(), comparePicturesGenre);
                search_key = selectCategoryPictures();
                searchResults = databaseGenreSearch(picVector, search_key);
                printSearchResults(searchResults, picsHeader);
                break;
            case 3:
                menu_loop = false;
                break;
            default:
                cout << "Selection error; please enter a valid menu selection" << endl;
                cin.clear();
                string throwaway;
                getline(cin, throwaway);
        }
    }

}
/**
 * Displays a list of away categories the user can select
 * @return searchCriteria of the award category as a string used to search the vector for matching actors or actresses
 */
string Database::selectAwardActorActress() {
    string actorL = "Actor in a Leading Role";
    string actressL = "Actress in a Leading Role";
    string actorS = "Actor in a Supporting Role";
    string actressS = "Actress in a Suppprting Role";
    int selection;
    string searchCriteria;

    cout << "You may select from the following categories" << endl;
    cout << "1. " << actorL << endl;
    cout << "2. " << actressL << endl;
    cout << "3. " << actorS << endl;
    cout << "4. " << actressS << endl;
    cout << "Enter the number of your selection: ";
    cin >> selection;

    // User input determines the string value of searchCriteria which is returned
    switch(selection){
        case 1:
            searchCriteria = actorL;
            break;
        case 2:
            searchCriteria = actressL;
            break;
        case 3:
            searchCriteria = actorS;
            break;
        case 4:
            searchCriteria = actressS;
            break;
        default:
            cout << "Please enter a valid menu selection" << endl;
            cin.clear();
            string throwaway;
            getline(cin, throwaway);
            break;
    }
    return searchCriteria;
}
/**
 * Displays a list of genres the user can select to use as a search criteria
 * @return searchCriteria string value to search the vector for matching films
 */
string Database::selectCategoryPictures() {
    int selection;
    string searchCriteria;
    string drama = "Drama";
    string bio = "Biography";
    string adv = "Adventure";
    string com = "Comedy";
    string wes = "Western";
    string mus = "Musical";
    string crime = "Crime";

    cout << "You may select from the following genre categories" << endl;
    cout << "1. " << drama << endl;
    cout << "2. " << bio << endl;
    cout << "3. " << adv << endl;
    cout << "4. " << com << endl;
    cout << "5. " << wes << endl;
    cout << "6. " << mus << endl;
    cout << "7. " << crime;

    cout << "Enter a search category: ";
    cin >> selection;
    // User input determines the string value of searchCriteria which is returned
    switch(selection){
        case 1:
            searchCriteria = drama;
            break;
        case 2:
            searchCriteria = bio;
            break;
        case 3:
            searchCriteria = adv;
            break;
        case 4:
            searchCriteria = com;
            break;
        case 5:
            searchCriteria = wes;
            break;
        case 6:
            searchCriteria = mus;
            break;
        case 7:
            searchCriteria = crime;
            break;
        default:
            cout << "Enter a valid search category";
            cin.clear();
            string throwaway;
            getline(cin, throwaway);
    }
    return searchCriteria;
}
/**
 * Sorts the Actor Actress vector in alphabetical name order or by the award nomination category
 * The user enters a number corresponding to their selection and a quick sort is performed on the vector
 */
void Database::sortActorActress() {
    int selection;
    bool menu_loop = true;

    // The user selects their sport preference from a menu and the sort is performed
    cout << "1. Actor or Actress name in alphabetical order" << endl;
    cout << "2. Award Nomination Category" << endl;
    while(menu_loop) {
        cout << "Define the sorting category for the Actor-Actress list, enter the corresponding number: ";
        cin >> selection;
        switch(selection) {
            case 1:
                sort(aaVector.begin(), aaVector.end(), compareAAName);
                menu_loop = false;
                break;
            case 2:
                sort(aaVector.begin(), aaVector.end(), compareAAAward);
                menu_loop = false;
                break;
            default:
                cout << "Selection error; please enter a valid menu selection" << endl;
                cin.clear();
                string throwaway;
                getline(cin, throwaway);
        }
    }
}
/**
 * Sorts the Pictures vector based on either alphabetical name order or by the primary genre
 * The user enters a number corresponding to their selection and a quick sort is performed on the vector
 */
void Database::sortPictures() {
    int selection;
    bool menu_loop = true;

    // The user selects their sort preference from a menu and the sort is performed
    cout << "1. Picture name in alphabetical order" << endl;
    cout << "2. Picture genre Category" << endl;
    while(menu_loop) {
        cout << "Define the sorting category for the Pictures list, enter the corresponding number: ";
        cin >> selection;
        switch(selection) {
            case 1:
                sort(picVector.begin(), picVector.end(), comparePicturesName);
                menu_loop = false;
                break;
            case 2:
                sort(picVector.begin(), picVector.end(), comparePicturesGenre);
                menu_loop = false;
                break;
            default:
                cout << "Selection error; please enter a valid menu selection" << endl;
                cin.clear();
                string throwaway;
                getline(cin, throwaway);
        }
    }
}

vector<ActorActress*> Database::databaseAwardSearch(vector<ActorActress> &arr, string &key) {
    vector<ActorActress*> aa;
    for(auto & i : arr){
        if(i.getAward() == key){
            ActorActress *a;
            a = &i;
            aa.push_back(a);
        }
    }
    return aa;
}

vector<Pictures*> Database::databaseGenreSearch(vector<Pictures> &arr, string &key) {
    vector<Pictures*> pic;
    for(auto & i : arr){
        if(i.getGenre1() == key){
            Pictures *p;
            p = &i;
            pic.push_back(p);
        }
    }
    return pic;
}


bool Database::compareAAName(ActorActress lhs, ActorActress rhs) {
    return lhs.getName() < rhs.getName();
}

bool Database::compareAAAward(ActorActress lhs, ActorActress rhs) {
    return lhs.getAward() < rhs.getAward();
}

bool Database::comparePicturesName(Pictures lhs, Pictures rhs) {
    return lhs.getName() < rhs.getName();
}

bool Database::comparePicturesGenre(Pictures lhs, Pictures rhs) {
    return lhs.getGenre1() < rhs.getGenre1();
}
void Database::editActorActress(vector<ActorActress *> & aa) {
    int aa_selection;
    int cat_selection;
    string input;

    cout << "Choose one of the following actor or actresses to edit: " << endl;
    printSearchResults(aa, aaHeader);
    cout << "Enter selection: ";
    cin >> aa_selection;

    while (cat_selection != 0) {
        cout << "Choose from one of the following categories to edit" << endl;
        cout << "1. Name" << endl;
        cout << "2. Film" << endl;
        cout << "3. Year" << endl;
        cout << "4. Award" << endl;
        cout << "5. Winner" << endl;
        cout << "0. Done editing" << endl;

        cout << "Enter selection: ";
        cin >> cat_selection;
        switch(cat_selection){
            case 0:
                cout << "Done editing" << endl;
                break;
            case 1:
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, input);
                aa[aa_selection]->setName(input);
                break;
            case 2:
                cout << "Enter film name: ";
                cin.ignore();
                getline(cin, input);
                aa[aa_selection]->setFilm(input);
                break;
            case 3:
                cout << "Enter year of film release: ";
                cin.ignore();
                getline(cin, input);
                aa[aa_selection]->setYear(input);
                break;
            case 4:
                cout << "Enter the award this actor or actress was nominated for: ";
                cin.ignore();
                getline(cin, input);
                aa[aa_selection]->setAward(input);
                break;
            case 5:
                cout << "Enter a 0 or 1 if the actor or actress did not win or won the award respectively: ";
                cin.ignore();
                getline(cin, input);
                aa[aa_selection]->setWinner(input);
                break;
            default:
                cout << "Selection invalid; please enter a valid menu selection" << endl;
                cin.clear();
                string throwaway;
                getline(cin, throwaway);
        }
    }
}

void Database::editPicture(vector<Pictures *> & pics) {
    int pic_selection;
    int cat_selection;
    string input;

    cout << "Please select one of the following films to edit" << endl;
    printSearchResults(pics, picsHeader);
    cout << "Enter selection: ";
    cin >> pic_selection;

    while(cat_selection != 0){
        cout << "Select from one of the following categories to edit" << endl;
        cout << "1. Name" << endl;
        cout << "2. Year" << endl;
        cout << "3. Nominations" << endl;
        cout << "4. Rating" << endl;
        cout << "5. Duration" << endl;
        cout << "6. Primary Genre" << endl;
        cout << "7. Secondary Genre" << endl;
        cout << "8. Release" << endl;
        cout << "9. Metacritic Rating" << endl;
        cout << "10. Synopsis" << endl;
        cout << "0. Done Editing" << endl;

        cout << "Enter selection: ";
        cin >> cat_selection;
        switch(cat_selection){
            case 0:
                cout << "Done editing" << endl;
                break;
            case 1:
                cout << "Enter film name: ";
                cin.ignore();
                getline(cin, input);
                pics[pic_selection]->setName(input);
                break;
            case 2:
                cout << "Enter year: ";
                cin.ignore();
                getline(cin, input);
                pics[pic_selection]->setYear(input);
                break;
            case 3:
                cout << "Enter number of nominations: ";
                cin.ignore();
                getline(cin, input);
                pics[pic_selection]->setNom(input);
                break;
            case 4:
                cout << "Enter rating: ";
                cin.ignore();
                getline(cin, input);
                pics[pic_selection]->setRating(input);
                break;
            case 5:
                cout << "Enter duration: ";
                cin.ignore();
                getline(cin, input);
                pics[pic_selection]->setDuration(input);
                break;
            case 6:
                cout << "Enter primary genre: ";
                cin.ignore();
                getline(cin, input);
                pics[pic_selection]->setGenre1(input);
                break;
            case 7:
                cout << "Enter secondary genre";
                cin.ignore();
                getline(cin, input);
                pics[pic_selection]->setGenre2(input);
                break;
            case 8:
                cout << "Enter release: ";
                cin.ignore();
                getline(cin, input);
                pics[pic_selection]->setRelease(input);
                break;
            case 9:
                cout << "Enter Metacritic rating: ";
                cin.ignore();
                getline(cin, input);
                pics[pic_selection]->setMetacritic(input);
                break;
            case 10:
                cout << "Enter synopsis: ";
                cin.ignore();
                getline(cin, input);
                pics[pic_selection]->setSynopsis(input);
                break;
            default:
                cout << "Selection invalid; enter a valid menu selection" << endl;
                string throwaway;
                cin.ignore();
                getline(cin, throwaway);
        }
    }
}

