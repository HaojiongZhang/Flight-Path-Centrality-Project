## Development Log: 



progress made:

## week of Nov 22th

1. Created code that reads from the .dat files from the dataset and catgorize them into vectors in main.cpp (data acquisition and cleaning).

2. Created Airport class that holds the airports' names, ID, Latitude and Longitude in Airport.cpp and Airport.h.

3. Created Route class that stores the ID of source and destination airports of the routes from the dataset. It contains a method that computes the distance between airports for weights in our graph.

4. Created code that implements an adjacency matrix in main.cpp to aid our graph algorithm, with weight of the edges created from source and destination ID(the distance between airports) filling the corresponding positions.

5. Created Makefile that compiles and test our code.

## week of Nov 29th

1. Created and tested breath first traversal algorithm (implemented through adjacency matrix)

2. Created and tested dijkstra's algorithm (implemented also through adjacency matrix)

## week of Dec 6th

1. Finished test cases for Breadth First Traversal and Djikstra's Algorithm

2. Finished code implementation and test cases for Betweenness Centrality Algorithm

3. Started Code implementation for visual implementation

## week of Dec 12

1. Finished Code Implementation for visual implementation

2. Re-orginized main for better demo experience

3. Fixed bugs on Betweeness Centrality and made concatenated connected component matrix to demo
