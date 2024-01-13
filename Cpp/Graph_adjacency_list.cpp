#include "header.h"

class graph {
    int nodes,edges;
    bool directed; // checks if the graph is directed or not
    unordered_map<int, list<int> > adj;
    
  public:
    graph(bool);

    void add_edge(int, int);
    void remove_edge(int, int);
    void display_graph();
    void print_nodes();
    void breadth_first_search();
    void depth_first_search();
    void search_depth(int, unordered_map<int, bool>&); // for traversing recursively in dfs
    int nodes_count();
    int edges_count();
    bool has_node(int);
    int degree_of_node(int);
    void clear();
};

graph::graph(bool directed = false) {
    // initializing values
    this->directed = directed;
    this->nodes = this->edges = 0;
}

void graph::add_edge(int u, int v) {
    // if any of the node from both ones is not added already then increase the count of node
    if (adj.count(u) == 0) nodes++;
    if (adj.count(v) == 0) nodes++;

    // adding edge between two nodes if not already present
    if (find(adj[u].begin(), adj[u].end(), v) == adj[u].end()){
        edges++;
        adj[u].push_back(v);
    }

    // adding edge from opposite direction also if the graph is not directed graph and the edge is not present already
    if(!directed && find(adj[v].begin(), adj[v].end(), u) == adj[v].end()) {
        adj[v].push_back(u);
    }
}

void graph::remove_edge(int u, int v) {
    // removing the edge from u to v if there is one present
    if(find(adj[u].begin(), adj[u].end(), v) != adj[u].end()) {
        adj[u].remove(v);
        edges--;
    }

    // removing edge from v to u if the graph is not directed and there is one present
    if(!directed && find(adj[v].begin(), adj[v].end(), u) != adj[v].end()) {
        adj[v].remove(u);
    }
}

// This function prints the graph with all the traversals
void graph::display_graph() {
    // check if the graph is empty or not
    if(adj.empty()) {
        cout << "Graph is empty" << endl;
        return;
    }

    // printing values
    print_nodes();
    cout << endl;
    breadth_first_search();
    cout << endl;
    depth_first_search();
}

void graph::print_nodes() {
    // check if graph has nodes or not
    if(adj.empty()) return;

    // creating with the graph data for sorting
    map<int, list<int> > adj(this->adj.begin(), this->adj.end());

    cout << "Graph : " << endl << endl;

    // printing the graph
    for (auto node : adj){
        cout << node.first + 1 << " -> ";
        for (auto link : node.second)
            cout << link + 1 << ", ";
        cout << endl;
    }
}

void graph::breadth_first_search() {
    // returning if there is no node present in the graph
    if(adj.empty()) return;

    // declaring queue and visited map
    /*
    * queue helps to store all the nodes on the same level
    * visited map helps to store the visited nodes
    */
    queue<int> q;
    unordered_map<int, bool> visited;

    cout << "BFS : ";
    for(auto node : adj){
        // skipping the node if it is already visited
        if(visited[node.first]) continue;

        // putting first node so that while loop will run
        q.push(node.first);
        visited[node.first] = true; // marked it as visited

        while (!q.empty()) {
            // fetching the nodes one by one
            int nodeValue = q.front();
            q.pop();

            cout << nodeValue + 1 << ", ";

            // adding all the non visited nodes to the queue and marking them as visited
            for(auto listValue : adj[nodeValue]) {
                if(!visited[listValue]){
                    visited[listValue] = true;
                    q.push(listValue);
                }
            }
        }
    }
    cout << endl;
}

void graph::depth_first_search() {
    // returing if there is no node present in graph
    if(adj.empty()) return;

    unordered_map<int, bool> visited;

    cout << "DFS : ";

    // traversing all the nodes in the graph if not already visited
    for(auto nodeValues : adj){
        if(!visited[nodeValues.first]) search_depth(nodeValues.first, visited);
    }
    cout << endl;
}

void graph::search_depth(int nodeValue, unordered_map<int, bool> &visited) {
    cout << nodeValue + 1 << ", ";

    visited[nodeValue] = true;

    // traversing all the nodes connected to the current node
    for (auto node : adj[nodeValue]){
        if(!visited[node]) search_depth(node, visited);
    }
}

// clears the data of graph
void graph::clear() {
    // clear the adjacency list
    adj.clear();

    // reset the counts
    nodes = edges = 0;
    directed = false;
}

// checks if node is present in the graph or not
bool graph::has_node(int nodeValue) {
    return adj.count(nodeValue) > 0;
}

// returns the degree of a node
int graph::degree_of_node(int nodeValue) {
    return adj.at(nodeValue).size();
}

int graph::nodes_count() { return this->nodes; } // returns the no. of nodes in the graph
int graph::edges_count() { return this->edges; } // return the no. of edges in the graph

int main(){

    int choice = 0;
    int u, v; // for the nodes values
    bool directed = false;
    char c = '\0';

    cout << endl << "Is the graph directed? (y/n): ";
    cin >> c;

    if(c == 'y' || c == 'Y') directed = true;

    graph g(directed);

    do {
        cout << endl;
        cout << left << setw(30) << "1. Add Edge";
        cout << left << setw(30) << "2. Remove Edge" << endl;
        cout << left << setw(30) << "3. Number of nodes";
        cout << left << setw(30) << "4. Number of edges" << endl;
        cout << left << setw(30) << "5. Display Graph";
        cout << left << setw(30) << "6. Check if Node Exists" << endl;
        cout << left << setw(30) << "7. Degree of a Node";
        cout << left << setw(30) << "8. Clear Graph" << endl;
        cout << left << setw(30) << "9. Exit" << endl;

        cout << endl << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice){
            case 1:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                g.add_edge(u-1, v-1);
                break;

            case 2:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                g.remove_edge(u-1, v-1);
                break;

            case 3:
                cout << "Number of nodes in the graph = " << g.nodes_count() << endl;
                break;

            case 4:
                cout << "Number of edges in the graph = " << g.edges_count() << endl;
                break;

            case 5:
                g.display_graph();
                break;

            case 6:
                cout << "Enter node value: ";
                cin >> u;
                if (g.has_node(u-1)) {
                    cout << "Node " << u << " exists in the graph." << endl;
                } else {
                    cout << "Node " << u << " does not exist in the graph." << endl;
                }
                break;

            case 7:
                cout << "Enter node value: ";
                cin >> u;
                cout << "Degree of node " << u << " = " << g.degree_of_node(u-1) << endl;
                break;

            case 8:
                g.clear();
                cout << "Graph cleared." << endl;
                break;

            case 9:
                break;
            
            default:
                cout << "Enter a valid number!!!!" << endl;
                break;
        }

    } while (choice!=9);
    
    return 0;
}