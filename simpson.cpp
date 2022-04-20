#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class simpson
{
    double y[100];
public:
    double calculate(double x[],int n)
    {
        double y1=0,y2=0;
        for(int i=0;i<=n;i++){
            y[i]=func(x[i]);
        }
        for(int i=1;i<=n-1;i++){
            if(i%2){
                y1+=y[i];
            }
            else{
                y2+=y[i];
            }
        }
        double ans = ((x[1]-x[0])/3)*(y[0]+y[n]+(4*y1)+(2*y2));
        return ans;
    }
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
    simpson obj;
    double ans = obj.calculate(x,n-1);
    cout<<ans<<endl;
}
