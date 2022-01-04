#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cmath>

#include "Projection.h"

using namespace std;
using namespace cs225;


Projection::Projection() {
    Airport air("Airport", 1, 1, 1);
    origin = air;
    destination = air;
    map.readFromFile("Mercator_projection_map.png");
    mapWidth = map.width();
    mapHeight = map.height();
    originx = mapWidth / 2;
    originy = mapHeight / 2;
}

Projection::Projection(Airport a1, Airport a2) {
    origin = a1;
    destination = a2;
    map.readFromFile("Mercator_projection_map.png");
    mapWidth = map.width();
    mapHeight = map.height();
    originx = mapWidth / 2;
    originy = mapHeight / 2;
}

Projection::~Projection() {

}

double Projection::lonErrorFix(double x) {
    /*
    if (x > originx) {
        // fix the error between algorithm and the image.
        x *= (mapWidth / mapHeight);
    */
    return x * ((double)mapWidth / (double)mapHeight) * (23.0 / 24.0);
}

double Projection::xCal(double lo) {
    return (lo + 180.0) * (mapWidth / 360);
}

double Projection::yCal(double la) {
    double lat_rad = la * M_PI / 180;
    double mercn = log(tan((M_PI / 4) + (lat_rad / 2)));
    return (mapHeight / 2) - (mapWidth * mercn / (2 * M_PI));
}

double Projection::pixelDist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void Projection::drawPoint(Airport airport, double centrality) {
    double radius = 20 * (1.0 + centrality);
    double lon = airport.getLongitude();
    double lat = airport.getLatitude();
    double x_coor = xCal(lon);
    double y_coor = yCal(lat);
    x_coor = lonErrorFix(x_coor);

    for (int j = 0; j < mapHeight; ++j) {
        for (int i = 0; i < mapWidth; ++i) {
            HSLAPixel & pixelIn = map.getPixel(i, j);
            bool inCircle = radius > pixelDist(x_coor, y_coor, i, j);
            if (inCircle) {
                pixelIn.h = 0;
                pixelIn.s = 1;
                pixelIn.l = .5;
                pixelIn.a = 1;
            }
        }
    }
}

void Projection::drawLine(Airport air1, Airport air2) {
    double lon1 = air1.getLongitude();
    double x1 = xCal(lon1);
    double lon2 = air2.getLongitude();
    double x2 = xCal(lon2);

    int pacific = min(x1, x2) + mapWidth - max(x1, x2);
    int atlantic = mapWidth - pacific;

    if (pacific < atlantic) {
        drawLinePacific(air1, air2);
    }
    else {
        drawLineAtlantic(air1, air2);
    }
}

// back of map
void Projection::drawLinePacific(Airport air1, Airport air2) {
    double lat1 = air1.getLatitude();
    double y1 = yCal(lat1);

    double lon1 = air1.getLongitude();
    double x1 = xCal(lon1);
    x1 = lonErrorFix(x1);
    double lat2 = air2.getLatitude();
    double y2 = yCal(lat2);
    double lon2 = air2.getLongitude();
    double x2 = xCal(lon2);
    x2 = lonErrorFix(x2);
    double newX1;
    double newX2;

    if (x1 < x2) {
        newX1 = x1 + originx;
        newX2 = x2 - originx;
    }
    else {
        newX1 = x1 - originx;
        newX2 = x2 + originx;
    }

    for (int i = 0; i < mapHeight; ++i) {
        for (int j = 0; j < mapWidth; ++j) {
            HSLAPixel & pixelIn = map.getPixel(j, i);
            bool onLine = abs((j - x2) / (x1 - x2) - (i - y2) / (y1 - y2)) <= 0.3;
            bool outX = (j >= max(x1, x2)) || (j <= min(x1, x2));
            bool outY = (i >= max(y1, y2)) || (i <= min(y1, y2));
            bool line = onLine && outX && outY;
            if (line) {
                pixelIn.h = 0;
                pixelIn.s = 1;
                pixelIn.l = .5;
                pixelIn.a = 1;
            }
            else {
                continue;
            }
        }
    }
}

// front of map
void Projection::drawLineAtlantic(Airport air1, Airport air2) {
    double lat1 = air1.getLatitude();
    double y1 = yCal(lat1);
    double lon1 = air1.getLongitude();
    double x1 = xCal(lon1);
    x1 = lonErrorFix(x1);
    double lat2 = air2.getLatitude();
    double y2 = yCal(lat2);
    double lon2 = air2.getLongitude();
    double x2 = xCal(lon2);
    x2 = lonErrorFix(x2);

    for (int i = 0; i < mapHeight; ++i) {
        for (int j = 0; j < mapWidth; ++j) {
            HSLAPixel & pixelIn = map.getPixel(j, i);
            double limit = 0.3;
            if (abs((y1 - y2) / (x1 - x2)) > 0.2) {
                limit = 0.015;
            }
            bool onLine = abs((j - x2) / (x1 - x2) - (i - y2) / (y1 - y2)) <= limit;
            bool inX = (j <= max(x1, x2)) && (j >= min(x1, x2));
            bool inY = (i <= max(y1, y2)) && (i >= min(y1, y2));
            bool line = onLine && inX && inY;
            if (line) {
                pixelIn.h = 0;
                pixelIn.s = 1;
                pixelIn.l = .5;
                pixelIn.a = 1;
            }
            else {
                continue;
            }
        }
    }
}

void Projection::writeToMap() {
    map.writeToFile("Mercator_projection_mapped.png");
}