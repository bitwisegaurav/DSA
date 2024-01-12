#include "header.h"

class graph_matrix {
    int nodes = 0;
    bool directed;
    vector<vector<bool>> adj;
    
  public:
    graph_matrix(int nodes, bool directed = false) {
        this->nodes = nodes;
        this->directed = directed;
        adj.resize(nodes);
        for(int i=0; i<nodes; i++) {
            adj[i].resize(nodes);
            for(int j=0; j<nodes; j++) {
                adj[i][j] = false;
            }
        }
    }

    void add_edge(int u, int v) {
        adj[u][v] = true;
        if(!directed) adj[v][u] = true;
    }

    void remove_edge(int u, int v) {
        adj[u][v] = false;
        if(!directed) adj[v][u] = false;
    }

    void display_graph_matrix() {

        // for formatting 
        cout << right << setw(6) << "" << " | "; 
        for(int i = 0; i < nodes; i++) { 
            cout << right << setw(6) << i+1 << " "; 
        } 
        cout << endl;
        for(int i = 0; i < nodes; i++) { 
            cout << right << setw(6) << "---------"; 
        } 
        cout << endl;

        // printing the values 
        for(int i = 0; i < nodes; i++) { 
            cout << right << setw(6) << i+1 << " | "; 
            for(int j = 0; j < nodes; j++) { 
                if(adj[i][j]) { 
                    cout << right << setw(6) << '*' << " "; 
                } else { 
                    cout << right << setw(6) << '-' << " "; 
                } 
            } 
            cout << endl; 
        }
        cout << endl;
    }
};

int main(){
    
    int n = 0, size = 0;
    bool directed = false;
    char c = '\0';

    cout << "Enter number of nodes: ";
    cin >> size;

    cout << "Is the graph directed? (y/n): ";
    cin >> c;

    if(c == 'y' || c == 'Y') directed = true;

    graph_matrix g(size ? size : 5, directed);

    do {
        cout << "1. Add Edge" << endl;
        cout << "2. Remove Edge" << endl;
        cout << "3. Display Graph" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> n;

        if(n==1) {
            int u, v;
            cout << "Enter edge (u v): ";
            cin >> u >> v;
            g.add_edge(u-1, v-1);
        } 
        else if(n==2) {
            int u, v;
            cout << "Enter edge (u v): ";
            cin >> u >> v;
            g.remove_edge(u-1, v-1);
        }
        else if(n==3) {
            g.display_graph_matrix();
        } 
        else if(n!=4) cout << "Enter a valid number!!!!" << endl;
    } while (n!=4);
    

    return 0;
}