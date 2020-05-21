#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<list>

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

    void dfs_helper(T node,map<T,bool>&visited,list<T>&ordering){
        visited[node]=true;
        for(T neighbour:adj[node]){
            if(!visited[neighbour]){
                dfs_helper(neighbour,visited,ordering);
            }
        }
        ordering.push_front(node);
    }

    void topological_sort_dfs(){
        map<T,bool>visited;
        list<T>ordering;
        for(auto i:adj){
            T node=i.first;
            if(!visited[node]){
                dfs_helper(node,visited,ordering);
            }
        }
        for(T e:ordering){
            cout<<e<<"-->";
        }
    }
};

int main(){
    Graph<string>g;
    g.add_edge("english","programming logic",false);
    g.add_edge("maths","programming logic",false);
    g.add_edge("programming logic","HTML",false);
    g.add_edge("programming logic","python",false);
    g.add_edge("programming logic","java",false);
    g.add_edge("programming logic","js",false);
    g.add_edge("python","web dev",false);
    g.add_edge("HTML","CSS",false);
    g.add_edge("CSS","js",false);
    g.add_edge("js","web dev",false);
    g.add_edge("java","web dev",false);
    g.add_edge("python","web dev",false);

    g.topological_sort_dfs();

}
