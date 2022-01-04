#include "Dijkstra.h"

//copy constructor that takes in an adjacency matrix
Dijkstra::Dijkstra(vector< vector <double> > copyMatrix) {
    adj.resize(copyMatrix.size());
    for(unsigned int i = 0; i < adj.size(); i++) {
        adj[i].resize(copyMatrix[i].size());
    }

    for(unsigned int j = 0; j < adj.size(); j++) {
        for(unsigned int k = 0; k < adj[j].size(); k++) {
            adj[j][k] = copyMatrix[j][k];
        }
    }
    distance.resize(copyMatrix.size());
    Tset.resize(copyMatrix.size());
    parent.resize(copyMatrix.size());
}

Dijkstra::Dijkstra(vector< vector <double> > copyMatrix, vector <string> copyNames, int begin) {
    adj.resize(copyMatrix.size());
    airportNames.resize(copyNames.size());
    for(unsigned int i = 0; i < adj.size(); i++) {
        adj[i].resize(copyMatrix[i].size());
    }

    for(unsigned int j = 0; j < adj.size(); j++) {
        for(unsigned int k = 0; k < adj[j].size(); k++) {
            adj[j][k] = copyMatrix[j][k];
        }
    }

    for(unsigned int l = 0; l < airportNames.size(); l++) {
        airportNames[l] = copyNames[l];
    } 

    distance.resize(copyMatrix.size(),0);
    Tset.resize(copyMatrix.size());
    parent.resize(copyMatrix.size());

    start = begin;
}


//helper function for Dijkstra
int Dijkstra::miniDist(vector<double> distance, vector<bool> Tset) {
    int minimum = 1000000, ind;

    for(unsigned int i = 0; i < distance.size(); i++) {
        if(!Tset[i] && distance[i] <= minimum) {
            minimum = distance[i];
            ind = i;
        }
    }
    return ind;
}

void Dijkstra::DijkstraAlgo(int start) {

    for(unsigned int k = 0; k < distance.size(); k++) {
        distance[k] = 1000000;
        Tset[k] = false;
        parent[k] = -2;
    }
    

    distance[start] = 0;
    parent[start] = -2;
    for(unsigned int k = 0; k < Tset.size(); k++) {
        int m = miniDist(distance, Tset);
        Tset[m] = true;
        for(unsigned int k = 0; k < distance.size(); k++) {
           if(!Tset[k] && adj[m][k] && distance[m] != 1000000 && distance[m] +adj[m][k] < distance[k]) {
               distance[k] = distance[m] + adj[m][k];
               parent[k] = m; 

           }
        }
    }
}

//helper function for debugging
void Dijkstra::printDistance() {
    for(unsigned int a = 0; a < distance.size(); a++) {
        cout << distance[a] << endl;
    }
}

vector<double> Dijkstra::returnPath(){
    return distance;
}

vector<string> Dijkstra::printPath(int id){
    vector<string> path;
    while(parent[id]!=-2){
        cout<<airportNames[id]<<endl;
        path.push_back(airportNames[id]);
        id = parent[id];
    }
    path.push_back(airportNames[id]);
    cout<<airportNames[id]<<endl;
    return path;
}

void Dijkstra::returnDistance(int destination) {
    if(distance[destination] == 1000000) {
        cout << "There is no connecting route between " << airportNames[start] << " and " << airportNames[destination] << endl;
        return;
    }
    cout << "The shortest distance is " <<  distance[destination] << " between " << airportNames[start] << " and " << airportNames[destination] << endl;
}

