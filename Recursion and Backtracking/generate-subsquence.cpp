#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//vector<string>v;
int c=0;
void subsequence(char *in,char *out,int i, int j){
    //base case
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;//c+=1;
        //v.push_back(out);
        return;
    }
    // include the current char
    out[j]=in[i];
    subsequence(in,out,i+1,j+1);
    //exclude the current character
    subsequence(in,out,i+1,j);
}


int main(){
    cout<<"Enter the string \n";//int c=0,i;
    char a[100];char x;
    cin>>a;
    //cout<<"enter x \n"; cin>>x;
    char out[100];
    cout<<"All the possible subsequence are...\n";
    subsequence(a,out,0,0);
    cout<<"total subsequence "<<c<<endl;
}
