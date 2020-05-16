#include<iostream>
#include<map>
#include<list>
#include<string>
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


};

int main(){
    Graph<string> g;
    g.add_edge("Putin","Trump",false);
    g.add_edge("Putin","Modi",false);
    g.add_edge("Putin","Pope",false);
    g.add_edge("Modi","Trump",true);
    g.add_edge("Modi","Yogi",true);
    g.add_edge("Yogi","Prabhu",false);
    g.add_edge("Prabhu","Modi",false);

    cout<<"The generic graph is...\n";
    g.print_graph();

}
