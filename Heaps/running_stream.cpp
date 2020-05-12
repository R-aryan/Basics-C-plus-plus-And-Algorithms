#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>

using namespace std;

void query_print(priority_queue<int,vector<int>,greater<int> >pq)
{
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

int main(){
    int no;
    int cs=0;//to control heap size
    int k=3;
    priority_queue<int,vector<int>,greater<int> > pq;
    while(scanf("%d",&no)!=EOF){
        //cout<<no<<", ";
        if(no==-1)
            query_print(pq);

        else if(cs<k){
            pq.push(no);
            cs+=1;
        }
        else{
            if(no>pq.top()){
                pq.pop();
                pq.push(no);
            }
        }
    }


}
