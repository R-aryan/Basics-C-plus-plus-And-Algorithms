#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main(){
    char a[1000];
    string str="";
    cout<<"Enter the string...\n";
    cin>>a;
    int i,n;
    n=strlen(a);
    int cur_len=1;
    int max_len=1;
    int visited[256];
    for(i=0;i<256;i++)
        visited[i]=-1;
    visited[a[0]]=0;
    for(i=1;i<n;i++){
        int last_occ=visited[a[i]];
        if(last_occ== -1|| i-cur_len>last_occ){
            cur_len+=1;
            max_len=max(cur_len,max_len);
            str+=a[i];
        }
        else{
            if(cur_len>max_len)
                max_len=cur_len;
            cur_len=i-last_occ;
        }
        visited[a[i]]=i;
    }
    if(cur_len>max_len)
        max_len=cur_len;
    cout<<"Length of longest substring is... "<<max_len<<" And the substring is.... "<<str<<endl;

}
