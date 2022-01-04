# hz49-junjieg2-youfuq2-cyin9
Final project for hz49-junjieg2-youfuq2-cyin9

# Code Base

The code is seperated in the five major catagories:
  1. Data Aquisition:
          Airport.cpp Airport.h Route.cpp Route.h
          
  3. Breadth First Search Traversal: 
          bfs.cpp bfs.h
          
  3. Dijkstra's Algorithm & Betweeness Centrality Algorithm:
          Dijkstra.cpp Dijkstra.h
          
  4. Test Cases: 
          test.cpp test.h 

  5. Graphic Representation:
          Projection.cpp Projection.h

# Main Commands:
In main.cpp we have provided demonstrations of our bfs traversal, Dijkstra's algorithm, Betweeness
Centrality algorithm and means of testing for the three main coding goals with easy to read notices 

Compile:  make -f Makefile.mk

Run:            ./airports

We showcase all the airports that can be traversed by BFS from a user-specified starting Airport ID

A shortest distance from arbitary source and destination airports

Easier-to-read Betweeness centrality property of the largest connected componet of the given dataset


# Test Cases:
For the test cases we used scaled down reproducable adjacency matrices as substitute for our large data
set. The output traversal/shortest path/centrality value is then compared to the intended output.

# Miscellaneous:

For development progress see Devlog1.md

For general summery see Final_Project_Report.md
