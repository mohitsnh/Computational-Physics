#include <iostream>
using namespace std;
double T(double x,double y)
{double a;
a=2*x*y+2*x-x*x-2*y*y+72;
return a;

}
double trap_rule(double l,double b,int n)
{
    double hl,hb,dx1,dx2,dx,sum;
    hl=l/n;
    hb=b/n;
    int i,j;
    sum=0;
    for(i=1;i<=n;i++)
    {for(j=1;j<=n;j++)
    {
        dx1=(T((i-1)*hl,(j-1)*hb)+T((i-1)*hl,j*hb))*hb/2;
        dx2=(T((i)*hl,(j-1)*hb)+T((i)*hl,j*hb))*hb/2;
        dx=(dx1+dx2)*hl/2;
        sum=sum+dx;
    }
    }

   /* da1=(T(0,0)+2*T(hl,0)+T(l,0))*hl/2;
    da2=(T(0,hb)+2*T(hl,hb)+T(l,hb))*hl/2;
    da3=(T(0,b)+2*T(hl,b)+T(l,b))*hl/2;
    da=(da1+2*da2+da3)*hb/2;

return da;*/
return sum;

}
double simson_rule(double l,double b)
{
    double hl,hb,da1,da2,da3,da;
    hl=l/2;
    hb=b/2;
    da1=(T(0,0)+4*T(hl,0)+T(l,0))*hl/3;
    da2=(T(0,hb)+4*T(hl,hb)+T(l,hb))*hl/3;
    da3=(T(0,b)+4*T(hl,b)+T(l,b))*hl/3;
    da=(da1+4*da2+da3)*hb/3;

return da;

}
double simson_rule_3(double l,double b){
    double hl,hb,da1,da2,da3,da4,da;
    hl=l/3;
    hb=b/3;
    da1=(T(0,0)+3*T(hl,0)+3*T(2*hl,0)+T(l,0))*3*hl/8;
    da2=(T(0,hb)+3*T(hl,hb)+3*T(2*hl,hb)+T(l,hb))*3*hl/8;
    da3=(T(0,2*hb)+3*T(hl,2*hb)+3*T(2*hl,2*hb)+T(l,2*hb))*3*hl/8;
    da4=(T(0,b)+3*T(hl,b)+3*T(2*hl,b)+T(l,b))*3*hl/8;
    da=(da1+3*da2+3*da3+da4)*3*hb/8;
    return da;


}
int main()
{
    double l,b,tavg, savg,savg2;
    l=8;
    b=6;
    int n;
   /* hl=l/2;
    hb=b/2;
cout<<T(0,0)<<endl;
cout<<T(0,hb)<<endl;
cout<<T(0,b)<<endl;
cout<<T(hl,0)<<endl;
cout<<T(hl,hb)<<endl;
cout<<T(hl,b)<<endl;
cout<<T(l,0)<<endl;
cout<<T(l,hb)<<endl;
cout<<T(l,b)<<endl;*/



    cout<<"From Trapezoidal rule with 2 segments\n";
    n=2;
    cout << trap_rule(l,b,n) << endl;
    tavg= trap_rule(l,b,n)/(l*b);
    cout<<tavg<<endl;
    cout<<"From Simson rule\n";
    cout << simson_rule(l,b) << endl;
    savg= simson_rule(l,b)/(l*b);
    cout<<savg<<endl;

    cout<<"From Trapezoidal rule with 3 segments\n";
    n=3;
    cout << trap_rule(l,b,n) << endl;
    tavg= trap_rule(l,b,n)/(l*b);
    cout<<tavg<<endl;
        cout<<"From Simson-3/8 rule\n";
    cout << simson_rule_3(l,b) << endl;
    savg2= simson_rule_3(l,b)/(l*b);
    cout<<savg2<<endl;
    return 0;
}
