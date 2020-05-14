#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<string>
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

    void dfshelper(T node,map<T,bool>&visited){
        visited[node]=true;
        cout<<node<<" ";
        for(auto n:adj[node]){
            if(!visited[n]){
                visited[n]=true;
                dfshelper(n,visited);
            }
        }

    }
    void dfs(T src){
        int c=1;
        map<T,bool>visited;
        dfshelper(src,visited);
        cout<<endl;
        for(auto i:adj){
            T city=i.first;
            if(!visited[city]){
                dfshelper(city,visited);
                c++;
            }
        }
        cout<<endl;
        cout<<"The given graph has... "<<c<<" components...\n";
    }

};

int main(){
    Graph<string>g;
    g.add_edge("Amritsar","Jaipur");
    g.add_edge("Amritsar","Delhi");
    g.add_edge("Delhi","Jaipur");
    g.add_edge("Mumbai","Jaipur");
    g.add_edge("Mumbai","Bhopal");
    g.add_edge("Delhi","Bhopal");
    g.add_edge("Mumbai","Banglore");
    g.add_edge("Agra","Delhi");
    g.add_edge("Andaman","Nicobar");

    g.dfs("Amritsar");


}
