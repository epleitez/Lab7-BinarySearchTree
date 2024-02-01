//
// Created by Emely Pleitez on 10/25/22.
//

#ifndef CTP_250_LAB_7_AIRPORT_H
#define CTP_250_LAB_7_AIRPORT_H
#include <string>

using namespace std;

class Airport {

private:
    string name;
    string state;
    string city;
    string code;
    int numPassengers;
    int numFlights;
    int freight; //(in tons)

    //default
    //copy
public:
    //constructors
    Airport();
    //Airport(string name, string state, string city, string code,
            //int numPassengers, int numFlights, int freight);
    Airport(string attributes);
    //setters
    void setName(string);
    void setState(string);
    void setCity(string);
    void setCode(string);
    void setNumPassengers(int);
    void setNumFlights(int);
    void setFreight(int);
    //getters
    string getName();
    string getState();
    string getCity();
    string getCode();
    int getNumPassengers();
    int getNumFlights();
    int getFreight();
    //const string toString()const;

    //overloaded operators
    bool operator==(const Airport &airport2) const;
    bool operator!=(const Airport &airport2) const;
    //increase num of flights in Airport
    void operator+=(int x);
    //compare the number of passengers in two Airport objects
    bool operator>(const Airport &airport2) const;
    bool operator<(const Airport &airport2) const;
    //friend functions
    // (cout) << display current state of object
    friend ostream& operator<<(ostream& out, const Airport &airport2);
    // (cin) >> allow user to enter an airport
    friend istream& operator>>(istream& input, Airport &airport2);


};

#endif //CTP_250_LAB_7_AIRPORT_H
