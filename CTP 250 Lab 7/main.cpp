#include <iostream>
#include "Airport.cpp"
#include "BinarySearchTree.h"
#include <fstream>
#include <string>
#include <vector>
#include "menu.cpp"


using namespace std;

void buildBinaryTreeFromFile(BinarySearchTree <Airport> &);

//search menu methods
void searchMenuMethods(BinarySearchTree <Airport>, int choice);
void searchAirportByCode(BinarySearchTree <Airport> airports);
void searchByState(BinarySearchTree <Airport> airports);
void searchByMinPassengers(BinarySearchTree <Airport> airports);

//generate Reports menu methods
void generateReportsMenuMethods(BinarySearchTree <Airport>, int choice);
void listAllAirports(BinarySearchTree <Airport> airports);
void avgNumPassengers(BinarySearchTree <Airport> airports); //in a day
void avgNumFlights(BinarySearchTree <Airport> airports); // in a day

//Max Min menu methods
void maxMinMenuMethods(BinarySearchTree <Airport> , int choice);
void maxNumPassengers(BinarySearchTree <Airport> airports);
void maxFreight(BinarySearchTree <Airport> airports);
void maxNumFlights(BinarySearchTree <Airport> airports);
void minNumPassengers(BinarySearchTree <Airport> airports);
void minFreight(BinarySearchTree <Airport> airports);
void minNumFlights(BinarySearchTree <Airport> airports);

//edit menu methods
void editMenuMethods(BinarySearchTree <Airport>, int choice);
void editNumPassengers(BinarySearchTree <Airport> airports);
void editFreight(BinarySearchTree <Airport> airports);
void editNumFlights(BinarySearchTree <Airport> airports);



int main() {

    BinarySearchTree <Airport> airports;
    int option = 0;
    int choice = 0;
    buildBinaryTreeFromFile(airports);

    cout << "Please Select a Menu Option: " << endl;

    //airports.inorderTraverse();
    //airports.displayInorderTraverse();

    //Execution of Menu's
    option = mainMenu();
    if (option == 1) {
        choice = searchMenu();
        searchMenuMethods(airports,choice);
    }
    else if (option == 2){
        choice = generateReportsMenu();
        generateReportsMenuMethods(airports, choice);
    }
    else if (option == 3){
        choice = maxMinMenu();
        maxMinMenuMethods(airports, choice);
    }
    else if (option == 4){
        choice = editMenu();
        editMenuMethods(airports, choice);
    }
    else{
        cout << "Thank you... program terminating..." << endl;
    }



    return 0;
}
/* Binary Search tree built with data from the file "us-airports-1.csv"
 * uses the Airport(string attributes) constructor to build each Airport object from each line of data.
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects.
 */
void buildBinaryTreeFromFile(BinarySearchTree <Airport> &airports){
    //opening file
    ifstream infile("us-airports-1.csv");
    string line = "";
    //checking if file is open
    if(!infile.is_open()) {
        cout << "File not open for input...program terminating" << endl;
        exit(0);
    }
    getline(infile, line);
    while(getline(infile, line)){
        transform(line.begin(), line.end(), line.begin(), ::toupper);
        Airport a(line);
        airports.add(a);
        //cout << a;
    }

    infile.close();
}
/* Calls the methods for each menu option in searchMenu()
 * switch case used for each menu option in searchMenu()
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects.
 */
void searchMenuMethods(BinarySearchTree <Airport> airports, int choice){

    switch(choice){
        case 1:
            searchAirportByCode(airports);
            break;
        case 2:
            searchByState(airports);
            break;
        case 3:
            searchByMinPassengers(airports);
            break;
        case 4:
            mainMenu();
            break;
    }
}//end searchMenuMethods()

/* Calls the methods for each menu option in generateReportsMenu()
 * switch case used for each menu option in generateReportsMenu()
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects.
 */
void generateReportsMenuMethods(BinarySearchTree <Airport> airports, int choice){

    switch(choice){
        case 1:
            listAllAirports(airports);
            break;
        case 2:
            avgNumPassengers(airports);
            break;
        case 3:
            avgNumFlights(airports);
            break;
        case 4:
            mainMenu();
    }
}// end generateReportsMenuMethods()

/* Calls the methods for each menu option in maxMinMenu()
 * switch case used for each menu option in maxMinMenu()
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects.
 */
void maxMinMenuMethods(BinarySearchTree <Airport> airports, int choice){

    switch(choice){
        case 1:
            maxNumPassengers(airports);
            break;
        case 2:
            maxFreight(airports);
            break;
        case 3:
            maxNumFlights(airports);
            break;
        case 4:
            minNumPassengers(airports);
            break;
        case 5:
            minFreight(airports);
            break;
        case 6:
            minNumFlights(airports);
            break;
        case 7:
            mainMenu();
            break;
    }
}// end maxMinMenuMethods()

/* Calls the methods for each menu option in editMenu()
 * switch case used for each menu option in editMenu()
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects.
 */
void editMenuMethods(BinarySearchTree<Airport> airports, int choice){

    switch(choice){
        case 1:
            editNumPassengers(airports);
            break;
        case 2:
            editFreight(airports);
            break;
        case 3:
            editNumFlights(airports);
            break;
        case 4:
            mainMenu();
            break;
    }

}//end editMenuMethods()

//METHODS-------------------------------------------------------------------------

/* Searches Airport Objects in the Binary Search Tree for a specific Airport code.
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects.
 * returns The Airport object that matches the userInput for code
 */
void searchAirportByCode(BinarySearchTree <Airport> airports){

    string airportCode = "";
    cout << "\nEnter Airport code(Ex: LAX): ";
    cin >> airportCode;
    transform(airportCode.begin(), airportCode.end(), airportCode.begin(), ::toupper);

    cout << "Airports that contain: " << airportCode << endl;
    cout << "\n---------------------------------" << endl;

    airports.inorderTraverseString(airportCode);

}//end searchAirportByCode()

/* Searches Airport Objects in the Binary Search Tree for a specific Airport state.
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects
 * returns The Airport object that matches the userInput for state
 */
void searchByState(BinarySearchTree <Airport> airports){

    string airportState = "";
    cout << "\nEnter Airport State(Ex: CA): ";
    cin >> airportState;
    transform(airportState.begin(), airportState.end(), airportState.begin(), ::toupper);

    cout << "Airports that contain: " << airportState << endl;
    cout << "\n---------------------------------" << endl;

    airports.inorderTraverseString(airportState);
} //end searchByState()

/* Searches Airport Objects in the Binary Search Tree for a minimum number of Passengers
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects
 * returns The Airport object that matches or is greater than the userInput for minimum number of passengers
 */

void searchByMinPassengers(BinarySearchTree <Airport> airports){

    int numPassengers = 0;
    cout << "\nEnter Minimum Number of Passengers: ";
    cin >> numPassengers;

    cout << "Airports that contain " << numPassengers << " Passengers or more: " << endl;
    cout << "\n---------------------------------" << endl;


    airports.inorderTraverseInteger(numPassengers);
}//end searchByMinPassengers()

/* displays all Airport Objects in the Binary Search Tree
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects
 * displays the Airport name, state, city, code, number of passengers, number of flights, and number of freight
 */
void listAllAirports(BinarySearchTree<Airport>airports){
    int width = 20;
    cout << left << setw(65) <<  "\nName: " <<
         left << setw(10) <<  "State: " <<
         left << setw(25) << "City: " <<
         left << setw(width) << "Code: " <<
         left << setw(width) << "Num of Passengers: " <<
         left << setw(width) << "Num of Flights: " <<
         left << setw(width) << "Num of Freight: " << endl;

    airports.displayInorderTraverse();
}//end listAllAirports()

/* displays Airport Objects in the Binary Search Tree
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects
 * displays the Airport name, state, city, code, and average number of passengers in a year (365 days)
 */
void avgNumPassengers(BinarySearchTree <Airport> airports){
    int width = 20;
    cout << "\nAverage Number of Passengers in one year (365 days): " << endl;

    cout << left << setw(65) <<  "\nName: " <<
         left << setw(10) <<  "State: " <<
         left << setw(25) << "City: " <<
         left << setw(width) << "Code: " <<
         left << setw(width) << "Avg Num of Passengers: " << endl;

    airports.displayAvgNumPassengersTraverse();
}//end avgNumPassengers()

/* displays Airport Objects in the Binary Search Tree
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects
 * displays the Airport name, state, city, code, and average number of Flights in a year (365 days)
 */
void avgNumFlights(BinarySearchTree <Airport> airports){
    int width = 20;

    cout << "\nAverage Number of Flights in one year (365 days): " << endl;

    cout << left << setw(65) <<  "\nName: " <<
         left << setw(10) <<  "State: " <<
         left << setw(25) << "City: " <<
         left << setw(width) << "Code: " <<
         left << setw(width) << "Avg Num of Flights: " << endl;

    airports.displayAvgNumFlightsTraverse();
} //end avgNumFlights()

/* displays the Airport Object with Max num of Passengers in the Binary Search Tree
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects
 * displays the Airport name, code, and number of Passengers
 */
void maxNumPassengers(BinarySearchTree <Airport> airports){
    int width = 20;
    cout << "\nAirport with Maximum Number of Passengers: " << endl;

    cout << left << setw(65) <<  "\nName: " <<
         left << setw(width) << "Code: " <<
         left << setw(width) << "Num of Passengers: " << endl;

    airports.maxNumPassengersTraverse();

}//end maxNumPassengers()

/* displays the Airport Object with Max num of Freight in the Binary Search Tree
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects
 * displays the Airport name, code, and amount of freight
 */
void maxFreight(BinarySearchTree<Airport>airports){
    int width = 20;
    cout << "\nAirport with Maximum Amount of Freight: " << endl;

    cout << left << setw(65) <<  "\nName: " <<
         left << setw(width) << "Code: " <<
         left << setw(width) << "Amount of Freight: " << endl;


    airports.maxFreightTraverse();

}//end maxFreight()

/* displays the Airport Object with Max num of Flights in the Binary Search Tree
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects
 * displays the Airport name, code, and num of flights
 */

void maxNumFlights(BinarySearchTree<Airport>airports){
    int width = 20;
    cout << "\nAirport with Maximum Number of Flights: " << endl;

    cout << left << setw(65) <<  "\nName: " <<
         left << setw(width) << "Code: " <<
         left << setw(width) << "Num of Flights: " << endl;


    airports.maxNumFlightsTraverse();

}//end maxNumFlights()

/* displays the Airport Object with Min num of Passengers in the Binary Search Tree
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects
 * displays the Airport name, code, and number of Passengers
 */
void minNumPassengers(BinarySearchTree <Airport> airports){
    int width = 20;
    cout << "\nAirport with Minimum Number of Passengers: " << endl;

    cout << left << setw(65) <<  "\nName: " <<
         left << setw(width) << "Code: " <<
         left << setw(width) << "Num of Passengers: " << endl;

    airports.minNumPassengersTraverse();

}//end minNumPassengers()

/* displays the Airport Object with Min amount of freight in the Binary Search Tree
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects
 * displays the Airport name, code, and amount of freight
 */
void minFreight(BinarySearchTree <Airport> airports){
    int width = 20;
    cout << "\nAirport with Minimum Amount of Freight: " << endl;

    cout << left << setw(65) <<  "\nName: " <<
         left << setw(width) << "Code: " <<
         left << setw(width) << "Amount of Freight: " << endl;

    airports.minFreightTraverse();

}//end minFreight()

/* displays the Airport Object with Min num of Flights in the Binary Search Tree
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects
 * displays the Airport name, code, and num of flights
 */
void minNumFlights(BinarySearchTree<Airport>airports){
    int width = 20;
    cout << "\nAirport with Minimum Number of Flights: " << endl;

    cout << left << setw(65) <<  "\nName: " <<
         left << setw(width) << "Code: " <<
         left << setw(width) << "Num of Flights: " << endl;


    airports.minNumFlightsTraverse();

}//end minNumFlights()

/* Allows user to input new num of Passengers of an Airport object -> searches Airport by code
 * displays the old Airport Object and new Airport object with new num of Passengers
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects
 */

void editNumPassengers(BinarySearchTree<Airport>airports){

    string airportCode = "";

    cout << "\nEnter Airport Code(Ex: LAX): ";
    cin >> airportCode;
    transform(airportCode.begin(), airportCode.end(), airportCode.begin(), ::toupper);

    airports.changeNumPassengersTraverse(airportCode);

}//end editNumPassengers()

/* Allows user to input new amount of freight of an Airport object -> searches Airport by code
 * displays the old Airport Object and new Airport object with new amount of freight
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects
 */
void editFreight(BinarySearchTree<Airport>airports){

    string airportCode = "";

    cout << "\nEnter Airport Code(Ex: LAX): ";
    cin >> airportCode;
    transform(airportCode.begin(), airportCode.end(), airportCode.begin(), ::toupper);

    airports.changeFreightTraverse(airportCode);

} //end editFreight()

/* Allows user to input new num of flights of an Airport object -> searches Airport by code
 * displays the old Airport Object and new Airport object with new num of flights
 * @param BinarySearchTree <Airport> is the Binary Search Tree of Airport objects
 */
void editNumFlights(BinarySearchTree<Airport>airports){

    string airportCode = "";

    cout << "\nEnter Airport Code(Ex: LAX): ";
    cin >> airportCode;
    transform(airportCode.begin(), airportCode.end(), airportCode.begin(), ::toupper);

    airports.changeNumFlightsTraverse(airportCode);

}//end editNumFlights()


