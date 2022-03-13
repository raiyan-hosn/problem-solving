//alhamdulillah
#include<bits/stdc++.h>
using namespace std;
#define eps 1e-7
int p,q,r,s,t,u;
double equationValue(double x){
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
double bisection(){
    double low=0,high=1,x;
 
    while(low+eps<high){
        x=(low+high)/2;
        if(equationValue(low)*equationValue(x)<=0){
            high=x;
        }
        else{
            low=x;
        }
    }
    return low; //returning avg(low,high) is a good practice;
}
int main(void)
{
    while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF){
        if(equationValue(0)*equationValue(1)>0){
            printf("No solution\n");
        }
        else
        {
            printf("%.4lf\n",bisection());
        }
    }
}