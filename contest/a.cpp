#include <bits/stdc++.h>
using namespace std;
#define eps 1e-8
#define ll long long int
ll valueOfB(ll a){
	return (a*a-1)>>1;
}
bool isValid(int a,int b,int n){
	return (a*a-b)== sqrt(a*a + b*b)&& max(a,max(b,a*a-b))<=n&& 0<min(a,min(b,(a*a-b)));
}
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--){
		ll n;
		scanf("%lld",&n);
		if(n<4){
			printf("0\n");
			continue;
		}
		ll lo=1,hi=n;
		ll prev;
		while(lo<hi){
			ll mid=(lo+hi)/2;
			ll b=valueOfB(mid);
			if(b>n){
				hi=mid-1;
			}else{
				prev=lo;
				if(prev==mid){
					lo=mid+1;
				}else{
					lo=mid;
				}
				
			}
	
		}
		// printf("prev = %d\n",prev);
		while(valueOfB(prev+1)<n)prev++;
		while(valueOfB(prev)>=n)prev--;
		// printf("updated prev %d\n",prev);
		ll res;
		if(prev%2!=0){
			res=(prev+1)/2;
		}else{
			res=prev/2;
		}
		res--;
		printf("%lld\n",res);
	
	}
}


