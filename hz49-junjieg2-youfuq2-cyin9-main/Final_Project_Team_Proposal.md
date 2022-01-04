# Final Project Team Proposal
## (hz49-junjieg2-youfuq2-cyin9)

## Leading Question
The fast trend of globalization has significantly enhanced the interconnection between countries in the contemporary world, and it is more convenient for an individual to travel intercontinentally or domestically. The question now arises -- how can a passenger choose the most optimized routine when he/she wants to travel to another country? Our team seeks to establish a general search tool that combines the OpenFlights data sets provided with graph algorithm and traverse algorithm to provide customers with graphical representations of the shortest traversal path between any two airports. Furthermore, the general search tool might realize additional functions such as calculating travel distance as well as display the priorities of airports.

## Dataset Acquisition and Processing
From the provided website https://openflights.org/data.html, we plan on using the
airport data set, which includes the name of the airports, the country where the airport locates, as well as the latitude and longitude of individual airports. We will download the CSV file and perform possible research on how to process and read the datas from CSV using C++. At this stage, we are planning to utilize two forms of data, one data type is string that used to store the name of the country as well as airport, and the other one is float that used to store the longitude and latitude of the airport and we will combine three in a single tree node. There might be alternative ways to process and we will research on the one that has the maximum efficiency. For the data cleaning process, we will read the CSV file and eradicate any data with inappropriate formats, NULL values, and mismatched information before we import the file into our real project.

## Graph Algorithms
We plan on implementing a breadth first search as our graph traversal which has a running time of O(V+E) since every edge and vertex will be cheched once. The underlying mechanism we are considering is that when we are given a specific airport as a startpoint, we are determined to find all possible paths to reach a specific destination and choose the path that has the smallest distance. 

For finding the shortest path between airports, we plan on implementing Dijkstra's algorithm with run time O(|V|^2) and flight route distance as weights, which produces a shortest-path tree from a given source as root, which we can extract the desired path.

For the algorithm that isn’t covered in class, we plan on demonstrating betweenness centrality by modifying the Dijkstra's algorithm with runtime O(|V|^3) so that we are able to find all the shortest paths between two nodes. By looking at the data later we may opt into picking the Johnson's algorithm or Brandes' algorithm with a shorter sun time of O(|V|^2+|V||E|) time though it might be unlikely that the flight route data turn out to be a sparese graph. By finding the shortest paths that pass through a given vertex (in this case the number of flights routes that pass through a given airport). By finding the degree to which nodes stand between each other we can get a sense of how important a given airport is.

For our graph representation, the vertices will be airports, and the edges (weights) will be the distance between two vertices (flight route between two airports). The shorter the distance, the greater the weight. We will try to find the data for the flight routes. If that is unsuccessful we can manually calculate the direct distance with the latitude and longitude of the respective airports.The direction of the edges will be assigned accordingly with given flight.

## Timeline
Week of 11/7: 
Acquire the necessary data set and convert it into usable format such as CSV
Week of 11/14:
Finish data cleaning and setups
Finish working on graph traversal, checked using appropriate test cases
Week of 11/21:
Finish graph data algorithm #1, checked using appropriate test cases
Week of 11/28:
Finish graph data algorithm #2, checked using appropriate test cases
Week of 12/5:
Finish graphical output and wrap up our presentation
