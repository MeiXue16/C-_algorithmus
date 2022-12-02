// graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#include <list>
#include <stack>

using namespace std;

class Graph {

public:
    using NodeId = int;
    
    // Graph(int V);
	// void addEdge(int v, int w);

	// // The main function that finds and prints strongly connected
	// // components
	// void printSCCs();

    // void Graph::fillOrder(int v, bool visited[], stack<int> &Stack){
	// // Mark the current node as visited and print it
    //     visited[v] = true;

    //     // Recur for all the vertices adjacent to this vertex
    //     list<int>::iterator i;
    //     for(i = adj[v].begin(); i != adj[v].end(); ++i)
    //         if(!visited[*i])
    //             fillOrder(*i, visited, Stack);

    //     // All vertices reachable from v are processed by now, push v
    //     Stack.push(v);
    // }
    // // A recursive function to print DFS starting from v
    // void Graph::DFSUtil(int v, bool visited[])
    // {
    //     // Mark the current node as visited and print it
    //     visited[v] = true;
    //     cout << v << " ";

    //     // Recur for all the vertices adjacent to this vertex
    //     list<int>::iterator i;
    //     for (i = adj[v].begin(); i != adj[v].end(); ++i)
    //         if (!visited[*i])
    //             DFSUtil(*i, visited);
    // }

	// // Function that returns reverse (or transpose) of this graph
	// Graph getTranspose();
    // //list<int> *adj; // An array of adjacency lists

    class Neighbor {
    public:
        Neighbor(Graph::NodeId n, double w);
        double edge_weight() const;
        Graph::NodeId id() const;
    private:
        Graph::NodeId _id;
        double _edge_weight ;
    };

    class Node{
    public:
        void add_neighbor(Graph::NodeId nodeid, double weight);
        const std::vector<Neighbor> & adjacent_nodes() const;
    private:
        std::vector<Neighbor> _neighbors ;
    };

    enum DirType {directed, undirected};
    Graph(NodeId num_nodes, DirType dirtype);
    Graph(char const* filname, DirType dirtype);

    void add_nodes(NodeId num_new_nodes);
    void add_edge(NodeId tail, NodeId head, double weight=1.0);

    NodeId num_nodes() const;
    const Node & get_node(NodeId) const;
    void print() const;
    std::vector<vector<int>> table();

    const DirType dirtype;
    static const NodeId invalid_node;
    static const double infinite_weight;

private:
    std::vector<Node> _nodes ;
    // int V; // No. of vertices
	// list<int> *adj; // An array of adjacency lists

	// // Fills Stack with vertices (in increasing order of finishing
	// // times). The top element of stack has the maximum finishing
	// // time
	// void fillOrder(int v, bool visited[], stack<int> &Stack);

	// // A recursive function to print DFS starting from v
	// void DFSUtil(int v, bool visited[]);


};

#endif