#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#include "Airport.h"
using namespace std;

class Route {
    public:
        Route();
        Route(const Airport & a1, const Airport & a2);
        void calcDist();
        double getDist();
        Airport getSource();
        Airport getDestination();

    private:
        Airport source;
        Airport destination;
        double dist;
};