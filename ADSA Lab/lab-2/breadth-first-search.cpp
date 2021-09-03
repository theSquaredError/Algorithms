/*
Problem - Given an unweighted graph G and a source vertex s, write a program to perform BFS
		(breadth first search) using queue data-structure and compute the distances of all the
		vertices from s.
*/

#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph{
	int V;
	// array of list
	list<int> *l;
public:
	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x, int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void printAdjList(){
		// Iterate over all the vertices
		for(int i=0; i<V;i++){
			cout<<"Vertex "<< i <<"->";
			for(int nbr: l[i]){
				cout<<nbr<<" ";
			}
			cout<<endl;
		}
	}

	void breadthFirstTraversal(int s){
		bool *visited = new bool[V];
		for(int i;i<V;i++){
			visited[i] = false;
		}

		queue<int> Q;
		Q.push(s);
		visited[s] = true;

		while(!Q.empty()){
			s = Q.front();
        	cout << s << " ";
        	Q.pop();

        	for(int nbr: l[s]){
        		if(!visited[nbr]){
        			visited[nbr] = true;
        			Q.push(nbr);
        		}
        	}

		}
	}
};



int main(){

	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(1,2);
	g.printAdjList();

	g.breadthFirstTraversal(0);
	return 0;
}



/*

 
// Data structure to store a graph edge
struct Edge {
    int src, dest;
};
 
// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to hold `N` elements of type `vector<int>`
        adjList.resize(N);
 
        // add edges to the directed graph
        for (auto &edge: edges)
        {
            // insert at the end
            adjList[edge.src].push_back(edge.dest);
 
            // uncomment the following code for undirected graph
            // adjList[edge.dest].push_back(edge.src);
        }
    }
};
 
// Function to print adjacency list representation of a graph
void printGraph(Graph const &graph, int N)
{
    for (int i = 0; i < N; i++)
    {
        // print the current vertex number
        cout << i << " ——> ";
 
        // print all neighboring vertices of a vertex `i`
        for (int v: graph.adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}
 
// Graph Implementation using STL
int main()
{
    // vector of graph edges as per the above diagram.
    // Please note that the initialization vector in the below format will
    // work fine in C++11, C++14, C++17 but will fail in C++98.
    vector<Edge> edges =
    {
        { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
        { 3, 2 }, { 4, 5 }, { 5, 4 }
    };
 
    // total number of nodes in the graph
    int N = 6;
 
    // construct graph
    Graph graph(edges, N);
 
    // print adjacency list representation of a graph
    printGraph(graph, N);
 
    return 0;
}


*/