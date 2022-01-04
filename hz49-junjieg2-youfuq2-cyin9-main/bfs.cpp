#include "bfs.h"
#include <iostream>


BFS::BFS(){
}

//copy over the adjaency matrix from the main.cpp
BFS::BFS(vector< vector <double> > copyMatrix, vector <string> copyNames) {
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
}

//helper function to test that the adjacency matrix is properly copies
void BFS::printMatrix() {
    int countzeros = 0;
    int countother = 0;

    for(unsigned int i = 0; i < adj.size(); i++) {
        for(unsigned int j = 0; j < adj[i].size(); j++) {
            if(adj[i][j] == 0) {
                countzeros++;
                continue;
            }
           //cout << adj[i][j] << endl;
            countother++;
        }
    } 
    //cout << countzeros << endl;
    //cout << countother << endl;
}

//helper function for debugging and testing
void BFS::addEdge(int x, int y){
    adj[x][y] = 1;
    adj[y][x] = 1;
}


//implements bfs traversal from a given airport id
void BFS::traverse(int start){
    vector<bool> visited(adj.size(),false);

    q.push_back(start);
    visited[start] = true;
    
    int vis;
    int count = 0;
    while(!q.empty()){
        vis = q[0];
        bfs_output.push_back(vis);
        num++;
        q.erase(q.begin());
        count++;
        for(unsigned int i = 0; i < adj[vis].size();i++){
            if(adj[vis][i] != 0 && !visited[i]){
                q.push_back(i);
                visited[i] = true;
            }
        }
    }
    cout << count << endl;
}

//helper function used to verify the successful bfs traversal
void BFS::printBFS() {
    for (unsigned int i = 0; i < bfs_output.size(); i++) {
        cout << airportNames[bfs_output[i]] << endl;
    }
}

//helper function for testing returns the traversal order
vector<int> BFS::output(){
    return bfs_output;
}


//helper function to find the length of this instance of traversal
int BFS::returnNum() {
    return num;
}



