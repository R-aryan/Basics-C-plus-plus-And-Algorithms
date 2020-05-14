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

    bool is_cyclic_helper(T node,map<T,bool>&visited,map<T,bool>&instack){
        visited[node]=true;
        instack[node]=true;

        for(T neighbour:adj[node]){
            if(!visited[neighbour]&& is_cyclic_helper(neighbour,visited,instack)||instack[neighbour]){
                return true;
            }
        }
        instack[node]=false;
        return false;
    }

    bool is_cyclic(){
        map<T,bool>visited;
        map<T,bool>instack;
        for(auto i:adj){
            T node=i.first;
            if(!visited[node]){
                bool cip=is_cyclic_helper(node,visited,instack);
                if(cip)
                    return true;
            }
        }
        return false;
    }
};

int main(){
    Graph<int>g;
    g.add_edge(0,2,false);
    g.add_edge(0,1,false);
    g.add_edge(2,3,false);
    g.add_edge(2,4,false);
    g.add_edge(3,0,false);
    g.add_edge(4,5,false);
    g.add_edge(1,5,false);

    bool r= g.is_cyclic();
    if(r)
        cout<<"Cycle is found";
    else
        cout<<"Cycle not found";
}
