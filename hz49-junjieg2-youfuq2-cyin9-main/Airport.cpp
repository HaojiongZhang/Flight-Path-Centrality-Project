#include "Airport.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

Airport::Airport() {
    name = "shabi";
    ID = 0;
    latitude = 0.0;
    longitude = 0.0;
}

Airport::Airport(string n, int i, double la, double lo) {
    name = n;
    ID = i;
    latitude = la;
    longitude = lo;
}

void Airport::setName(string n) {
    name = n;
}

string Airport::getName() {
    return name;
}

void Airport::setID(int i) {
    ID = i;
}

int Airport::getID() {
    return ID;
}

void Airport::setLatitude(double la) {
    latitude = la;
}

double Airport::getLatitude() {
    return latitude;
}
void Airport::setLongitude(double lo) {
    longitude = lo;
}

double Airport::getLongitude() {
    return longitude;
}