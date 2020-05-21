#include<iostream>
#include<string>
#include<list>
#include<map>
#include<queue>

using namespace std;

template<typename T>
class Graph{
public:
    map<T,list<T> >adj;
    Graph(){
    }

    void add_edge(T u,T v,bool bi=false){
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

    int bfs_traversal_shortest_path(T s,T d){
        queue<T>q;
        map<T,int>dist;
        map<T,T>parent;
        for(auto i:adj){
                dist[i.first]=INT_MAX;
            }
        q.push(s);
        dist[s]=0;
        parent[s]=s;

        while(!q.empty()){
            T node = q.front();
            //cout<<node<<" ,";
            q.pop();
            for(auto i:adj[node]){
                if(dist[i]==INT_MAX){
                    q.push(i);
                    dist[i]=dist[node]+1;
                    parent[i]=node;
                }
            }

        }
        /*for(auto i:adj){
                T node=i.first;
                cout<<"Distance of "<<node<<"  from "<<s<<" is "<<dist[node]<<endl;
            }*/
            ///printing the path
            T temp =d;
            cout<<"The shortest path is....\n";
            while(temp!=s){
                cout<<temp<<"<--";
                temp=parent[temp];
            }
            cout<<s<<endl;
            return dist[d];
    }


};


int main(){

    Graph<int>g;
    int board[50]={0};
    board[2]=13;board[5]=2;board[9]=18;board[18]=11;board[17]=-13;
    board[20]=-14;board[24]=-8;board[25]=-10;board[32]=-2;board[34]=-22;

    for(int u=0;u<=36;u++){
        for(int d=1;d<=6;d++){
                int v= u+d+board[u+d];
                g.add_edge(u,v,false);

            }
        }
       int d= g.bfs_traversal_shortest_path(0,36);
       cout<<"The shortest distance is.... "<<d<<endl;
}
