// C++ program for Dijkstra's single source shortest path
// algorithm.The program is for adjacency matrix
// representation of the graph.
#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
//(2(A))
#define V 6
//(2(B))#define V 8

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++)
        if (sptSet[i] == false && dist[i] <= min)
            min = dist[i], min_index = i;
    return min_index;
}

// Function to print shortest path from source to j using
// parent array
void printPath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    cout << j << " ";
}

// A utility function to print the constructed distance
// array
int printSolution(int dist[], int n, int parent[])
{
    int src = 0;
    cout << "Vertex\t Distance\tPath";
    for (int i = 1; i < V; i++) {
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i],
               src);
        printPath(parent, i);
    }
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    // The output array. dist[i] will hold the shortest
    // distance from src to i
    int dist[V];

    // sptSet[i] will true if vertex i is included / in
    // shortest path tree or shortest distance from src to i
    // is finalized
    bool sptSet[V] = { false };

    // Parent array to store shortest path tree
    int parent[V] = { -1 };

    // Initialize all distances as INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in first iteration.
        int u = minDistance(dist, sptSet);
        // Mark the picked vertex as processed
        sptSet[u] = true;
        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)
            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v]
                && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    // print the constructed distance array
    printSolution(dist, V, parent);
}

// Driver Code
int main()
{
    // Let us create the example graph discussed above
    cout<<"2(A)"<<endl;
    cout<<"The vertices are:\n0-a\n1-b\n2-c\n3-d\n4-e\n5-f\n"<<endl;
    int graph[V][V] = { { 0, 2, 3, 0, 0, 0 },
                        { 2, 0, 0, 5, 2, 0 },
                        { 3, 0, 0, 0, 5, 0 },
                        { 0, 5, 0, 0, 1, 2},
                        { 0, 2, 0, 1, 0, 4},

                        { 0, 0, 0, 2, 4, 0} };
    dijkstra(graph, 0);

    /*
    cout<<"2(B)"<<endl;
    cout<<"The vertices are:\n0-a\n1-b\n2-c\n3-d\n4-e\n5-f\n6-g\n7-z"<<endl;
    int graph[V][V] = { { 0, 4, 3, 0, 0, 0, 0, 0 },
                        { 4, 0, 2, 5, 0, 0, 0, 0 },
                        { 3, 2, 0, 3, 6, 0, 0, 0 },
                        { 0, 5, 3, 1, 5, 0, 0, 0},
                        { 0, 0, 6, 1, 0, 0, 5, 0},
                        { 0, 0, 0, 5, 0, 0, 2, 7},
                        { 0, 0, 0, 0, 5, 2, 0, 4},
                        { 0, 0, 0, 0, 0, 7, 4, 0} };
    dijkstra(graph, 0);
    */
    return 0;
}