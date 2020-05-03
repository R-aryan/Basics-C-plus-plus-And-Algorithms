#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

void shuffle(int *a,int s ,int e){
    srand(time(NULL));
    int i,j,temp;
    for(i=e;i>0;i--){
            j=rand()%(i+1);
            swap(a[i],a[j]);

        }

}

int part(int *a,int s, int e){
    int i,j,pivot ;
    i=s-1;
    pivot=a[e];
    for(j=s;j<e;j++){
        if(a[j]<pivot){
         i++;
         swap(a[i],a[j]);}
        }
        swap(a[i+1],a[e]);
    return i+1;
}

void quick_sort(int *a,int s,int e){
    if(s>=e)
        return;
    int p= part(a,s,e);
    quick_sort(a,s,p-1);
    quick_sort(a,p+1,e);


}

void print(int a[],int n){
    cout<<"Sorted array is..\n";
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

}
int main(){
    cout<<"Enter number of elements..\n";
    int n,i;
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" elements..\n";
    for(i=0;i<n;i++)cin>>a[i];
    shuffle(a,0,n-1);
    //print(a,n);
    quick_sort(a,0,n);
    print(a,n);

}
