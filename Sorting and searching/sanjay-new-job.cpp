#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


bool mycompare(pair<string,int> p1,pair<string,int> p2){
    if(p1.second==p2.second)
        return p1.first < p2.first;

    return p1.second > p2.second;
}
int main(){
    int n,ms,i;
    string name;
    int sal;
    cout<<"Enter minimum salary and number of records...\n";
    cin>>ms>>n;
    pair<string,int> emp[10000];
    for(i=0;i<n;i++){
        cin>>name>>sal;
        emp[i].first = name;
        emp[i].second = sal;
    }
    sort(emp,emp+n,mycompare);
    cout<<"after sorting....\n";

    for(i=0;i<n;i++){
        if(emp[i].second>=ms){
            cout<<emp[i].first<<" "<<emp[i].second<<"\n";
        }
    }


}
