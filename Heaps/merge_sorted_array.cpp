#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

typedef pair<int,pair<int,int> >ppi;

vector<int> merge_array(vector<vector<int> > arr){
    priority_queue<ppi,vector<ppi>,greater<ppi> >pq;
    int i,j;
    vector<int>output;
    for(i=0;i<arr.size();i++){
        pq.push({arr[i][0],{i,0}});
    }
    while(!pq.empty()){
        ppi cur=pq.top();
        pq.pop();
        i=cur.second.first;
        j=cur.second.second;

        output.push_back(cur.first);

        if(j+1<arr[i].size())
        pq.push({arr[i][j+1],{i,j+1}});
    }
    return output;

}

int main(){
    vector<vector<int> > arr{ { 2, 6, 12 },
                              { 1, 9 },
                              { 23, 34, 90, 2000 } };

    vector<int>output=merge_array(arr);
    cout<<"The merged array is...\n";
    for(auto x:output){
        cout<<x<<" ";
    }

}
