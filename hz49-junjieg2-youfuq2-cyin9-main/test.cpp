#include "bfs.h"
#include "Airport.h"
#include "Route.h"
#include "Dijkstra.h"
#include "test.h"
#include "Centrality.h"

using namespace std;


void testBFS1()
{
  vector<vector<double>> test = {
    {0,1,1},
    {1,0,1},
    {1,1,0}
    };
 vector<string> emptyName;
 
 BFS trav(test,emptyName);
 trav.traverse(0);
 vector<int> testoutput = trav.output();

  if(testoutput[0] == 0 && testoutput[1] == 1 && testoutput[2] == 2){
    cout<<"test BFS #1 passed"<<endl;
  }
}

void testBFS2()
{
  vector<vector<double>> test = {
    {0,1,1,0,0},
    {1,0,1,1,0},
    {1,1,0,1,0},
    {0,1,1,0,0}
    };
 
  vector<string> emptyName;
 
 BFS trav(test,emptyName);
  trav.traverse(1);
  vector<int> testoutput = trav.output();
 
 
  if(testoutput[0] == 1 && testoutput[1] == 0 && testoutput[2] == 2){
    cout<<"test BFS #2 passed"<<endl;
  }
}

void testBFS3()
{
  vector<vector<double>> test = {
    {0,1,0,0,0,0,1,0},
    {1,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0},
    {1,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0}

  };
 
 vector<string> emptyName;
 
 BFS trav(test,emptyName);
 trav.traverse(1);
  vector<int> testoutput = trav.output();

  if(testoutput[0] == 1 && testoutput[1] == 0 && testoutput[2] == 5){
    cout<<"test BFS #3 passed"<<endl;
  }
}

void testDijkstra1()
{
  vector< vector <double> > testMatrix;
  testMatrix.resize(6);
  for(unsigned int i = 0; i < testMatrix.size(); i++) {
      testMatrix[i].resize(6);
  }
  testMatrix = {
  {0,1,2,0,0,0},
  {1,0,0,5,1,0},
  {2,0,0,2,3,0},
  {0,5,2,0,2,2},
  {0,1,3,2,0,1},
  {0,0,0,2,1,0}};
  Dijkstra dij (testMatrix);
  dij.DijkstraAlgo(0);
  vector<double> testpath = dij.returnPath();

 
  if(testpath[0] == 0 && testpath[1] == 1 && testpath[2] == 2){
    cout<<"test Dijkstra's algo #1 passed"<<endl;
  }
}

void testDijkstra2()
{
  vector< vector <double> > testMatrix;
  testMatrix.resize(6);
  for(unsigned int i = 0; i < testMatrix.size(); i++) {
      testMatrix[i].resize(6);
  }
  testMatrix = {
    {0,0,0,1,0,0,0,0},
    {0,0,0,1,0,4,7,0},
    {0,0,0,0,9,6,0,0},
    {1,1,0,0,0,5,0,0},
    {0,0,9,0,0,0,0,0},
    {0,4,6,5,0,0,0,0},
    {0,7,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0}
  };
  Dijkstra dij (testMatrix);
  dij.DijkstraAlgo(0);
  vector<double> testpath = dij.returnPath();

 
  if(testpath[0] == 0 && testpath[1] == 2 && testpath[2] == 12){
    cout<<"test Dijkstra's algo #2 passed"<<endl;
  }
}

void testDijkstra3()
{
  vector< vector <double> > testMatrix;
  testMatrix.resize(6);
  for(unsigned int i = 0; i < testMatrix.size(); i++) {
      testMatrix[i].resize(6);
  }
  testMatrix = {
    {0,1,0,2,3,0,0,0},
    {1,0,0,2,0,0,3,0},
    {0,0,0,0,0,0,0,0},
    {2,2,0,0,0,0,0,5},
    {3,0,0,0,0,0,9,0},
    {0,0,0,0,0,0,3,0},
    {0,3,0,0,9,3,0,9},
    {0,0,0,5,0,0,9,0}
  };
  Dijkstra dij (testMatrix);
  dij.DijkstraAlgo(0);
  vector<double> testpath = dij.returnPath();


  if(testpath[0] == 0 && testpath[1] == 1 && testpath[2] >= 1000){
    cout<<"test Dijkstra's algo #3 passed"<<endl;
  }
}

void testCentrality1()
{
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
    Centrality dij(testMatrix);

    dij.betweenCentral(0);
    vector<int> testpath = dij.returnCentral();
 


  if(testpath[0] == 3 && testpath[1] == 4 && testpath[2] == 2){
    cout<<"test betweeness centrality #1 passed"<<endl;
  }
}

void testCentrality2()
{
    vector< vector <double> > testMatrix;
      testMatrix.resize(3);
      for(unsigned int i = 0; i < testMatrix.size(); i++) {
          testMatrix[i].resize(3);
      }
    testMatrix = {
          {0,10,3,0,0},
          {0,0,1,2,0},
          {0,4,0,8,2},
          {0,0,0,0,7},
          {0,0,0,9,0}
            };
    Centrality dij(testMatrix);

    dij.betweenCentral(0);
    vector<int> testpath = dij.returnCentral();
 


if(testpath[0] == 4 && testpath[1] == 7 && testpath[2] == 9){
    cout<<"test betweeness centrality #2 passed"<<endl;
  }

}


