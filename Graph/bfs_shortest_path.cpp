#include<iostream>
#include<map>
#include<list>
#include<string>
#include<queue>
using namespace std;

template<typename T>
class Graph{
public:

    map<T,list<T> > adj;
        Graph(){
        }
        void add_edge(T u,T v,bool bi=true){
            adj[u].push_back(v);
            if(bi)
                adj[v].push_back(u);

        }
        void print_graph(){
            for(auto i:adj){
                cout<<i.first<<"-> ";
                for(auto entry:i.second){
                    cout<<entry<<" ,";
                }
                cout<<endl;
            }
        }

        void bfs_traversal_shortest_path(T src){
            queue<T>q;
            map<T,int>dist;
            map<T,T>parent;
            for(auto i:adj){
                dist[i.first]=INT_MAX;
            }
            q.push(src);
            dist[src]=0;
            parent[src]=src;

            while(!q.empty()){
                T node=q.front();
                cout<<node<<"  ";
                q.pop();
                for(auto n:adj[node]){
                    if(dist[n]==INT_MAX){
                        q.push(n);
                        dist[n]=dist[node]+1;
                        parent[n]=node;

                    }
                }
            }
            for(auto i:adj){
                T node=i.first;
                cout<<"Distance of "<<node<<"  from "<<src<<" is "<<dist[node]<<endl;
            }

        }


};

int main(){
    /*Graph<string> g;
    g.add_edge("Putin","Trump",false);
    g.add_edge("Putin","Modi",false);
    g.add_edge("Putin","Pope",false);
    g.add_edge("Modi","Trump",true);
    g.add_edge("Modi","Yogi",true);
    g.add_edge("Yogi","Prabhu",false);
    g.add_edge("Prabhu","Modi",false);

    cout<<"The BFS graph traversal is...\n\n";
    //g.print_graph();
    g.bfs_traversal("Putin");
    cout<<"\n\n";*/

    Graph<int>g1;
    g1.add_edge(0,1);
    g1.add_edge(1,2);
    g1.add_edge(0,4);
    g1.add_edge(2,4);
    g1.add_edge(3,5);
    g1.add_edge(2,3);
    g1.add_edge(3,4);

    cout<<"The BFS graph traversal is...\n\n";
    //g.print_graph();
    g1.bfs_traversal_shortest_path(0);

}
