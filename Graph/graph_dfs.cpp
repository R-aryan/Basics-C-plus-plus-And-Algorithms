#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

template<typename T>
class Graph{
public:
    map<T,list<T> >adj;
    Graph(){
    }
    void add_edge(T u,T v,bool bi=true){
        adj[u].push_back(v);
        if(bi)
            adj[v].push_back(u);
    }

    void dfshelper(T node,map<T,bool> &visited){
        visited[node]=true;
        cout<<node<<" ";
        for(T n:adj[node]){
            if(!visited[n]){
                visited[n]=true;
                dfshelper(n,visited);
            }
        }
    }

    void dfs(T src){
        map<T,bool>visited;
        dfshelper(src,visited);

    }

};

int main(){
    Graph<int> g;
    g.add_edge(0,1);
    g.add_edge(0,4);
    g.add_edge(4,3);
    g.add_edge(1,4);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(1,3);
    cout<<"The DFS traversal is...\n";
    g.dfs(0);
}
