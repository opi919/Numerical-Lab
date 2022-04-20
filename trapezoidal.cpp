#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class trapezoidal
{
    double y[100];
public:
    double calculate(double x[],int n)
    {
        double temp=0,ans;
        for(int i=0;i<=n;i++){
            y[i]=func(x[i]);
//            cout<<y[i]<<" ";
        }
        for(int i=1;i<=n-1;i++){
            temp+=y[i];
        }
        ans = (y[0]+y[n]+(2*temp))*((x[1]-x[0])/2);
        return ans;
    };
public:
    double func(double x)
    {
        return 1/(1+x);
    }
};

int main()
{
    double x[]= {0.0,0.5,1.0};
    int n = sizeof(x)/sizeof(x[0]);
    trapezoidal obj;
    double ans = obj.calculate(x,n-1);
    cout<<ans<<endl;
}
