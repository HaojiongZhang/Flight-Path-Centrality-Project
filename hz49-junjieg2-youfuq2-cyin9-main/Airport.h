#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Airport {
    public:
        Airport();
        Airport(string name, int ID, double latitude, double longitude);
        void setName(string name);
        string getName();
        void setID(int ID);
        int getID();
        void setLatitude(double latitude);
        double getLatitude();
        void setLongitude(double longitude);
        double getLongitude();

    private:
        string name;
        int ID;
        double latitude;
        double longitude;
};