#include <vector>
#include <iostream>

using namespace std;

class Centrality {
    public:
        Centrality(vector< vector  <double> > copyMatrix);  //Copy constructor for test case
        Centrality(vector< vector  <double> > copyMatrix, vector <int> start);  //Copy constructor for main data
        int miniDist(vector<double> distance, vector<bool> Tset);  //helper function that calculates the min distance
        int betweenCentral(int id);  //Between Centrality Algo that loops through the given id
        void bctHelper(int start);  //helper function for BCA
        void central();  //helper function for debugging
        void largestCon(vector<int> path); //helper function for debugging
        vector<int> returnCentral();  //returns the weights of the given graph

    private:
        vector<vector<double>> adj;
        vector<int> startList;
        vector<double> distance;
        vector<bool> Tset;
        vector<int> centrality;
        vector<int> parent;
};



