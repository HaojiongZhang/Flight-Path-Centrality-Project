#include "Centrality.h"

//constructor for test case
Centrality::Centrality(vector< vector <double> > copyMatrix) {
    adj.resize(copyMatrix.size());
    for(unsigned int i = 0; i < adj.size(); i++) {
        adj[i].resize(copyMatrix[i].size());
    }

    for(unsigned int j = 0; j < adj.size(); j++) {
        for(unsigned int k = 0; k < adj[j].size(); k++) {
            adj[j][k] = copyMatrix[j][k];
        }
    }
    centrality.resize(copyMatrix.size(),0);
    parent.resize(copyMatrix.size(),-1);
    distance.resize(copyMatrix.size());
    Tset.resize(copyMatrix.size());
}

//constructor for open flight data
Centrality::Centrality(vector< vector <double> > copyMatrix, vector <int> start) {
    adj.resize(copyMatrix.size());
    for(unsigned int i = 0; i < adj.size(); i++) {
        adj[i].resize(copyMatrix[i].size());
    }

    for(unsigned int j = 0; j < adj.size(); j++) {
        for(unsigned int k = 0; k < adj[j].size(); k++) {
            adj[j][k] = copyMatrix[j][k];
        }
    }
    centrality.resize(copyMatrix.size(),0);
    parent.resize(copyMatrix.size(),-1);
    distance.resize(copyMatrix.size());
    Tset.resize(copyMatrix.size());
}

//helper function for dijkstra that calculates min distance
int Centrality::miniDist(vector<double> distance, vector<bool> Tset) {
    int minimum = 1000000, ind;

    for(unsigned int i = 0; i < distance.size(); i++) {
        if(!Tset[i] && distance[i] <= minimum) {
            minimum = distance[i];
            ind = i;
        }
    }
    return ind;
}

//betweenness Centrality Algorithm applied to the whole graph
int Centrality::betweenCentral(int id){
    for (size_t i = 0; i< centrality.size(); i++){
     cout<< "Starting BCT iteration on vertex" << i << endl;
     bctHelper(i);
    }
    return centrality[id];
}

//Helper Function for BCA
void Centrality::bctHelper(int start){
    for(unsigned int k = 0; k < distance.size(); k++) {
        distance[k] = 1000000;
        Tset[k] = false;
    }
    for(size_t i = 0; i < parent.size(); i++){
        parent[i] = -1;
    }
    int r;
    distance[start] = 0;
    parent[start] = -2;
    for(unsigned int k = 0; k < Tset.size(); k++) {
        int m = miniDist(distance, Tset);   
        Tset[m] = true;
        for(unsigned int k = 0; k < distance.size(); k++) {
           if(!Tset[k] && adj[m][k] && distance[m] != 1000000 && distance[m] +adj[m][k] < distance[k]) {
               if(parent[k] == -1){
                    parent[k] = m;
                    centrality[k]++;
                    
                    r = m;
                    while(parent[r] != -2){
                        centrality[r] ++;
                        r = parent[r];
                    }
                    centrality[r]++;
                } else{
                    //delete original path
                    
                    centrality[k]--;
                    r = parent[k];
                    while(parent[r] != -2){
                        
                        centrality[r]--;
                        r = parent[r];

                    }
                    centrality[r] --;

                    //update parent
                    parent[k]=m;

                    //update new shortest path
                    centrality[k] ++;
                    
                    r = m;
                    while(parent[r] != -2){
                        centrality[r]++;
                        r = parent[r];
                    }
                    centrality[r]++;
                }
                distance[k] = distance[m] + adj[m][k];

                
           }
        }
    }
}
//print out weights
void Centrality::central(){
    for(unsigned int i = 0; i < centrality.size(); i++) {
          cout << centrality[i] << endl;
    }
}
//return weights of BCA
vector<int> Centrality::returnCentral(){
    return centrality;
}

