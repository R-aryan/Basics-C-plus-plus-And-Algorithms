#include<iostream>
#include<stack>
#include<deque>

using namespace std;

int main(){
    int n,k,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
        cout<<"\n";
        cin>>k;
    deque<int> q(k);
    for(i=0;i<k;i++){
        while(!q.empty() && a[i]>a[q.back()]){
            q.pop_back();
        }
        q.push_back(i);

    }
    for(;i<n;i++){
        cout<<a[q.front()]<<" ";
        //remove the elements which are not part of the window
        while((!q.empty()&&(q.front()<=i-k))){
                q.pop_front();

        }
        //remove the elements which are not useful in the window
        while((!q.empty()&&(a[i]>=a[q.back()]))){
            q.pop_back();
        }
        //add the new elements
        q.push_back(i);
    }
    cout<<a[q.front()]<<endl;


}
