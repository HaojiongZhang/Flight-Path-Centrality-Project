#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>

#include "Airport.h"
#include "Route.h"
#include "bfs.h"
#include "Dijkstra.h"
#include "Centrality.h"
#include "Projection.h"
#include "test.h"

using namespace std;

//helper function to get Index of a given element in a vector
int getintIndex(vector<int> v, int k) {
    auto it = find(v.begin(), v.end(), k);
    if(it != v.end()) {
        int index = it - v.begin();
        return index;
    }
    else {
        return -1;
    }
}

int getIndexName(vector<string> v, string k) {
    auto it = find(v.begin(), v.end(), k);
    if(it != v.end()) {
        int index = it - v.begin();
        return index;
    }
    else {
        return -1;
    }
}

int main() 
{
    //testing 
    
    testBFS1();
    testBFS2();
    testBFS3();
    testDijkstra1();
    testDijkstra2();
    testDijkstra3();
    testCentrality1();
    testCentrality2();

    //read the file directly
    vector<string> airportNames;
    vector<double> latitudeValues;
    vector<double> longtitudeValues;
    vector<int> airportID;
    vector<int> SourceID;
    vector<int> DestinationID;
    //vectors that used to set up graph
    vector< vector <double> > adjacencyMatrix;
    //vectors that used to set up for centrality
    vector<int> traversed;
    vector<int> centrality;
    vector<double> display;
    vector< vector <double> > largestComponent;

    ifstream airportsFile("airports.dat");
    ifstream routesFile("routes.dat");

    //set up some string for reading
    string AirportID, Name, City, Country, IATA, ICAO, Latitude, Longitude;
    string myString, line;
    string Airline, AirlineID, SourceAirport, SourceIDs, DestinationAirport, DestinationIDs;

    if (airportsFile.is_open()) {
    /* Reads a line from `wordsFile` into `word` until the file ends. */
        while (getline(airportsFile, line)) {
            stringstream ss(line);
            getline(ss, AirportID, ',');
            getline(ss, Name, ',');
            getline(ss, City, ',');
            getline(ss, Country, ',');
            getline(ss, IATA, ',');
            getline(ss, ICAO, ',');
            getline(ss, Latitude, ',');
            getline(ss, Longitude, ',');
            stringstream la(Latitude);
            stringstream lo(Longitude);
            stringstream id(AirportID);
            double Lati;
            la >> Lati;
            double Longi;
            lo >> Longi;
            int ID;
            id >> ID;


            airportNames.push_back(Name.substr(1, Name.size() - 2));
            latitudeValues.push_back(Lati);
            longtitudeValues.push_back(Longi);
            airportID.push_back(ID);
        }
        airportsFile.close();    
    }


    if (routesFile.is_open()) {
        while (getline(routesFile, line)) {
            stringstream ss(line);
            getline(ss, Airline, ',');
            getline(ss, AirlineID, ',');
            getline(ss, SourceAirport, ',');
            getline(ss, SourceIDs, ',');
            getline(ss, DestinationAirport, ',');
            getline(ss, DestinationIDs, ',');

            stringstream sID(SourceIDs);
            stringstream dID(DestinationIDs);
            int sourceID; 
            sID >> sourceID;
            int destinationID;
            dID >> destinationID;

            SourceID.push_back(sourceID);
            DestinationID.push_back(destinationID);
        }
        routesFile.close(); 
    }


    //Graph Establishment Part


    //set up a 7698 * 7698 square matrix
    int airportsNum = airportID.size();
    adjacencyMatrix.resize(airportsNum);
    for(unsigned int i = 0; i < adjacencyMatrix.size(); i++) {
        adjacencyMatrix[i].resize(airportsNum);
    }
    
    //now fill the adjacency matrix with distance, successfully establish the graph
    for (unsigned int i = 0; i < SourceID.size(); i++) {
        int sourceIndex = getintIndex(airportID, SourceID[i]);
        int destinationIndex = getintIndex(airportID, DestinationID[i]);
        if(sourceIndex == -1 || destinationIndex == -1) {
            continue;
        }
        Airport a1(airportNames[sourceIndex], airportID[sourceIndex], latitudeValues[sourceIndex], longtitudeValues[sourceIndex]);
        Airport a2(airportNames[destinationIndex], airportID[destinationIndex], latitudeValues[destinationIndex], longtitudeValues[destinationIndex]);
        Route r(a1, a2);
        adjacencyMatrix[sourceIndex][destinationIndex] = r.getDist();
    }


    //BFS I/O part
    
    
    int ID;
    cout << "Please enter an airport ID that you want to traverse: ";
    cin >> ID;
    //error handling part
    if(getintIndex(airportID, ID) == -1) {
        cout << "Please input a valid airport ID! " << endl;
        return -1;
    } else {
        BFS bfs(adjacencyMatrix, airportNames);
        bfs.traverse(getintIndex(airportID, ID));
        bfs.printBFS();
        cout << "There are " << bfs.returnNum() << " airports you have traversed using BFS" << endl;
        traversed = bfs.output();
    }

    //Dij I/O part
    

    int startID;
    int destinationID;
    cout << "Welcome to the airports search progrom" << endl;
    cout << "Please enter an airport ID as start: ";
    cin >> startID;
    int start = getintIndex(airportID, startID);
    cout << "Please enter an airport ID as destination: ";
    cin >> destinationID;
    int end = getintIndex(airportID, destinationID);
    Dijkstra dij(adjacencyMatrix, airportNames, start);
    dij.DijkstraAlgo(start);
    dij.returnDistance(end);
    vector<string> path = dij.printPath(end);
    vector<Airport> airport_s;
    for (unsigned int i = 0; i < path.size(); ++i) {
        auto index = getIndexName(airportNames, path[i]);
        Airport air(path[i], airportID[index], latitudeValues[index], longtitudeValues[index]);
        airport_s.push_back(air);
    }


  
    //Centrality I/O part
    
    
        cout<< "Starting test matrix for betweeness centrality, expected impact of each node is {3, 4, and 2} for given test case graph" << endl;
    vector< vector <double> > testMatrix;
        testMatrix.resize(3);
        for(unsigned int i = 0; i < testMatrix.size(); i++) {
            testMatrix[i].resize(3);
        }
    testMatrix = {
     
        {0,1,0},
        {1,0,0},
        {0,1,0}
    };
    
    Centrality central(testMatrix);
    
    central.betweenCentral(0);
    centrality = central.returnCentral();
    for(unsigned int i = 0; i < centrality.size(); i++) {
        cout << centrality[i] << endl;
    }

    int switch_;
    cout << "Please enter 1 to start, it may take a while: ";
    cin >> switch_;

    if(switch_ == 1){
        cout <<  "Constructing the largestcomponent matrix, largest CC known contains 3166 vertices, please check at BFS count" << endl;
        largestComponent.resize(traversed.size());
        for(unsigned int j = 0; j < largestComponent.size(); j++) {
            largestComponent[j].resize(traversed.size());
        }

        
        for(unsigned int m = 0; m < largestComponent.size(); m++) {
            for(unsigned int n = 0; n < largestComponent[m].size(); n++) {
                
                    largestComponent[m][n] = adjacencyMatrix[traversed[m]][traversed[n]];
                
            }
        
        }
        cout << "construction complete with dimensions" << largestComponent.size() << "," << largestComponent[0].size()<< endl;
        Centrality centralnew1(largestComponent);

        centralnew1.betweenCentral(0);
        centrality = centralnew1.returnCentral();

        display.resize(centrality.size());
        for(unsigned int a = 0; a < display.size(); a++) {
            display[a] = centrality[a];
        }

        cout << "Among the airports you choose, Here are the results for each airport's time of includes in shortest paths: " << endl;
        for(unsigned int i = 0; i < display.size(); i++) {
            cout << airportNames[traversed[i]] << " : " << display[i] << endl;
        }
    }

    Projection prj;
    for (unsigned int i = 0; i < path.size(); ++i) {
        prj.drawPoint(airport_s[i], (double)i / 10.0);
    }
    for (unsigned int j = 0; j < path.size() - 1; ++j) {
        prj.drawLine(airport_s[j], airport_s[j + 1]);
    }
    prj.writeToMap();

    return 0;
}

