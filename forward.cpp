#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class newton_forward
{
private:
    double y[100][100];
    int n;
public:
    newton_forward(double x[],int length)
    {
        n=length;
        y[0][0]=1;
        y[1][0]=0;
        y[2][0]=1;
        y[3][0]=10;
    };
public:
    void calculate_diff()
    {
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n-i; j++)
            {
                y[j][i]=y[j+1][i-1]-y[j][i-1];
            }
        }
    }
public:
    void display(double x[])
    {
        for (int i = 0; i < n; i++)
        {
            cout << setw(4) << x[i]
                 << "\t";
            for (int j = 0; j < n - i; j++)
                cout << setw(4) << y[i][j]
                     << "\t";
            cout << endl;
        }
    }
    public:double u_cal(double u,int n){
        double temp = u;
        for(int i=1;i<n;i++){
            temp*=(u-i);
        }
        return temp;
    }
    public:int fact(int n){
        int temp=1;
        for(int i=2;i<=n;i++){
            temp*=i;
        }
        return temp;
    }
public:
    double formula(double x[],double pv)
    {
        double sum=y[0][0];
        double u = (pv-x[0])/(x[1]-x[0]);
        for(int i=1;i<n;i++){
            sum+=u_cal(u,i)*y[0][i]/fact(i);
        }
        return sum;
    }
};

int main()
{
    double x[]= {0,1,2,3},pv;
    int n = sizeof(x)/sizeof(x[0]);
    cout<<"Enter point value"<<endl;
    while(cin>>pv)
    {
        newton_forward obj(x,n);
        obj.calculate_diff();
//        obj.display(x);
        double ans = obj.formula(x,pv);
        cout<<ans<<endl;
    }
}
