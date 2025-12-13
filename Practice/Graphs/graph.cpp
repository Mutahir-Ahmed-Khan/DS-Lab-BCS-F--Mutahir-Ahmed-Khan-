#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
    private:
        int V; //Total Vertices in a Graph
        list<int> *arr; //Store a list on every index of arr

    public:
        Graph(int v){
            V = v;
            arr = new list<int>[v];
        }

        void addEdges(int u, int v){
            arr[u].push_back(v); 
            arr[v].push_back(u);
        }

        void printAL(){
            for(int i = 0; i < V; i++){
                cout << i << " : ";
                for(int o : arr[i]){
                    cout << o << " ";
                }
                cout << endl;
            }
        }

        //--------------- BFS & DFS --------------------//
        void BFS(){
            queue<int> q;
            bool *vis;

            vis = new bool[V];
            for(int i = 0; i < V; i++){
                vis[i] = false;
            }

            q.push(0); //Source
            vis[0] = true;

            while(q.size() > 0){
                int temp = q.front();
                cout << temp << " ";
                q.pop();
                for(int neigh : arr[temp]){
                    if(!vis[neigh]){
                        vis[neigh] = true;
                        q.push(neigh);
                    }
                }
            }

            cout << endl;
        }

    void DFSHelper(int u, bool *vis){
        cout << u << " ";
        vis[u] = true;

        for(int neigh : arr[u]){
            if(!vis[neigh]){
                DFSHelper(neigh, vis);
            }
        }
    }

    void DFS(){
        int u = 0;
        bool *vis = new bool[V];
        for(int i = 0; i < V; i++){
            vis[i] = false;
        }

        DFSHelper(u,vis);
        cout << endl;
    }

    //---------------- CYCLE DETECTION UNDIRECTED -----------------//
    bool isCycleUndDFS(int src, int par, bool *vis ){
        vis[src] = true;

        for(int neigh : arr[src]){
            if(!vis[neigh]){
                if(isCycleUndDFS(neigh,src,vis)){
                    return true;
                }
            }
            else if(neigh != par){
                return true;
            }
        }

        return false;
    }

    bool isCycle(){
        bool *vis = new bool[V];
        for(int i = 0; i < V; i++){
            vis[i] = false;
        }

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(isCycleUndDFS(1, -1, vis)){
                    return true;
                }
            }
        }

        return false; 
    }
};


int main(){
    Graph g(5);

    g.addEdges(0,1);
    // g.addEdges(0,2);
    g.addEdges(0,3);
    g.addEdges(1,2);
    g.addEdges(3,4);

    g.printAL();

    cout << endl;
    cout << "BFS : ";
    g.BFS();

    cout << endl;
    cout << "DFS : ";
    g.DFS();

    cout << endl;
    if(g.isCycle()){
        cout << "Cycle is Present" << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }


return 0;
}
