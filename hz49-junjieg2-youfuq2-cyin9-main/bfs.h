#include <iostream>
#include <vector>

using namespace std;

class BFS{
    private:
        vector<vector<double>> adj;  //adjacency matrix used for traversal
        vector<int> q;                 //vector used for bfs (effectively a queue)
        vector<string> airportNames;  //airport Names mapped to it's given id
        vector<int> bfs_output; // store all the index of traveled airports.
        int num;

    public:
        BFS();   //default constructor
        BFS(vector< vector <double> > copyMatrix, vector <string> copyNames);   //copy constructor for dataset
        void printMatrix();   //printMatrix for debugging
        void addEdge(int x, int y);   //helper function for testing
        void traverse(int start);   //bfs traversal algo input: start node   output: traversed node
        void printBFS();  
        vector<int> output();
        int returnNum();
        
};
