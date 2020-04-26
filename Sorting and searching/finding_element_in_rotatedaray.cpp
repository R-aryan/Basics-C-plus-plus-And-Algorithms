#include<iostream>
#include<algorithm>

using namespace std;

int search_in_rotated(int a[],int s,int e,int key){
    int mid;
    if(s>e)
        return -1;
    mid=(s+e)/2;
    if(a[mid]==key)
        return mid;

    //when mid lies in the first line
    if(a[s]<=a[mid]){
        if(key>=a[s]&& key<=a[mid])
            return search_in_rotated(a,s,mid-1,key);
        else
            return search_in_rotated(a,mid+1,e,key);
        }

    //when mid lies in the second line

    if(key>=a[mid]&&key<=a[e])
        return search_in_rotated(a,mid+1,e,key);

    return search_in_rotated(a,s,mid-1,key);



}

int main(){
    int a[]={5,6,7,1,2,3,4};
    int n;
    cout<<"Enter the element you want to search...\n";
    cin>>n;
    int s= search_in_rotated(a,0,6,n);
    if(s!=-1)
        cout<<"element "<<n<<" is present at index... "<<s+1;
    else
        cout<<"sorry element not found...\n";


}
