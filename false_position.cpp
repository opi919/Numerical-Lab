#include<iostream>
#include<bits/stdc++.h>

#define EPSILON 0.01

using namespace std;

class falsi
{
public:
    falsi(double a,double b)
    {
        double fa,fb;
        fa = func(a);
        fb = func(b);
//        cout<<fa<<" "<<fb<<endl;
        if(fa*fb>0)
        {
            cout<<"Invalid initial guess"<<endl;
            return;
        }
        double result = calculate(a,b);
        cout<<result<<endl;
    }
public:
    double calculate(double a,double b)
    {
        double fa,fb,xr,fr,prev=0,error=100;
        while(error>=EPSILON)
        {
            fa = func(a);
            fb= func(b);
            xr = b - ((fb*(a-b))/(fa-fb));
            error = abs(((xr-prev)/xr)*100);
            prev = xr;
            fr = func(xr);
            if(fa*fr==0) break;
            if(fa*fr<0) b = xr;
            else a = xr;
        }
        return xr;
    }
public:
    double func(double x)
    {
        return -2.4*x*x*x + 18*x*x - 21*x - 12;
    }
};

int main()
{
    double a,b;
    while(cin>>a>>b)
    {
//        cout<<a<<b<<endl;
    falsi obj(a,b);
    }
    return 0;
}
