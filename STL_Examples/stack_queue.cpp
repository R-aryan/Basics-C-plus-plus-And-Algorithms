#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class Test
{
private:
    string name;

public:
    Test(string name):
        name(name){
        }

    void print()
    {
        cout<<"Name is : "<<name<<"\n";
    }

    ~Test(){
        cout<<"Object Destroyed \n";
    }
};

int main()
{
    stack<Test>t1;
    t1.push(Test("Mike"));
    t1.push(Test("Harry"));
    t1.push(Test("Sue"));

    Test T=t1.top();
    T.print();

}
