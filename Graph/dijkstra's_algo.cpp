#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
#include<list>
#include<set>

using namespace std;

template<typename T>
class Graph{
public:
    unordered_map<T, list<pair<T,int>> >adj;

    Graph(){
    }

    void add_edge(T u,T v,int dist,bool bi=true){
        adj[u].push_back(make_pair(v,dist));
        if(bi)
            adj[v].push_back(make_pair(u,dist));

    }

    void print_adj(){
        for(auto u:adj){
            cout<<u.first<<" --> ";
            for(auto v:u.second){
                cout<<v.first<<" ,"<<v.second<<" --> ";
            }
            cout<<endl;
        }
    }

    void dijkstrasSSSp(T src){
        unordered_map<T,int>dist;
        for(auto j:adj){
            dist[j.first]=INT_MAX;
        }
        ///make a set to store each node with minimum distance
        ///by default sorting on set is done based on first parameter
        set<pair<int,T> >s;
        dist[src]=0;
        s.insert(make_pair(0,src));
        while(!s.empty()){
            ///find out the pair in front
            auto p=*(s.begin());
            T node=p.second;
            int nd=p.first;
            s.erase(s.begin());
            ///Iterate over the neighbours of the current node
            for(auto child_pair:adj[node]){
                if(nd+child_pair.second< dist[child_pair.first]){
                    ///set updation is not possible so remove the old pair from the set
                    ///and insert with new diatance to stimulate updation
                    T dest=child_pair.first;
                    auto f= s.find(make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    ///update the distance
                    dist[dest]=nd+child_pair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        ///printing the shortest path from source
        cout<<"Shortest path from source is....\n\n";
        for(auto d:dist){
            cout<<d.first<<" is located at  "<<d.second<<endl;
        }

    }
};

int main(){
    Graph<string>g;
    g.add_edge("Amritsar","Delhi",1);
    g.add_edge("Amritsar","Jaipur",4);
    g.add_edge("Jaipur","Delhi",2);
    g.add_edge("Jaipur","Mumbai",8);
    g.add_edge("Bhopal","Agra",2);
    g.add_edge("Mumbai","Bhopal",3);
    g.add_edge("Agra","Delhi",1);

    g.print_adj();
    cout<<"\n\n";
    g.dijkstrasSSSp("Amritsar");

}
