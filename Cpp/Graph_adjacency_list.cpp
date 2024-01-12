#include "header.h"

class graph {
    int nodes,edges;
    bool directed;
    unordered_map<int, list<int> > adj;
    
  public:
    graph(bool);

    void add_edge(int, int);
    void remove_edge(int, int);
    void display_graph();
    int nodes_count();
    int edges_count();
};

graph::graph(bool directed = false) {
    this->directed = directed;
    this->nodes = this->edges = 0;
}

void graph::add_edge(int u, int v) {
    if (adj.count(u) == 0) nodes++;
    if (adj.count(v) == 0) nodes++;

    if (find(adj[u].begin(), adj[u].end(), v) == adj[u].end()){
        edges++;
        adj[u].push_back(v);
    }
    if(!directed && find(adj[v].begin(), adj[v].end(), u) == adj[v].end()) {
        adj[v].push_back(u);
    }
}

void graph::remove_edge(int u, int v) {
    if(find(adj[u].begin(), adj[u].end(), v) != adj[u].end()) {
        adj[u].remove(v);
        edges--;
    }
    if(!directed && find(adj[v].begin(), adj[v].end(), u) != adj[v].end()) {
        adj[v].remove(u);
    }
}

void graph::display_graph() {
    map<int, list<int> > adj(this->adj.begin(), this->adj.end());

    cout << "Graph : " << endl << endl;

    for (auto node : adj){
        cout << node.first + 1 << " -> ";
        for (auto link : node.second)
            cout << link + 1 << ", ";
        cout << endl;
    }
}

int graph::nodes_count() { return this->nodes; }
int graph::edges_count() { return this->edges; }

int main(){
    
    int n = 0;
    int u, v;
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
        cout << left << setw(30) << "6. Exit" << endl;

        cout << endl << "Enter your choice: ";
        cin >> n;
        cout << endl;

        switch (n){
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
                break;
            
            default:
                cout << "Enter a valid number!!!!" << endl;
                break;
        }

    } while (n!=6);
    

    return 0;
}