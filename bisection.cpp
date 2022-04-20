#include<iostream>
#include<bits/stdc++.h>
#define EPSILON 0.01

using namespace std;

class bisection
{
public:
    bisection(double x1, double x2)
    {
        double fa,fb,xr,fr;
        fa = func(x1);
        fb = func(x2);
        if(fa*fb>0)
        {
            cout<<"No root between x1 and x2"<<endl;
            return;
        }
        double result = calculate(x1,x2);
    cout<<result<<endl;

    }
public:
    double func(double x)
    {
        return x*x*x + 4*x*x -1;
    }
public:
    double calculate(double x1, double x2)
    {
        double xr,fa,fr,fb,prev;
        while((x2-x1)>=EPSILON)
        {
                    fa = func(x1);
                    fb = func(x2);
            xr = (x1+x2)/2;
            fr = func(xr);
//            cout<<xr<<endl;
            if(fa*fr==0) break;
            if(fa*fr<0) x2=xr;
            else x1=xr;
        }
        return xr;
    }
};

int main()
{
    double x1,x2;
    cout<< "enter the initial guess x1 and x2: ";
    cin>>x1>>x2;
    bisection obj(x1,x2);
}
