#include<iostream>
#include<bits/stdc++.h>
#include<fstream>

using namespace std;
//using std::ifstream;

class curvefitting
{
    double sumX=0,sumY=0,sumXY=0,sumXX=0;
public:
    curvefitting(double x[],double y[],int n)
    {
        for(int i=0; i<n; i++)
        {
            sumX+=x[i];
            sumXX+=x[i]*x[i];
            sumY+=y[i];
            sumXY+=x[i]*y[i];
        }
        solve(n);
    };
public:
    void solve(int n)
    {
//        cout<<sumX<<endl;
//        cout<<sumY<<endl;
//        cout<<sumXX<<endl;
//        cout<<sumXY<<endl;
        double a,b;
        a = ((sumY*sumXX)-(sumXY*sumX))/(((sumXX*n) - (sumX*sumX))*1.0);
        b = (sumXY - (a*sumX))/(sumXX*1.0);
        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl;
    }
};

int main()
{
    double x[] = {20,30,40,50,60,70};
    double y[]= {800.3,800.4,800.6,800.7,800.9,801.0};
    int n = sizeof(sizeof(x)/sizeof(x[0]));
//    cout<<n<<endl;
    curvefitting obj(x,y,n);
    return 0;
}
