#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
string a;
vector<string> v;
vector<int>s1;
void subseq(int i,string s,char x)
{
    int n=a.size();
    if(i==n)
    {if(!s.empty())
    cout<<s<<endl;
    if(count(s.begin(),s.end(),x)>0)
        v.push_back(s);
    return;}
    subseq(i+1,s,x);
    s.push_back(a[i]);
    subseq(i+1,s,x);
}

int main()
{
    int i,j,k,t,c=0,n;char x;


    cin>>a>>x;
    n=a.size();
    string s;
    subseq(0,s,x);
    //cout<<v.size()<<endl;
    for(i=0;i<v.size();i++){
        string s2=v[i];
        if(s2.find(x)!= string::npos){


        }
    }
    cout<<s1.size()<<endl;
    v.clear();
    s1.clear();

}
