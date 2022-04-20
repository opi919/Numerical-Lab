#include<iostream>
#include<bits/stdc++.h>
#define EPSILON 0.01

using namespace std;
class raphson
{
public:
    raphson(double x0)
    {
        double x1,error=100;
        while(error>=EPSILON){
            x1 = x0 - (func(x0)/diff(x0));
            error = abs(((x1-x0)/x1)*100);
            x0=x1;
        }
        cout<<x1<<endl;
    }
    public:double func(double x){
        return x*x*x + 4*x*x - 1;
    }
    public:double diff(double x){
        return 3*x*x + 8*x;
    }
};

int main()
{
    double x0;
    while(cin>>x0){
        raphson obj1(x0);
    }
    return 0;
}
