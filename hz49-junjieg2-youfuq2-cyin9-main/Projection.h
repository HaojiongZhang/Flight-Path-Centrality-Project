#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cmath>

#include "Airport.h"
#include "Route.h"
//#include "bfs.h"
//#include "Dijkstra.h"
//#include "Centrality.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

using namespace std;
using namespace cs225;

class Projection {
    public:
        Projection();
        Projection(Airport a1, Airport a2);
        ~Projection();
        double xCal(double lo);
        double yCal(double la);
        double lonErrorFix(double x);
        double pixelDist(double x1, double y1, double x2, double y2);
        void drawPoint(Airport airport, double centrality);
        void drawLine(Airport air1, Airport air2);
        void drawLinePacific(Airport air1, Airport air2);
        void drawLineAtlantic(Airport air1, Airport air2);
        void writeToMap();
        // void outputMap();

    private:
        Airport origin;
        Airport destination;
        PNG map;
        int mapWidth;
        int mapHeight;
        int originx;
        int originy;
};