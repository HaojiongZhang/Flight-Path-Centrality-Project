#include <iostream>
#include <vector>

using namespace std;

class Dijkstra{
    public:
        Dijkstra();  //default constructor
        Dijkstra(vector< vector <double> > copyMatrix);  //copy contructor for testing
        Dijkstra(vector< vector <double> > copyMatrix, vector <string> copyNames, int begin);  //copy constructor for main data set
        void DijkstraAlgo(int start);  //dijkstra algo input: starting node
        void printDistance();  //print the shortest distance
        void returnDistance(int destination);  //return the distance from the starting node to the given input destination
        vector<double> returnPath();  //return the path from start to end
        vector<string> printPath(int id);

    private:
        vector<vector<double>> adj;
        vector<string> airportNames;
        int start;
        int miniDist(vector<double> distance, vector<bool> Tset);
        vector<double> distance;
        vector<bool> Tset;
        vector<int> parent;
};
