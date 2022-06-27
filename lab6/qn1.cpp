#include<bits/stdc++.h>
using namespace std;

// Creating shortcut for an integer pair
typedef  pair<int, int> iPair;

// Structure to represent a graph
struct Graph
{
    int V, E;
    vector< pair<int, iPair> > edges;

    // Constructor
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    // Utility function to add an edge
    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }

    // Function to find MST using Kruskal's
    // MST algorithm
    int kruskalMST();
};

// To represent Disjoint Sets
struct DisjointSets
{
    int *parent, *rnk;
    int n;

    // Constructor.
    DisjointSets(int n)
    {
        // Allocate memory
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];

        // Initially, all vertices are in
        // different sets and have rank 0.
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;

            //every element is parent of itself
            parent[i] = i;
        }
    }
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

 // Functions returns weight of the MST
 void _3aGraph(){
     int V = 11, E = 17;
    Graph g(V, E);

    //  making above shown graph
    g.addEdge(0, 1, 80);
    g.addEdge(0, 5, 25);
    g.addEdge(0, 6, 21);
    g.addEdge(1, 2, 60);
    g.addEdge(1, 3, 25);
    g.addEdge(2, 3, 55);
    g.addEdge(3, 4, 35);
    g.addEdge(3, 5, 40);
    g.addEdge(4, 9, 70);
    g.addEdge(4, 10, 20);
    g.addEdge(4, 5, 20);
    g.addEdge(5, 6, 23);
    g.addEdge(6, 7, 10);
    g.addEdge(6, 10, 30);
    g.addEdge(7, 8, 30);
    g.addEdge(8, 10, 12);
    g.addEdge(8, 9, 45);

    cout<<"3(A)"<<endl;
    cout<<"Vertices are: \n0-Dyer\n1-Manhattan\n2-Warm Springs\n3-Tonopah\n4-Goldfield\n5-Silver Pea\n6-Oasis\n7-Deep Springs\n8-Gold Point\nBeatty\nLida"<<endl;

    cout << "Edges of MST are \n";
    int mst_wt = g.kruskalMST();

    cout << "\nWeight of MST is " << mst_wt;

 }

 void _3bGraph(){
         cout<<"3(B)"<<endl;
    int V = 5, E = 8;
    Graph g(V, E);
    cout<<"Verices are:\n0-a\n1-b\n2-c\n3-d\n4-e"<<endl;

    cout << "Edges of MST are \n";
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 4, 2);
    g.addEdge(1, 4, 3);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 2);
    int mst_wt = g.kruskalMST();

    cout << "\nWeight of MST is " << mst_wt;
 }

void _3cGraph(){
    int V = 9, E = 17;
    Graph g(V, E);

    cout<<"3(C)"<<endl;
    cout<<"Verices are:\n0-a\n1-b\n2-c\n3-d\n4-e\nf-5\ng-6\nh-7\ni-8"<<endl;

    g.addEdge(0, 1, 5);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 4);
    g.addEdge(1, 3, 3);
    g.addEdge(1, 4, 5);
    g.addEdge(1, 5, 6);
    g.addEdge(2, 5, 3);
    g.addEdge(3, 4, 7);
    g.addEdge(3, 6, 6);
    g.addEdge(3, 7, 8);
    g.addEdge(4, 5, 1);
    g.addEdge(4, 7, 3);
    g.addEdge(5, 7, 4);
    g.addEdge(5, 8, 4);
    g.addEdge(6, 7, 4);
    g.addEdge(7, 8, 2);


    cout << "Edges of MST are \n";
    int mst_wt = g.kruskalMST();

    cout << "\nWeight of MST is " << mst_wt;
}

int Graph::kruskalMST()
{
    int mst_wt = 0; // Initialize result

    // Sort edges in increasing order on basis of cost
    sort(edges.begin(), edges.end());

    // Create disjoint sets
    DisjointSets ds(  V    ) ;

    // Iterate through all sorted edges
    vector< pair<int, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if (set_u != set_v)
        {
            cout << u << " - " << v << endl;

            // Update MST weight
            mst_wt += it->first;

            // Merge two sets
            ds.merge(set_u, set_v);
        }
    }

    return mst_wt;
}

// Driver program to test above functions
int main()
{
    // Let us create above shown weighted
       //and undirected graph
    /*
    int V = 11, E = 17;
    Graph g(V, E);

    //  making above shown graph
    g.addEdge(0, 1, 80);
    g.addEdge(0, 5, 25);
    g.addEdge(0, 6, 21);
    g.addEdge(1, 2, 60);
    g.addEdge(1, 3, 25);
    g.addEdge(2, 3, 55);
    g.addEdge(3, 4, 35);
    g.addEdge(3, 5, 40);
    g.addEdge(4, 9, 70);
    g.addEdge(4, 10, 20);
    g.addEdge(4, 5, 20);
    g.addEdge(5, 6, 23);
    g.addEdge(6, 7, 10);
    g.addEdge(6, 10, 30);
    g.addEdge(7, 8, 30);
    g.addEdge(8, 10, 12);
    g.addEdge(8, 9, 45);

    cout<<"3(A)"<<endl;
    cout<<"Vertices are: \n0-Dyer\n1-Manhattan\n2-Warm Springs\n3-Tonopah\n4-Goldfield\n5-Silver Pea\n6-Oasis\n7-Deep Springs\n8-Gold Point\nBeatty\nLida"<<endl;

    cout << "Edges of MST are \n";
    int mst_wt = g.kruskalMST();

    cout << "\nWeight of MST is " << mst_wt;

    cout<<"3(B)"<<endl;
    int V = 5, E = 8;
    Graph g(V, E);
    cout<<"Verices are:\n0-a\n1-b\n2-c\n3-d\n4-e"<<endl;

    cout << "Edges of MST are \n";
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 4, 2);
    g.addEdge(1, 4, 3);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 2);
    int mst_wt = g.kruskalMST();

    cout << "\nWeight of MST is " << mst_wt;
   */


    // int V = 9, E = 17;
    // Graph g(V, E);

    // cout<<"3(C)"<<endl;
    // cout<<"Verices are:\n0-a\n1-b\n2-c\n3-d\n4-e\nf-5\ng-6\nh-7\ni-8"<<endl;

    // g.addEdge(0, 1, 5);
    // g.addEdge(0, 3, 2);
    // g.addEdge(1, 2, 4);
    // g.addEdge(1, 3, 3);
    // g.addEdge(1, 4, 5);
    // g.addEdge(1, 5, 6);
    // g.addEdge(2, 5, 3);
    // g.addEdge(3, 4, 7);
    // g.addEdge(3, 6, 6);
    // g.addEdge(3, 7, 8);
    // g.addEdge(4, 5, 1);
    // g.addEdge(4, 7, 3);
    // g.addEdge(5, 7, 4);
    // g.addEdge(5, 8, 4);
    // g.addEdge(6, 7, 4);
    // g.addEdge(7, 8, 2);


    // cout << "Edges of MST are \n";
    // int mst_wt = g.kruskalMST();

    // cout << "\nWeight of MST is " << mst_wt;
    _3aGraph();
    cout<<endl;

    _3bGraph();
    cout<<endl;

    _3cGraph();

    return 0;
}