#include "Route.h"
#include "Airport.h"
#include <cmath>

// define pi 3.14159265358979323846

long double toRad(const double degree) {
    double d1 = (M_PI) / 180;
    return (d1 * degree);
}

Route::Route() {

}

Route::Route(const Airport & a1, const Airport & a2) {
    source  = a1;
    destination = a2;
    calcDist();
}


void Route::calcDist() {
    double lat1 = toRad(source.getLatitude());
    double long1 = toRad(source.getLongitude());
    double lat2 = toRad(destination.getLatitude());
    double long2 = toRad(destination.getLongitude());

    double lon = long2 - long1;
    double lat = lat2 - lat1;

    dist = sin(lat / 2) * sin(lat / 2) + cos(lat1) * cos(lat2) * sin(lon / 2) * sin(lon / 2);
    dist = 2 * asin(sqrt(dist));
    dist = (6371.0 * dist);
}

double Route::getDist() {
    return dist;
}

Airport Route::getSource() {
    return source;
}

Airport Route::getDestination() {
    return destination;
}