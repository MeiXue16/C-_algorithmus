//graph.cpp
#include <iostream>
#include<fstream>
#include<sstream>
#include<stdexcept>
#include<limits>
#include <list>
#include <stack>
#include <bits/stdc++.h>

#include "graph.h"
using namespace std;

const Graph::NodeId Graph::invalid_node =-1;
const double Graph::infinite_weight =std::numeric_limits<double>::max();

void Graph::add_nodes(NodeId num_new_nodes){
    _nodes.resize(num_nodes()+ num_new_nodes);
}

Graph::Neighbor::Neighbor(Graph::NodeId n, double w): _id(n), _edge_weight(w) {}
Graph::Graph(NodeId num, DirType dtype): dirtype(dtype), _nodes(num) {}

void Graph::add_edge(NodeId tail, NodeId head, double weight){
    if (tail >= num_nodes() or tail<0 or head >= num_nodes() or head<0){
        throw std::runtime_error("Edge cannot be added due to undefined endpoint .");
    }
    _nodes[tail].add_neighbor(head,weight);
    if (dirtype == Graph::undirected){
        _nodes[head].add_neighbor(tail, weight);
    }
}

void Graph::Node::add_neighbor(Graph::NodeId nodeid, double weight){
    _neighbors.push_back(Graph::Neighbor(nodeid, weight));
}

const std::vector<Graph::Neighbor> & Graph::Node::adjacent_nodes() const{
    return _neighbors;
}

Graph::NodeId Graph::num_nodes() const{
    return _nodes.size();
}

const Graph::Node & Graph::get_node(NodeId node) const{
    if (node<0 or node>= static_cast<int>(_nodes.size())){
        throw std::runtime_error("Invalid nodeid in Graph :: get_node .");
    }
    return _nodes[node];
}

Graph::NodeId Graph::Neighbor::id() const{
    return _id;
}

double Graph::Neighbor::edge_weight()const{
    return _edge_weight;
}




// list<int> adj = new list<int> [num_nodes()];
// Graph::Graph(int V)
// {
// 	this->V = V;
// 	adj = new list<int>[V];
// }


// Graph Graph::getTranspose()
// {
// 	Graph g(V);
// 	for (int v = 0; v < V; v++)
// 	{
// 		// Recur for all the vertices adjacent to this vertex
// 		list<int>::iterator i;
// 		for(i = adj[v].begin(); i != adj[v].end(); ++i)
// 		{
// 			g.adj[*i].push_back(v);
// 		}
// 	}
// 	return g;
// }

// void Graph::addEdge(int v, int w)
// {
// 	adj[v].push_back(w); // Add w to v’s list.
// }




void Graph::print() const{
    if(dirtype == Graph::directed){
        std::cout << "Diagraph ";
    }
    else{
        std::cout << "undirected graph ";
    }
    std::cout << "with" << num_nodes() << "vertices , numbered 0 ,... , "
    << num_nodes()-1 << ".\n";
    for(auto nodeid =0; nodeid <num_nodes(); ++nodeid){
        std::cout << "The following edges are ";
        if (dirtype ==Graph::directed){
            std::cout << "leaving";
        }
        else{
            std::cout << "incident to";
        }
        std::cout << " vertex " << nodeid << ":\n";
        for(auto neighbor: _nodes[nodeid].adjacent_nodes()){
            //输出顶点连接关系
            // addEdge(nodeid, neighbor.id());


            std::cout << nodeid << " - " << neighbor.id()
            <<" weight = " << neighbor.edge_weight()<< "\n";
        }
    }
}
vector<vector<int>> adj;
vector<vector<int>> Graph::table(){
    
    for(auto nodeid =0; nodeid <num_nodes(); ++nodeid){
        for(auto neighbor: _nodes[nodeid].adjacent_nodes()){
            //输出顶点连接关系
            // addEdge(nodeid, neighbor.id());
            adj[nodeid].push_back(neighbor.id());
            
        }
    }
    return adj;
}

Graph::Graph(char const * filename, DirType dtype):dirtype(dtype){
    std::ifstream file(filename) ;
    if (not file){
        throw std::runtime_error("cannot open file.");
    }

    Graph::NodeId num =0;
    std::string line;
    std::getline(file, line);
    std::stringstream ss(line);
    ss >>num ;
    if (not ss){
        throw std::runtime_error("Invalid file format.");
    }
    add_nodes(num);

    while (std::getline(file, line)){
        std::stringstream ss(line);
        Graph::NodeId head, tail;
        ss >> tail >> head;
        if (not ss){
            throw std::runtime_error("Invalid file format.");
        }
        double weight =1.0;

        ss >> weight ;
        if (tail != head){
            add_edge(tail, head, weight);
        }
        else{
            throw std::runtime_error(" Invalid file format : loops not allowed .");
        }

    }
}




// The main function that finds and prints all strongly connected
// components
// void Graph::printSCCs()
// {
// 	stack<int> Stack;

// 	// Mark all the vertices as not visited (For first DFS)
// 	bool *visited = new bool[V];
// 	for(int i = 0; i < V; i++)
// 		visited[i] = false;

// 	// Fill vertices in stack according to their finishing times
// 	for(int i = 0; i < V; i++)
// 		if(visited[i] == false)
// 			fillOrder(i, visited, Stack);

// 	// Create a reversed graph
// 	Graph gr = getTranspose();

// 	// Mark all the vertices as not visited (For second DFS)
// 	for(int i = 0; i < V; i++)
// 		visited[i] = false;

// 	// Now process all vertices in order defined by Stack
// 	while (Stack.empty() == false)
// 	{
// 		// Pop a vertex from stack
// 		int v = Stack.top();
// 		Stack.pop();

// 		// Print Strongly connected component of the popped vertex
// 		if (visited[v] == false)
// 		{
// 			gr.DFSUtil(v, visited);
// 			cout << endl;
// 		}
// 	}
// }



void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj2[]) {
    vis[node] = 1; 
    for(auto it: adj2[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj2); 
        }
    }
    
    st.push(node); 
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    cout << node << " "; 
    vis[node] = 1; 
    for(auto it: transpose[node]) {
        if(!vis[it]) {
            revDfs(it, vis, transpose); 
        }
    }
}



int main(){
    Graph g("Graph_1_", Graph::directed);
    g.print();
    int n = g.num_nodes();
    cout << n;
    //g.get_node(6);

    // vector<int> adj2 = g.table();

    // stack<int> st;
	// vector<int> vis(n+1, 0); 
	// for(int i = 1;i<=n;i++) {
	//     if(!vis[i]) {
	//         dfs(i, st, vis, adj2); 
	//     }
	// } 
	
	// vector<int> transpose[n+1]; 
	
	// for(int i = 1;i<=n;i++) {
	//     vis[i] = 0; 
	//     for(auto it: adj2[i]) {
	//         transpose[it].push_back(i); 
	//     }
	// }
	
	
	// while(!st.empty()) {
	//     int node = st.top();
	//     st.pop(); 
	//     if(!vis[node]) {
	//         cout << "SCC: "; 
	//         revDfs(node, vis, transpose); 
	//         cout << endl; 
	//     }
	// }
	
    return 0;

}