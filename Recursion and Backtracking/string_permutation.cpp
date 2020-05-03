#include<iostream>
using namespace std;

void permute(char *in,int i){
    //base case
    if(in[i]=='\0'){
        cout<<in<<" , ";
        return;
    }
    //recursive case
    for(int j=i;in[j]!='\0';j++){
        swap(in[i],in[j]);
        permute(in,i+1);
        // backtracking step - restoring the original state
        swap(in[i],in[j]);
    }
}

int main(){
    cout<<"Enter the string \n";
    char a[100];
    cin>>a;
    //char out[100];
    cout<<"All the possible permutations are...\n";
    permute(a,0);
}
