#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class lagrange
{
public:
    double calculate(double x[],double y[],int n)
    {
        double xp,yp=0;
        cout<<"Enter x point value"<<endl;
        cin>>xp;
        for(int i=0; i<n; i++)
        {
            double temp=1;
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                {
                    temp*=(xp-x[j])/(x[i]-x[j]);
                }
            }
            yp+=temp*y[i];
        }
        return yp;
    }
};

int main()
{
    double x[] = {321.0,322.8,324.2,325.0};
    double y[] = {2.50651,2.50893,2.51081,2.51188};
    int n = sizeof(x)/sizeof(x[0]);
    lagrange obj;
    double yp = obj.calculate(x,y,n);
    cout<<yp<<endl;
}
