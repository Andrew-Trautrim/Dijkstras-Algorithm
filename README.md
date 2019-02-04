# Dijkstras-Algorithm
Dijkstra's algorithm is an algorithm for finding the shortest path between two specified nodes on a given graph; the graph doesn't necessarily need to be complete or undirected.   
The algorithm goes as follows:  
1. Mark all nodes unvisited and the initial node, in this case node 0, to visited.
2. Assign each node a distance value: set it to zero for the initial node and infinity for all other nodes.
3. For the current node, calculate the distance to all of its unvisited neighbors. Compare the newly calculated distance to the current assigned value and assign the smaller one.
4. When finished evaluating the unvisited neighbors of the current node, mark the current node as visited.  
5. If the destination node has been visited or if the smallest distance among the unvisited nodes is infinity i.e. there is no possible connection to the specified destination node, then stop.  
6. If unfinished, select the unvisited node that is marked with the smallest distance, set it as the current node and go back to step 3.
