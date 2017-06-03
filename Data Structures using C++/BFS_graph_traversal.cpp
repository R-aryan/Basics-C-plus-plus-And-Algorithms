#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<string>
using namespace std;

class Graph_traversal
{
    int v;
    list<int> *adj;

public:
    Graph_traversal(int a)
    {
        v=a;
        adj= new list<int>[v];
    }
    void add_edge(int v,int w);
    void BFS_traversal(int s);

};

void Graph_traversal::add_edge(int v,int w)
{
    adj[v].push_back(w);
    // Add w to v’s list.
    cout<<"edge successfully added between "<<v<<" "<<w<<"\n";
}

void Graph_traversal::BFS_traversal(int s)
{
    int i;
    bool *visited = new bool[v];
    for(i=0;i<v;i++)
    {
        visited[i]=false;
    }
    list<int> queu;
    // Mark the current node as visited and enqueue it
    visited[s]=true;
    queu.push_back(s);
     // 'it' will be used to get all adjacent vertices of a vertex
    list<int>::iterator it;
    cout<<"The BFS traversal of the graph is :- \n\n";

    while(!queu.empty())
    {
        s=queu.front();
        cout<<s<<" ";
        queu.pop_front();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it

        for(it= adj[s].begin();it!=adj[s].end();++it)
        {
            if(!visited[*it])
            {
                visited[*it]=true;
                queu.push_back(*it);
            }
        }

    }
}

int main()
{
    int v,ch,x,y,a,i,s;
    string choice;
    cout<<"Enter the number of vertex you want to insert/have in the graph \n";
    cin>>v;
    Graph_traversal G(v);
    do{
    cout<<"Enter 1 for adding edges and 2 for printing the BFS traversal of the graph \n";
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"Enter number of co-ordinates with max value  "<<v<<"\n";
        cin>>a;
        for(i=0;i<a;i++)
        {
            cin>>x>>y;
            if(x<v && y<v)
            G.add_edge(x,y);
        }
        break;

    case 2:
        cout<<"enter a source with value of node less than "<<v<<"\n";
        cin>>s;
        cout<<"\n\n";
        G.BFS_traversal(s);
        break;

        default :
        cout<<"Sorrry! wrong choice Try again \n\n";


    }
    cout<<"Enter 0 to exit and any other key to continue \n\n";
    cin>>choice;
    }while(choice!="0");

    return 0;

}

/*

vector <int> v[10] ;   //Vector for maintaining adjacency list explained above
    int level[10]; //To determine the level of each node
    bool vis[10]; //Mark the node if visited
    void bfs(int s) {
        queue <int> q;
        q.push(s);
        level[ s ] = 0 ;  //Setting the level of the source node as 0
        vis[ s ] = true;
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            for(int i = 0;i < v[ p ].size() ; i++)
            {
                if(vis[ v[ p ][ i ] ] == false)
                {
            //Setting the level of each node with an increment in the level of parent node
                    level[ v[ p ][ i ] ] = level[ p ]+1;
                     q.push(v[ p ][ i ]);
                     vis[ v[ p ][ i ] ] = true;
      }
            }
        }
    }

    */
