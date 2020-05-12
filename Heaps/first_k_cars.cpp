#include<iostream>
#include<vector>
#include<functional>
#include<queue>

using namespace std;

class Car{
    int ID,xc,yc;
public:
    Car(int i,int x,int y){
        ID=i;
        xc=x;
        yc=y;
    }
    int dist(){
        return xc*xc+yc*yc;
    }
    void print(){
        cout<<" ID is : "<<ID<<" ";
        cout<<"Location is : "<<xc<<" "<<yc<<endl;
    }
};

class CarCompare{
public:
    bool operator()(Car a,Car b){
        //for max heap
        return a.dist()<b.dist();
        //for min heap
        //return a.dist()>b.dist();
    }
};

int main(){
    priority_queue<Car,vector<Car>,CarCompare> pq;
    int x[10]={5,6,7,18,9,11,0,3,8,20};
    int y[10]={1,2,8,9,10,21,3,2,4,24};
    int i,p=0;
    for(i=0;i<10;i++){
        Car c(i,x[i],y[i]);
        pq.push(c);
    }
    while(!pq.empty()&& p<=4){
        Car te=pq.top();
        cout<<"Details of the car at top of the heap is...\n";
        te.print();
        pq.pop();
        p+=1;
    }

}
