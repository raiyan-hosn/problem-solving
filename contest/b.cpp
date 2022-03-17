#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void makeAllCombinations(vector<ll>&arr,vector<ll>&c){
    
    int n=pow(2,(int)arr.size());
    for(int i=0;i<n;i++){
        ll sum=0;
        for(int j=0;j<arr.size();j++){
            if(i&(1<<j)){
                sum+=arr[j];
            }
        }
        c.push_back(sum);
    }
    sort(c.begin(),c.end());
}
ll findMaxSubSetSum(vector<ll>&x,vector<ll>&y,ll s){
    ll mx=LONG_LONG_MIN;
    for(int i=0;i<x.size();i++){
        if(x[i]>s)break;
        ll need= s-x[i];
        auto it=lower_bound(y.begin(),y.end(),need);
        ll sum;
        if(it==y.end()){
            sum=x[i]+*(y.end()-1);
        }else if(*it==need){
            sum=x[i]+*it;
        }else{
            if(it!=y.begin()){
                sum=x[i]+*(it-1);
            }else{
                sum=x[i];
            }
        }
        mx=max(mx,sum);
    }
    return mx;
}
int main()
{
    vector<int>  v={1,2,3,4,5};
    int n=(v.end()-(v.begin()+3));
	printf("%d\n",n);

}
