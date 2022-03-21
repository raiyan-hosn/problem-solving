//alhamdulillah
#include<bits/stdc++.h>
using namespace std;
#define eps 1e-7
bool debug= false;
struct subject
{
    int p,m;
    double diff;
};
bool cmp(subject a, subject b){

    return a.diff<b.diff;
}
bool isPossible(vector<subject>&v,int d,double mid){
    for(int i=0;i<v.size();i++){
        v[i].diff= v[i].p- (v[i].m*mid)/100;
    }
    sort(v.begin(),v.end(),cmp);
    double sum=0;
    for(int i=d;i<v.size();i++){
        sum+=v[i].diff;
    }
    return sum>=0;
}
double binarySearch(vector<subject>&v,int d){
    double low=0,high=100;
    double mid;
    while (low<=high)
    {
        mid=(low+high)/2;
       
        if(isPossible(v,d,mid)){
            low=mid;
        }
        else
        {
            high=mid;
        }
        if(abs(low-high)<=eps){
            return mid;
        }
        
    }
    return mid;
    
}
int main(void)
{
//    freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n,d;
        scanf("%d %d",&n,&d);
        vector<subject>v(n);
        int P=0;
        int M=0;
        for(int i=0;i<n;i++){
            scanf("%d %d",&v[i].p,&v[i].m);
        }
    
        printf("Case %d: ",t);
        printf("%.10lf\n",binarySearch(v,d));
        

    }
}
