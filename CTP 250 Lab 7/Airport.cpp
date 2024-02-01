//
// Created by Emely Pleitez on 10/25/22.
//

#include 3"Airport.h"
#include <iostream>
#include <sstream>

using namespace std;

//default constructor
Airport::Airport() {

    name = "";
    state = "";
    city = "";
    code = "";
    numPassengers = 0;
    numFlights = 0;
    freight = 0;

}
/*overloaded constructor
Airport::Airport(string name, string state, string city, string code,
                 int numPassengers, int numFlights, int freight){
    this->name = name;
    this->state = state;
    this->city = city;
    this->code = code;
    this->numPassengers = numPassengers;
    this->numFlights = numFlights;
    this->freight = freight;
}
 */

//add copy constructor
//Airport objects constructor
Airport::Airport(string attributes) {

    //new variables
    string numberPassengers = "";
    string numberFlights = "";
    string sizeFreight = "";

    istringstream iss(attributes);

        getline(iss, name, ',');
        getline(iss, state, ',');
        getline(iss, city, ',');
        getline(iss, code, ',');
        getline(iss, numberPassengers, ',');
        getline(iss, numberFlights, ',');
        getline(iss, sizeFreight, ',');
        numFlights = stoi(numberFlights);
        numPassengers = stoi(numberPassengers);
        freight = stoi(sizeFreight);

    attributes = name + state + city + code + numberPassengers +
                 numberFlights + sizeFreight;
}


//---------------Setters---------------------------------------------
/* Sets the name of the Airport to name
 * @param name: the new Airport name of this Airport
 */
void Airport::setName(string name) {
    this->name = name;
}

void Airport::setState(string state) {
    this->state = state;
}

void Airport::setCity(string city){
    this->city = city;
}

void Airport::setCode(string code) {
    this->code = code;
}

void Airport::setNumPassengers(int numPassengers) {
    this->numPassengers = numPassengers;
}

void Airport::setNumFlights(int numFlights) {
    this->numFlights = numFlights;
}

void Airport::setFreight(int freight) {
    this->freight = freight;
}

//---------------Getters---------------------------------------------
/* Returns the name of this Airport
 * @return the name of this Airport
 */
string Airport::getName() {
    return name;
}

string Airport::getState() {
    return state;
}

string Airport::getCity() {
    return city;
}

string Airport::getCode() {
    return code;
}

int Airport::getNumPassengers() {
    return numPassengers;
}

int Airport::getNumFlights() {
    return numFlights;
}

int Airport::getFreight() {
    return freight;
}

/*---------------toString()---------------------------------------------
const string Airport::toString() const {

    ostringstream s;

    s << "Airport Name: " << name << "\n"
      << "State: " << state << "\n"
      << "City: " << city << "\n"
      << "Code: " << code << "\n"
      << "Number of Passengers: " << numPassengers << "\n"
      << "Number of Flights: " << numFlights << "\n"
      << "Freight in Tons: " << freight << "\n"
      << "--------------------------------- " << endl;

    return s.str();
}
*/
//---------------Overloaded Operator Functions------------------------------

bool Airport::operator==(const Airport &airport2) const {
    return ( (this->name == airport2.name) &&
             (this->state == airport2.state) &&
             (this->city == airport2.city) &&
             (this->code == airport2.code) &&
             (this->numPassengers == airport2.numPassengers) &&
             (this->numFlights == airport2.numFlights) &&
             (this->freight == airport2.freight) );

}//end operator ==

bool Airport::operator!=(const Airport &airport2) const{
    return ( (this->name != airport2.name) ||
             (this->state != airport2.state) ||
             (this->city != airport2.city) ||
             (this->code != airport2.code) ||
             (this->numPassengers != airport2.numPassengers) ||
             (this->numFlights != airport2.numFlights) ||
             (this->freight != airport2.freight) );
}//end operator !=

void Airport::operator+=(int x){
    this->numFlights += x;
} // end +=(int)

bool Airport::operator>(const Airport &airport2) const{
    return (this->numPassengers > airport2.numPassengers);
} //end operator >

bool Airport::operator<(const Airport &airport2) const{
    return (this->numPassengers < airport2.numPassengers);
} //end operator <

//---------------Friend Functions-------------------------------------
ostream& operator<<(ostream& out, const Airport &airport2){
    out << "Airport Name: " << airport2.name << "\n"
        << "State: " << airport2.state << "\n"
        << "City: " << airport2.city << "\n"
        << "Code: " << airport2.code << "\n"
        << "Number of Passengers: " << airport2.numPassengers << "\n"
        << "Number of Flights: " << airport2.numFlights << "\n"
        << "Freight in Tons: " << airport2.freight << "\n"
        << "--------------------------------- " << endl;

    return out;
}//end ostream operator <<


//need to fix----------------------------------------------------
istream& operator>>(istream& input, Airport &airport2){

    cout << "Enter Airport Name: ";
    input >> airport2.name;
    cout << "Enter State: ";
    input >> airport2.state;
    cout << "Enter City: ";
    input >> airport2.city;
    cout << "Enter Code: ";
    input >> airport2.code;
    cout << "Enter the Number of Passengers: ";
    input >> airport2.numPassengers;
    cout << "Enter the Number of Flights: ";
    input >> airport2.numFlights;
    cout << "Enter the Freight (in Tons): ";
    input >> airport2.freight;

    return input;
}//end istream operator >>