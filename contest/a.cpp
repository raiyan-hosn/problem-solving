#include <bits/stdc++.h>
using namespace std;
#define eps 1e-8
#define ll long long int
#define MAX 100004
bool isCubicNumber(ll n){
	if(n==0)return false;
	if(floor(pow(n,1./3)+eps)*floor(pow(n,1./3)+eps)*floor(pow(n,1./3)+eps)==n){
		return true;
	}else{
		return false;
	}
}
bool isSumOfcubic(vector<ll>&v,ll x){
	for(int i=0;i<MAX;i++){
		if(x<v[i])return false;

		ll need= x-v[i];
		// printf("need %lld\n",need);
		if(isCubicNumber(need)){
			return true;
		}
	}
	return false;
}
int main()
{
	vector<ll>v;
	for(ll i=1;i<MAX;i++){
		v.push_back(i*i*i);
	}
	int tc;
	scanf("%d",&tc);
	while(tc--){
		ll x;
		scanf("%lld",&x);
		if(isSumOfcubic(v,x)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}


