//
// Created by Emely Pleitez on 11/3/22.
//

#include "menu.h"

using namespace std;


int searchMenu(){
    int x = 0;

    cout << "\n*** SEARCH MENU *** " << endl;
    cout << "Search by..." << endl;
    cout << "Airport code (Ex: BWI) -------- (1) " << endl;
    cout << "State (Ex: TX) ---------------- (2) " << endl;
    cout << "Min number of Passengers------- (3) " << endl;
    cout << "Return to Main Menu ----------- (4) " << endl;
    cout << "What is your numerical choice (1-4)?: " ;

    cin >> x;

    while (x < 1 || x > 4){
        cout << "not a valid menu choice..." << endl;
        cout << "(1), (2), (3) or (4)? ";
        cin >> x;
    }

    return x;
} //end searchMenu()

int generateReportsMenu(){
    int x = 0;
    cout << "\n*** GENERATE REPORTS MENU *** " << endl;
    cout << "List all..." << endl;
    cout << "Airports ---------------------- (1) " << endl;
    cout << "Avg num of Passengers per day - (2) " << endl;
    cout << "Avg num of Flights per day ---- (3)" << endl;
    cout << "Return to Main Menu ----------- (4) " << endl;
    cout << "What is your numerical choice (1-4)?: " ;

    cin >> x;

    while (x < 1 || x > 4){
        cout << "not a valid menu choice..." << endl;
        cout << "(1), (2), (3) or (4)? ";
        cin >> x;
    }


    return x;
}//end generateReportsMenu()

int maxMinMenu(){
    int choice = 0;

    cout << "\n*** MAX MIN MENU *** " << endl;
    cout << "Search by..." << endl;
    cout << "Max num of Passengers --------- (1) " << endl;
    cout << "Max Freight ------------------- (2) " << endl;
    cout << "Max num of Flights------------- (3) " << endl;
    cout << "Min num of Passengers --------- (4) " << endl;
    cout << "Min Freight ------------------- (5) " << endl;
    cout << "Min num of Flights------------- (6) " << endl;
    cout << "Return to Main Menu ----------- (7) " << endl;
    cout << "What is your numerical choice (1-7)?: " ;

    cin >> choice;

    while (choice < 1 || choice > 7){
        cout << "not a valid menu choice..." << endl;
        cout << "(1), (2), (3), (4), (5), (6) or (7)? ";
        cin >> choice;
    }

    return choice;
}

int editMenu(){
    int x = 0;
    cout << "\n*** EDIT AIRPORT DATA MENU *** " << endl;
    cout << "Edit..." << endl;
    cout << "Num of Passengers ------------- (1) " << endl;
    cout << "Amount of Freight ------------- (2) " << endl;
    cout << "Num of Flights ---------------- (3) " << endl;
    cout << "Return to Main Menu ----------- (4) " << endl;
    cout << "What is your numerical choice (1-4)?: " ;

    cin >> x;

    while (x < 1 || x > 4){
        cout << "not a valid menu choice..." << endl;
        cout << "(1), (2), (3) or (4)? ";
        cin >> x;
    }
    return x;
}//end editMenu();

int mainMenu(){
    int x = 0;

    cout << "\n*** MAIN MENU *** " << endl;

    cout << "Search ------------------------ (1) " << endl;
    cout << "Generate Reports -------------- (2) " << endl;
    cout << "Maximums and Minimums --------- (3) " << endl;
    cout << "Edit Airport data ------------- (4) " << endl;
    cout << "Quit -------------------------- (5) " << endl;
    cout << "What is your numerical choice (1-5)?: " ;

    cin >> x;

    while (x < 1 || x > 5){
        cout << "not a valid menu choice..." << endl;
        cout << "(1), (2), (3), (4) or (5)? ";
        cin >> x;
    }

    return x;
}//end mainMenu()



