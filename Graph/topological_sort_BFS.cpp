#include<iostream>
#include<string>
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
    void topological_sort_bfs(){
        queue<T>q;
        map<T,bool>visited;
        map<T,int>ind;
        for(auto i:adj){
            T node=i.first;
            visited[node]=false;
            ind[node]=0;

        }

        for(auto i:adj){
            T u=i.first;
            for(T v:adj[u]){
                ind[v]++;
            }
        }

        ///find all the nodes with 0 indegree
        for(auto i:adj){
            T node=i.first;
            if(ind[node]==0)
                q.push(node);
        }
        ///implement algorithm
        while(!q.empty()){
            T node=q.front();
            q.pop();
            cout<<node<<"-->";
            for(T neigh:adj[node]){
                ind[neigh]--;
                if(ind[neigh]==0)
                    q.push(neigh);
            }
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

    g.topological_sort_bfs();

}
