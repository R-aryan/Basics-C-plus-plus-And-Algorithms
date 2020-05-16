#include<iostream>
#include<list>
using namespace std;

class Graph{
    int v;
    list<int> *l;
public:
    Graph(int ve){
        v=ve;
        l=new list<int>[v];
    }

    void add_edge(int u,int v,bool bi=true){
        l[u].push_back(v);
        if(bi)
            l[v].push_back(u);

    }

    void print_graph(){
        int i,v;
        for(i=0;i<v;i++){
            cout<<i<<"-> ";
            for(v:l[i]){
                cout<<v<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(5);
    g.add_edge(0,1);
    g.add_edge(0,4);
    g.add_edge(4,3);
    g.add_edge(1,4);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(1,3);

    cout<<"The graph is...\n";
    g.print_graph();
}
