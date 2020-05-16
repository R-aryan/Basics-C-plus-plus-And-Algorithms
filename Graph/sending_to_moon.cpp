#include<iostream>
#include<list>
#include<set>
#include<vector>

using namespace std;

class Graph{
public:

    int v;
    list<int> *l;

    Graph(int ve){
        v=ve;
        l= new list<int>[v];
    }

    void add_edge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);

    }
    void dfs_helper(int i,bool vis[], int &cs){
        vis[i]=true;
        cs+=1;
        for(auto n:l[i]){
            if(!vis[n]){
                dfs_helper(n,vis,cs);
            }
        }
    }

    int dfs_moon(){
        bool *vis= new bool[v];
        int i;
        for(i=0;i<v;i++)
            vis[i]= false;

        int n=v;
        int tw= n*(n-1)/2;

        for(i=0;i<v;i++){
            if(!vis[i]){
                int cs=0;
                dfs_helper(i,vis,cs);
                tw-=cs*(cs-1)/2;
            }
        }
    return tw;
    }
};

int main(){
    Graph g(5);
    g.add_edge(0,1);
    g.add_edge(2,3);
    g.add_edge(0,4);

    cout<<"The number of ways are.... "<<g.dfs_moon();



}
