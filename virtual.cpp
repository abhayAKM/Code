#include<bits/stdc++.h>
using namespace std;

class A{
public:
    virtual void print(int) = 0;
};

class B : public A{
public:
    void print(int x){
        cout << x << endl;
    }
};

int main(){
    B obj;
    obj.print(4);
}
